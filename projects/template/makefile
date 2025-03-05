#Include Directory
SRC_DIR      =./src
INC_DIR      =./inc
LIB_DIR      =../../libs
LIB_INC_DIR  =../../../libs
BUILD_DIR    =./build
TOOL_DIR     =./tools
SYSCONFIG    =./config/GeneratedSource
PDLLIB       =$(LIB_DIR)/mtb-pdl-cat1
USBLIB	     =$(LIB_DIR)/usbdev



#FreeRTOS Directories
FRTOS_SRC_DIR    =$(LIB_DIR)/freertos/Source
FRTOS_INC_DIR    =$(LIB_DIR)/freertos/Source/include
FRTOS_MEM_DIR    =$(LIB_DIR)/freertos/Source/portable/MemMang
FRTOS_PRT_DIR    =$(LIB_DIR)/freertos/Source/portable/COMPONENT_CM4/TOOLCHAIN_GCC_ARM
SRC_FR_INC_DIR   =$(LIB_DIR)/freertos/Source/include
FR_PM_DIR        =$(LIB_DIR)/freertos/Source/portable/COMPONENT_CM4/TOOLCHAIN_GCC_ARM
FR_CFG_DIR	 =$(LIB_DIR)/freertos/portable/COMPONENT_CM4/TOOLCHAIN_GCC_ARM

######################################################################################################
TARGET_SEL = -mcpu=cortex-m4
TGTFLAGS = $(TARGET_SEL) -mfpu=fpv4-sp-d16 

