################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/GPIO/GPIO_program.c 

OBJS += \
./Src/MCAL/GPIO/GPIO_program.o 

C_DEPS += \
./Src/MCAL/GPIO/GPIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/GPIO/GPIO_program.o: ../Src/MCAL/GPIO/GPIO_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"D:/My_Codes/Arm_Part/STM32f401_ITI_Training/Inc/MCAL/GPIO" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/MCAL/GPIO/GPIO_program.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

