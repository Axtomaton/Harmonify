################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/System/SysClock.c \
../Core/Src/System/error_handler.c \
../Core/Src/System/syscalls.c \
../Core/Src/System/sysmem.c \
../Core/Src/System/system_stm32l4xx.c \
../Core/Src/System/systick.c 

OBJS += \
./Core/Src/System/SysClock.o \
./Core/Src/System/error_handler.o \
./Core/Src/System/syscalls.o \
./Core/Src/System/sysmem.o \
./Core/Src/System/system_stm32l4xx.o \
./Core/Src/System/systick.o 

C_DEPS += \
./Core/Src/System/SysClock.d \
./Core/Src/System/error_handler.d \
./Core/Src/System/syscalls.d \
./Core/Src/System/sysmem.d \
./Core/Src/System/system_stm32l4xx.d \
./Core/Src/System/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/System/%.o Core/Src/System/%.su Core/Src/System/%.cyclo: ../Core/Src/System/%.c Core/Src/System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I/Users/ivanl/SWEN340/Core/Inc/Activities -I/Users/ivanl/SWEN340/Core/Inc/Demos -I/Users/ivanl/SWEN340/Core/Inc/Devices -I/Users/ivanl/SWEN340/Core/Inc/Homework -I/Users/ivanl/SWEN340/Core/Inc/Project -I/Users/ivanl/SWEN340/Core/Inc/System -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-System

clean-Core-2f-Src-2f-System:
	-$(RM) ./Core/Src/System/SysClock.cyclo ./Core/Src/System/SysClock.d ./Core/Src/System/SysClock.o ./Core/Src/System/SysClock.su ./Core/Src/System/error_handler.cyclo ./Core/Src/System/error_handler.d ./Core/Src/System/error_handler.o ./Core/Src/System/error_handler.su ./Core/Src/System/syscalls.cyclo ./Core/Src/System/syscalls.d ./Core/Src/System/syscalls.o ./Core/Src/System/syscalls.su ./Core/Src/System/sysmem.cyclo ./Core/Src/System/sysmem.d ./Core/Src/System/sysmem.o ./Core/Src/System/sysmem.su ./Core/Src/System/system_stm32l4xx.cyclo ./Core/Src/System/system_stm32l4xx.d ./Core/Src/System/system_stm32l4xx.o ./Core/Src/System/system_stm32l4xx.su ./Core/Src/System/systick.cyclo ./Core/Src/System/systick.d ./Core/Src/System/systick.o ./Core/Src/System/systick.su

.PHONY: clean-Core-2f-Src-2f-System

