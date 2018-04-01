################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/StdPeriph_Driver/inc" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/inc" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/CMSIS/device" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/CMSIS/core" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


