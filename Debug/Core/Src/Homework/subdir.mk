################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Homework/Systick.c \
../Core/Src/Homework/bigToLittleEndian.c \
../Core/Src/Homework/hw5.c \
../Core/Src/Homework/printf.c 

OBJS += \
./Core/Src/Homework/Systick.o \
./Core/Src/Homework/bigToLittleEndian.o \
./Core/Src/Homework/hw5.o \
./Core/Src/Homework/printf.o 

C_DEPS += \
./Core/Src/Homework/Systick.d \
./Core/Src/Homework/bigToLittleEndian.d \
./Core/Src/Homework/hw5.d \
./Core/Src/Homework/printf.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Homework/%.o Core/Src/Homework/%.su Core/Src/Homework/%.cyclo: ../Core/Src/Homework/%.c Core/Src/Homework/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I/Users/ivanl/SWEN340/Core/Inc/Activities -I/Users/ivanl/SWEN340/Core/Inc/Demos -I/Users/ivanl/SWEN340/Core/Inc/Devices -I/Users/ivanl/SWEN340/Core/Inc/Homework -I/Users/ivanl/SWEN340/Core/Inc/Project -I/Users/ivanl/SWEN340/Core/Inc/System -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Homework

clean-Core-2f-Src-2f-Homework:
	-$(RM) ./Core/Src/Homework/Systick.cyclo ./Core/Src/Homework/Systick.d ./Core/Src/Homework/Systick.o ./Core/Src/Homework/Systick.su ./Core/Src/Homework/bigToLittleEndian.cyclo ./Core/Src/Homework/bigToLittleEndian.d ./Core/Src/Homework/bigToLittleEndian.o ./Core/Src/Homework/bigToLittleEndian.su ./Core/Src/Homework/hw5.cyclo ./Core/Src/Homework/hw5.d ./Core/Src/Homework/hw5.o ./Core/Src/Homework/hw5.su ./Core/Src/Homework/printf.cyclo ./Core/Src/Homework/printf.d ./Core/Src/Homework/printf.o ./Core/Src/Homework/printf.su

.PHONY: clean-Core-2f-Src-2f-Homework

