################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ECUAL/BUZZER/BUZZER_programm.c 

OBJS += \
./Src/ECUAL/BUZZER/BUZZER_programm.o 

C_DEPS += \
./Src/ECUAL/BUZZER/BUZZER_programm.d 


# Each subdirectory must supply rules for building sources it contributes
Src/ECUAL/BUZZER/BUZZER_programm.o: ../Src/ECUAL/BUZZER/BUZZER_programm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -DDEBUG -c -I../Inc -I"D:/My_Codes/Arm_Part/STM32f401_ITI_Training/Inc/MCAL/GPIO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/ECUAL/BUZZER/BUZZER_programm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

