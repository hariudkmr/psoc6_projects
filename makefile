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

#FreeRTOS Directories
FRTOS_SRC_DIR    =./libs/freertos/Source
FRTOS_INC_DIR    =./libs/freertos/Source/include
FRTOS_MEM_DIR    =./libs/freertos/Source/portable/MemMang
FRTOS_PRT_DIR    =./libs/freertos/Source/portable/COMPONENT_CM4/TOOLCHAIN_GCC_ARM
SRC_FR_INC_DIR   =../libs/freertos/Source/include
FR_PM_DIR        =../libs/freertos/Source/portable/COMPONENT_CM4/TOOLCHAIN_GCC_ARM
FR_CFG_DIR	 =../portable/COMPONENT_CM4/TOOLCHAIN_GCC_ARM

#Segger Directories
SGR_SRC_DIR = ./libs/systemview/SEGGER
SGR_SAM_DIR = ./libs/systemview/Sample/FreeRTOSV10.4
SGR_SYS_DIR = ./libs/systemview/SEGGER/Syscalls
SGR_CFG_DIR = ./libs/systemview/Config


PSOC6_TARGET = $(BUILD_DIR)/sumobot

ASMFILE1 = $(LIB_DIR)/mtb-pdl-cat1/devices/COMPONENT_CAT1A/templates/COMPONENT_MTB/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/startup_psoc6_02_cm4.S
ASMFILE2 = $(LIB_DIR)/mtb-pdl-cat1/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_gcc.S

#FreeRTO Include Directories
FR_INC_PATH += \
	      -I$(FRTOS_INC_DIR) \
	      -I$(SRC_FR_INC_DIR) \
	      -I$(FRTOS_PRT_DIR) \
	      -I$(FR_PM_DIR) \
	      -I$(FR_CFG_DIR)

#Segger Include Directories
SGR_INC_PATH += \
		-I$(SGR_SRC_DIR) \
		-I../$(SGR_SRC_DIR) \
		-I$(SGR_SAM_DIR) \
		-I../$(SGR_SAM_DIR) \
		-I$(SGR_SYS_DIR) \
		-I$(SGR_CFG_DIR) \
		-I../$(SGR_CFG_DIR) 

PDLFILES += \
	 $(LIB_DIR)/cat1cm0p/COMPONENT_CAT1A/COMPONENT_CM0P_SLEEP/psoc6_02_cm0p_sleep.c \
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

# FreeRTOS source File
FRFILES +=\
	 $(FRTOS_PRT_DIR)/port.c \
	 $(FRTOS_MEM_DIR)/heap_3.c  \
	 $(FRTOS_SRC_DIR)/croutine.c \
 	 $(FRTOS_SRC_DIR)/event_groups.c \
  	 $(FRTOS_SRC_DIR)/list.c \
	 $(FRTOS_SRC_DIR)/queue.c \
	 $(FRTOS_SRC_DIR)/stream_buffer.c \
	 $(FRTOS_SRC_DIR)/tasks.c \
	 $(FRTOS_SRC_DIR)/timers.c

#Segger Source Files
SGRASMFILE =  $(SGR_SRC_DIR)/SEGGER_RTT_ASM_ARMv7M.S
SGRFILES += \
	   $(SGR_SAM_DIR)/SEGGER_SYSVIEW_FreeRTOS.c \
	   $(SGR_SRC_DIR)/SEGGER_RTT.c \
	   $(SGR_SRC_DIR)/SEGGER_RTT_printf.c \
 	   $(SGR_SRC_DIR)/SEGGER_SYSVIEW.c \
	   $(SGR_CFG_DIR)/SEGGER_SYSVIEW_Config_FreeRTOS.c \
	   $(SGR_SYS_DIR)/SEGGER_RTT_Syscalls_GCC.c \


# C source files
CFILES += \
	 $(SRC_DIR)/gpio.c	\
	 $(SRC_DIR)/uart.c      \
	 $(SRC_DIR)/main.c
	
# C header files
HFILES += \
	 -I$(INC_DIR) \
         -I../$(INC_DIR) \
	 -I../$(FR_CFG_DIR)