DEVICE=psoc6_2m
STUP=startup_psoc6_02_cm4
TGT=CY8C624ABZI_S2D44 
CFLAGS += -DPSOC62=1 
CM0 = psoc6_02_cm0p_sleep
PSOC6_LD = $(LIB_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/cy8c6xxa_cm4_dual.ld
    
ifeq ($(MAKECMDGOALS), clean)
else ifeq ($(MAKECMDGOALS), format1)
else ifeq ($(MAKECMDGOALS), codecheck)
endif

######################################################################################################
PSOC6_TARGET = $(BUILD_DIR)/template

ASMFILE1 = $(LIB_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/$(STUP).S
ASMFILE2 = $(LIB_DIR)/mtb-pdl-cat1/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_gcc.S


PDLFILES += \
	 $(LIB_DIR)/cat1cm0p/COMPONENT_CAT1A/COMPONENT_CM0P_SLEEP/$(CM0).c \
	 $(PDLLIB)/devices/COMPONENT_CAT1A/source/cy_device.c	\
	 $(PDLLIB)/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/system_psoc6_cm4.c	\
	 $(PDLLIB)/drivers/source/cy_ipc_pipe.c	\
	 $(PDLLIB)/drivers/source/cy_ipc_drv.c	\
	 $(PDLLIB)/drivers/source/cy_ipc_sema.c	\
	 $(PDLLIB)/drivers/source/cy_wdt.c	\
	 $(PDLLIB)/drivers/source/cy_sysint.c	\
	 $(PDLLIB)/drivers/source/cy_sysclk.c	\
	 $(PDLLIB)/drivers/source/cy_gpio.c	\
	 $(PDLLIB)/drivers/source/cy_syslib.c	\

# System Configuration files
SYSFILES += \
	 $(SYSCONFIG)/cycfg.c \
	 $(SYSCONFIG)/cycfg_clocks.c \
	 $(SYSCONFIG)/cycfg_peripherals.c \
	 $(SYSCONFIG)/cycfg_pins.c \
 	 $(SYSCONFIG)/cycfg_system.c \

# C source files
CFILES += \
	 $(SRC_DIR)/main.c
	
# C header files
HFILES += \
	  $(FR_INC_PATH) \
	 -I$(SRC_DIR) \
	 -I../$(USBLIB) \
         -I../$(INC_DIR) \
	 -I../$(SYSCONFIG) \


# Assembler command line arguments.
AFLAGS = -c $(TARGET_SEL) --specs=nano.specs -mfloat-abi=softfp \
	 -mthumb -ffunction-sections -fdata-sections -g


# Compiler command line arguments.
CFLAGS += \
	-O0 --specs=nano.specs -mfloat-abi=softfp $(TGTFLAGS) \
	-mthumb -ffunction-sections -fdata-sections -g \
	$(HFILES) \
	$(FR_INC_PATH) \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/cmsis/include \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/include \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/include/ip \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/cmsis/source \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB \
	-I$(LIB_INC_DIR)/mtb-pdl-cat1/drivers/include	\
	-I$(LIB_INC_DIR)/core-lib/include \
	-I$(LIB_INC_DIR)/psoc6hal/include \
	-I$(LIB_INC_DIR)/psoc6hal/COMPONENT_PSOC6HAL/include \
	-I$(LIB_INC_DIR)/psoc6hal/COMPONENT_PSOC6HAL/include/triggers \
	-I$(LIB_INC_DIR)/psoc6hal/COMPONENT_PSOC6HAL/include/pin_packages \
	-I$(LIB_INC_DIR)/retarget-io \
	-D$(TGT) -DCY_IPC_DEFAULT_CFG_DISABLE


PDLOBJECTS += \
	$(BUILD_DIR)/$(STUP).o \
	$(BUILD_DIR)/cy_syslib_gcc.o \
	$(BUILD_DIR)/system_psoc6_cm4.o \
	$(BUILD_DIR)/cy_gpio.o 	\
	$(BUILD_DIR)/cy_syslib.o 	\
	$(BUILD_DIR)/cy_sysclk.o 	\
	$(BUILD_DIR)/cy_device.o 	\
	$(BUILD_DIR)/cy_sysint.o 	\
	$(BUILD_DIR)/$(CM0).o	\

SYSOBJECTS += \
	$(BUILD_DIR)/cycfg.o	\
	$(BUILD_DIR)/cycfg_clocks.o	\
	$(BUILD_DIR)/cycfg_peripherals.o	\
	$(BUILD_DIR)/cycfg_pins.o	\
	$(BUILD_DIR)/cycfg_system.o	\

SRCOBJECTS += \
	$(BUILD_DIR)/main.o \


# Path to compiler/linker tools.
CC  = arm-none-eabi-gcc
AS  = arm-none-eabi-gcc
LD  = arm-none-eabi-gcc
OC  = arm-none-eabi-objcopy
FD  = openocd
CPCK = cppcheck
CLCK = clang-check
FMT = clang-format-12
FMT1 = clang-format

DONE=@if [ -f $(1) ]; then echo Build completed.; fi
RM=rm -f $(1)

.SUFFIXES: .o .c .s
.PHONY: all clean build codecheck format

all: prep ofiles $(PSOC6_TARGET).elf $(PSOC6_TARGET).hex
	$(call DONE,$(PSOC6_TARGET).hex)

rebuild: clean all

clean:
	rm -rf build
	mkdir -p $(BUILD_DIR)

prep:
	@echo '#### Prepping stuff ####'
	+(rm -rf $(BUILD_DIR))
	+(mkdir -p $(BUILD_DIR))

ofiles : $(CFILES) $(ASMFILES)
	 @echo "---------------------"
	 @echo "Building the ASM files"
	 @echo "---------------------"
	 $(AS) $(AFLAGS) $(ASMFILE1) -o $(BUILD_DIR)/$(STUP).o
	 $(AS) $(AFLAGS) $(ASMFILE2) -o $(BUILD_DIR)/cy_syslib_gcc.o
	 @echo "-------------------"
	 @echo "Building the Source files"
	 @echo "-------------------"
	 for f in $(CFILES); do \
	     echo "Compiling $$f"; \
	     cd $(BUILD_DIR) && $(CC) $(CFLAGS) -c ../$$f && cd ..; \
	 done
	 @echo "-------------------"
	 @echo "Building the System configuration files"
	 @echo "-------------------"
	 for f in $(SYSFILES); do \
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

$(PSOC6_TARGET).elf : $(PDLOBJECTS) $(SYSOBJECTS) $(SRCOBJECTS) $(PSOC6_LD)
	@echo "--------------------"
	@echo "Linking the elf file obj" $@
	@echo "--------------------"
	$(LD) -Wl,--start-group $(TARGET_SEL) -mthumb --entry=Reset_Handler -Wl,-Map,$(PSOC6_TARGET).map -T $(PSOC6_LD) -specs=nano.specs -Wl,--gc-sections -g -ffunction-sections -finline-functions -Os -Wl,--end-group -o $(PSOC6_TARGET).elf   $(PDLOBJECTS) $(SYSOBJECTS) $(SRCOBJECTS)  

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
	$(CPCK) --quiet --enable=all --suppress=missingInclude \
	--inline-suppr	\
	-I $(INC_DIR)	\
	$(CFILES)

clangcheck:
	@$(CLCK) $(CFILES) $(INC_DIR)/*.h

format1:
	$(FMT1) -i $(CFILES) $(INC_DIR)/*.h
format:
	$(FMT) -i $(CFILES) $(INC_DIR)/*.h
