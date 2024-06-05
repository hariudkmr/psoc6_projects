######################################################################################################
TARGET_SEL = -mcpu=cortex-m4
TGTFLAGS = $(TARGET_SEL) -mfpu=fpv4-sp-d16 
######################################################################################################

PSOC6_TARGET = build/sumobot

ASMFILE1 = ../libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/startup_psoc6_02_cm4.S
ASMFILE2 = ../libs/mtb-pdl-cat1/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_gcc.S

# C source files
CFILES += \
	 ../libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/source/cy_device.c	\
	 ../libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/system_psoc6_cm4.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_ipc_pipe.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_ipc_drv.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_ipc_sema.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_wdt.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_sysint.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_sysclk.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_gpio.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_syslib.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_scb_common.c	\
	 ../libs/mtb-pdl-cat1/drivers/source/cy_scb_uart.c	\
	 ./src/psoc6_cm0.c	\
	 ./src/main.c

# Assembler command line arguments.
AFLAGS = -c $(TARGET_SEL) --specs=nano.specs -mfloat-abi=softfp \
	 -mthumb -ffunction-sections -fdata-sections -g

# Compiler command line arguments.
CFLAGS = \
	-Os --specs=nano.specs -Og -mfloat-abi=softfp $(TGTFLAGS) \
	-mthumb -ffunction-sections -fdata-sections -g \
	-I. \
	-I./include \
	-I../../libs/mtb-pdl-cat1/cmsis/include \
	-I../../libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/include \
	-I../../libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB \
	-I../../libs/mtb-pdl-cat1/drivers/include	\
	-I../../libs/core-lib/include \
	-I../../libs/psoc6hal/include \
	-I../../libs/psoc6hal/COMPONENT_PSOC6HAL/include \
	-I../../libs/psoc6hal/COMPONENT_PSOC6HAL/include/triggers \
	-I../../libs/psoc6hal/COMPONENT_PSOC6HAL/include/pin_packages \
	-I../../libs/retarget-io \
	-DCY8C624ABZI_S2D44 -DCY_IPC_DEFAULT_CFG_DISABLE

PSOC6_LD = ../libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/cy8c6xxa_cm4_dual.ld

OBJECTS += \
	build/startup_psoc6_02_cm4.o \
	build/cy_syslib_gcc.o \
	build/system_psoc6_cm4.o \
	build/cy_gpio.o 	\
	build/cy_syslib.o 	\
	build/cy_sysclk.o 	\
	build/cy_device.o 	\
	build/cy_scb_common.o 	\
	build/cy_scb_uart.o 	\
	build/psoc6_cm0.o 	\
	build/main.o

# Path to compiler/linker tools.
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
FD = openocd


DONE=@if [ -f $(1) ]; then echo Build completed.; fi
RM=rm -f $(1)

.SUFFIXES: .o .c .s
.PHONY: all clean build

all: prep ofiles $(PSOC6_TARGET).elf $(PSOC6_TARGET).hex
	$(call DONE,$(PSOC6_TARGET).hex)

rebuild: clean all

clean:
	rm -rf build
	mkdir build
prep:
	@echo '#### Prepping stuff ####'
	+(rm -rf build)
	+(mkdir build)

ofiles : $(CFILES) $(ASMFILES)
	 @echo "---------------------"
	 @echo "Building the ASM files"
	 @echo "---------------------"
	 $(AS) $(AFLAGS) $(ASMFILE1) -o build/startup_psoc6_02_cm4.o
	 $(AS) $(AFLAGS) $(ASMFILE2) -o build/cy_syslib_gcc.o
	 @echo "-------------------"
	 @echo "Building the C files"
	 @echo "-------------------"
	 for f in $(CFILES); do \
	     echo "Compiling $$f"; \
	     cd build && $(CC) $(CFLAGS) -c ../$$f && cd ..; \
	 done
	 @echo "----------------------"
	 @echo "Done compiling C files"
	 @echo "----------------------"

$(PSOC6_TARGET).elf : $(OBJECTS) $(PSOC6_LD)
	@echo "--------------------"
	@echo "Linking the elf file obj" $@
	@echo "--------------------"
	$(LD) -Wl,--start-group $(TARGET_SEL) -mthumb --entry=Reset_Handler -Wl,-Map,$(PSOC6_TARGET).map -T $(PSOC6_LD) -specs=nano.specs -Wl,--gc-sections -g -ffunction-sections -finline-functions -Os -Wl,--end-group -o $(PSOC6_TARGET).elf $(OBJECTS) 

$(PSOC6_TARGET).hex : $(PSOC6_TARGET).elf
	@echo "-------------------------"
	@echo "Building the hex file" $@
	@echo "-------------------------"
	$(OC) -O ihex $(PSOC6_TARGET).elf $(PSOC6_TARGET).hex
	@echo "-------------------------"
	@echo "Building the list file" $@
	@echo "--------------------------"
	arm-none-eabi-objdump -S $(PSOC6_TARGET).elf > $(PSOC6_TARGET).lst
	
flash:	$(PSOC6_TARGET).hex
	@echo "-------------------------"
	@echo "Flashing the hex file" $@
	@echo "-------------------------"
	$(FD) -f interface/kitprog3.cfg -f target/psoc6_512k.cfg -c"program $(PSOC6_TARGET).hex verify reset; exit"
	