# Assembler command line arguments.
AFLAGS = -c $(TARGET_SEL) --specs=nano.specs -mfloat-abi=softfp \
	 -I$(SGR_CFG_DIR) \
	 -mthumb -ffunction-sections -fdata-sections -g

# Compiler command line arguments.
CFLAGS = \
	-O0 --specs=nano.specs -mfloat-abi=softfp $(TGTFLAGS) \
	-mthumb -ffunction-sections -fdata-sections -g \
	$(HFILES) \
	$(FR_INC_PATH) \
	$(SGR_INC_PATH) \
 	-I. \
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
	$(BUILD_DIR)/psoc6_02_cm0p_sleep.o	\
	$(BUILD_DIR)/gpio.o 	\
	$(BUILD_DIR)/uart.o 	\
	$(BUILD_DIR)/main.o \

FROBJECTS += \
	   $(BUILD_DIR)/port.o \
	   $(BUILD_DIR)/heap_3.o \
	   $(BUILD_DIR)/croutine.o \
	   $(BUILD_DIR)/event_groups.o \
	   $(BUILD_DIR)/list.o \
	   $(BUILD_DIR)/queue.o \
	   $(BUILD_DIR)/stream_buffer.o \
	   $(BUILD_DIR)/tasks.o \
	   $(BUILD_DIR)/timers.o \

#Segger Source Files
SGROBJECTS += \
	   $(BUILD_DIR)/SEGGER_RTT_ASM_ARMv7M.o \
	   $(BUILD_DIR)/SEGGER_RTT.o \
 	   $(BUILD_DIR)/SEGGER_SYSVIEW.o \
	   $(BUILD_DIR)/SEGGER_SYSVIEW_FreeRTOS.o \
	   $(BUILD_DIR)/SEGGER_SYSVIEW_Config_FreeRTOS.o \


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
	 $(AS) $(AFLAGS) $(ASMFILE1) -o $(BUILD_DIR)/startup_psoc6_02_cm4.o
	 $(AS) $(AFLAGS) $(ASMFILE2) -o $(BUILD_DIR)/cy_syslib_gcc.o
	 $(AS) $(AFLAGS) $(SGRASMFILE) -o $(BUILD_DIR)/SEGGER_RTT_ASM_ARMv7M.o
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
	 @echo "-------------------"
	 @echo "Building the FreeRTOS Source files"
	 @echo "-------------------"
	 for f in $(FRFILES); do \
	     echo "Compiling $$f"; \
	     cd $(BUILD_DIR) && $(CC) $(CFLAGS) -c ../$$f && cd ..; \
	 done
	 @echo "-------------------"
	 @echo "Building the Seggerview Source files"
	 @echo "-------------------"
	 for f in $(SGRFILES); do \
	     echo "Compiling $$f"; \
	     cd $(BUILD_DIR) && $(CC) $(CFLAGS) -c ../$$f && cd ..; \
	 done
	 @echo "----------------------"
	 @echo "Done compiling C files"
	 @echo "----------------------"

$(PSOC6_TARGET).elf : $(OBJECTS) $(FROBJECTS) $(SGROBJECTS) $(PSOC6_LD)
	@echo "--------------------"
	@echo "Linking the elf file obj" $@
	@echo "--------------------"
	$(LD) -Wl,--start-group $(TARGET_SEL) -mthumb --entry=Reset_Handler -Wl,-Map,$(PSOC6_TARGET).map -T $(PSOC6_LD) -specs=nano.specs -Wl,--gc-sections -g -ffunction-sections -finline-functions -Os -Wl,--end-group -o $(PSOC6_TARGET).elf   $(OBJECTS) $(FROBJECTS) $(SGROBJECTS)

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
	$(CFILES)	\
	-i $(LIB_DIR)

clangcheck:
	@$(CLCK) $(CFILES) $(INC_DIR)/*.h

format1:
	$(FMT1) -i $(CFILES) $(INC_DIR)/*.h
format:
	$(FMT) -i $(CFILES) $(INC_DIR)/*.h
