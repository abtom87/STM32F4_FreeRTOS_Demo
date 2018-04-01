################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio_led.c \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f4xx.c \
../src/usart2_comm.c 

OBJS += \
./src/gpio_led.o \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f4xx.o \
./src/usart2_comm.o 

C_DEPS += \
./src/gpio_led.d \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f4xx.d \
./src/usart2_comm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F411VETx -DSTM32F411E_DISCO -DSTM32F411xE -DUSE_STDPERIPH_DRIVER -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/portable/GCC -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/include -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/portable/MemMang -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/config -I/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo1/FreeRTOS/portable/GCC/ARM_CM4F -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/StdPeriph_Driver/inc" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/inc" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/CMSIS/device" -I"/home/abel/Ac6/SystemWorkbench/FreeRTOS_Demo2/CMSIS/core" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


