################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/MCAL/USART/subdir.mk
-include Src/MCAL/SYSTICK/subdir.mk
-include Src/MCAL/SYSTEM_CTRL/subdir.mk
-include Src/MCAL/SPI/subdir.mk
-include Src/MCAL/RCC/subdir.mk
-include Src/MCAL/NVIC/subdir.mk
-include Src/MCAL/GPIO/subdir.mk
-include Src/MCAL/FLASH/subdir.mk
-include Src/MCAL/EXTI/subdir.mk
-include Src/MCAL/DMA/subdir.mk
-include Src/MCAL/CRC/subdir.mk
-include Src/ECUAL/TFT/subdir.mk
-include Src/ECUAL/SEGMENT/subdir.mk
-include Src/ECUAL/MOTOR/subdir.mk
-include Src/ECUAL/LED/subdir.mk
-include Src/ECUAL/LCD/subdir.mk
-include Src/ECUAL/KEYPAD/subdir.mk
-include Src/ECUAL/BUZZER/subdir.mk
-include Src/ECUAL/BUTTON/subdir.mk
-include Src/BOOTLOADER/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32f401_ITI_Training.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32f401_ITI_Training.list \

OBJCOPY_HEX += \
STM32f401_ITI_Training.hex \

OBJCOPY_BIN += \
STM32f401_ITI_Training.bin \


# All Target
all:
	+@make --no-print-directory main-build && make --no-print-directory post-build

# Main-build Target
main-build: STM32f401_ITI_Training.elf secondary-outputs

# Tool invocations
STM32f401_ITI_Training.elf: $(OBJS) $(USER_OBJS) D:\My_Codes\Arm_Part\STM32f401_ITI_Training\STM32F401CCUX_FLASH.ld
	arm-none-eabi-gcc -o "STM32f401_ITI_Training.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\My_Codes\Arm_Part\STM32f401_ITI_Training\STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32f401_ITI_Training.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32f401_ITI_Training.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32f401_ITI_Training.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32f401_ITI_Training.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM32f401_ITI_Training.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32f401_ITI_Training.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32f401_ITI_Training.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O ihex "STM32f401_ITI_Training.elf" "STM32f401_ITI_Training.hex"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
