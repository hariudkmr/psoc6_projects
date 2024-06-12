######################################################################################################
TARGET_SEL = -mcpu=cortex-m4
TGTFLAGS = $(TARGET_SEL) -mfpu=fpv4-sp-d16 
######################################################################################################

#Include Directory
SRC_DIR      =./src
INC_DIR      =./inc
LIB_DIR      =./libs
LIB_INC_DIR  =./../libs
BUILD_DIR    =./build


PSOC6_TARGET = $(BUILD_DIR)/sumobot

ASMFILE1 = $(LIB_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/startup_psoc6_02_cm4.S
ASMFILE2 = $(LIB_DIR)/mtb-pdl-cat1/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_gcc.S

PDLFILES += \
	 $(LIB_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/source/cy_device.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/system_psoc6_cm4.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_ipc_pipe.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_ipc_drv.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_ipc_sema.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_wdt.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_sysint.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_sysclk.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_gpio.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_syslib.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_scb_common.c	\
	 $(LIB_DIR)/mtb-pdl-cat1/drivers/source/cy_scb_uart.c	\

# C source files
CFILES += \
	 $(SRC_DIR)/psoc6_cm0.c	\
	 $(SRC_DIR)/main.c

# Assembler command line arguments.
AFLAGS = -c $(TARGET_SEL) --specs=nano.specs -mfloat-abi=softfp \
	 -mthumb -ffunction-sections -fdata-sections -g

# Compiler command line arguments.
CFLAGS = \
	-Os --specs=nano.specs -Og -mfloat-abi=softfp $(TGTFLAGS) \
	-mthumb -ffunction-sections -fdata-sections -g \
	-I. \
	-I$(INC_DIR) \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/cmsis/include \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/include \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/drivers/include	\
	-I$(LIB_INC_DIR)/core-lib/include \
	-I$(LIB_INC_DIR)/psoc6hal/include \
	-I$(LIB_INC_DIR)/psoc6hal/COMPONENT_PSOC6HAL/include \
	-I$(LIB_INC_DIR)/psoc6hal/COMPONENT_PSOC6HAL/include/triggers \
	-I$(LIB_INC_DIR)/psoc6hal/COMPONENT_PSOC6HAL/include/pin_packages \
	-I$(LIB_INC_DIR)/retarget-io \
	-DCY8C624ABZI_S2D44 -DCY_IPC_DEFAULT_CFG_DISABLE

PSOC6_LD = $(LIB_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/cy8c6xxa_cm4_dual.ld

OBJECTS += \
	$(BUILD_DIR)/startup_psoc6_02_cm4.o \
	$(BUILD_DIR)/cy_syslib_gcc.o \
	$(BUILD_DIR)/system_psoc6_cm4.o \
	$(BUILD_DIR)/cy_gpio.o 	\
	$(BUILD_DIR)/cy_syslib.o 	\
	$(BUILD_DIR)/cy_sysclk.o 	\
	$(BUILD_DIR)/cy_device.o 	\
	$(BUILD_DIR)/cy_scb_common.o 	\
	$(BUILD_DIR)/cy_scb_uart.o 	\
	$(BUILD_DIR)/psoc6_cm0.o 	\
	$(BUILD_DIR)/main.o

# Path to compiler/linker tools.
CC  = arm-none-eabi-gcc
AS  = arm-none-eabi-gcc
LD  = arm-none-eabi-gcc
OC  = arm-none-eabi-objcopy
FD  = openocd
CPCK = cppcheck
CLCK = clang-check
FMT = clang-format-12

DONE=@if [ -f $(1) ]; then echo Build completed.; fi
RM=rm -f $(1)

.SUFFIXES: .o .c .s
.PHONY: all clean build codecheck format

all: prep ofiles $(PSOC6_TARGET).elf $(PSOC6_TARGET).hex
	$(call DONE,$(PSOC6_TARGET).hex)

rebuild: clean all

clean:
	rm -rf build
	mkdir $(BUILD_DIR)

prep:
	@echo '#### Prepping stuff ####'
	+(rm -rf $(BUILD_DIR))
	+(mkdir $(BUILD_DIR))

ofiles : $(CFILES) $(ASMFILES)
	 @echo "---------------------"
	 @echo "Building the ASM files"
	 @echo "---------------------"
	 $(AS) $(AFLAGS) $(ASMFILE1) -o $(BUILD_DIR)/startup_psoc6_02_cm4.o
	 $(AS) $(AFLAGS) $(ASMFILE2) -o $(BUILD_DIR)/cy_syslib_gcc.o
	 @echo "-------------------"
	 @echo "Building the Source files"
	 @echo "-------------------"
	 for f in $(CFILES); do \
	     echo "Compiling $$f"; \
	     cd $(BUILD_DIR) && $(CC) $(CFLAGS) -c ../$$f && cd ..; \
	 done
	 @echo "-------------------"
	 @echo "Building the PDL files" 
	 @echo "-------------------"
	 for f in $(PDLFILES); do \
	     echo "Compiling $$f"; \
	     cd $(BUILD_DIR) && $(CC) $(CFLAGS) -c ../$$f && cd ..; \
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
	$(FD) -f interface/kitprog3.cfg -f target/$(DEVICE).cfg -c"program $(PSOC6_TARGET).hex verify reset; exit"
	
	
codecheck: 
	@$(CPCK) --quiet --enable=all --suppress=missingInclude --error-exitcode=1 \
	--inline-suppr	\
	-I $(INC_DIR)	\
	$(CFILES)	\
	-i $(LIB_DIR)

clangcheck:
	@$(CLCK) $(CFILES) $(INC_DIR)/*.h

format:
	$(FMT) -i $(CFILES) $(INC_DIR)/*.h
