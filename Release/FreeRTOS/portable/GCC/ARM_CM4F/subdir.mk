################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./FreeRTOS/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./FreeRTOS/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/ARM_CM4F/%.o: ../FreeRTOS/portable/GCC/ARM_CM4F/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F411VETx -DSTM32F411E_DISCO -DSTM32F411xE -DUSE_STDPERIPH_DRIVER -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/portable/GCC -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/include -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/portable/MemMang -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/config -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/portable/GCC/ARM_CM4F -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/StdPeriph_Driver/inc" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/inc" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/CMSIS/device" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/CMSIS/core" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


