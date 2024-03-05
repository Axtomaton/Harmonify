################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Project/part1.c \
../Core/Src/Project/project.c \
../Core/Src/Project/song.c \
../Core/Src/Project/tone.c 

OBJS += \
./Core/Src/Project/part1.o \
./Core/Src/Project/project.o \
./Core/Src/Project/song.o \
./Core/Src/Project/tone.o 

C_DEPS += \
./Core/Src/Project/part1.d \
./Core/Src/Project/project.d \
./Core/Src/Project/song.d \
./Core/Src/Project/tone.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Project/%.o Core/Src/Project/%.su Core/Src/Project/%.cyclo: ../Core/Src/Project/%.c Core/Src/Project/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I/Users/ivanl/SWEN340/Core/Inc/Activities -I/Users/ivanl/SWEN340/Core/Inc/Demos -I/Users/ivanl/SWEN340/Core/Inc/Devices -I/Users/ivanl/SWEN340/Core/Inc/Homework -I/Users/ivanl/SWEN340/Core/Inc/Project -I/Users/ivanl/SWEN340/Core/Inc/System -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Project

clean-Core-2f-Src-2f-Project:
	-$(RM) ./Core/Src/Project/part1.cyclo ./Core/Src/Project/part1.d ./Core/Src/Project/part1.o ./Core/Src/Project/part1.su ./Core/Src/Project/project.cyclo ./Core/Src/Project/project.d ./Core/Src/Project/project.o ./Core/Src/Project/project.su ./Core/Src/Project/song.cyclo ./Core/Src/Project/song.d ./Core/Src/Project/song.o ./Core/Src/Project/song.su ./Core/Src/Project/tone.cyclo ./Core/Src/Project/tone.d ./Core/Src/Project/tone.o ./Core/Src/Project/tone.su

.PHONY: clean-Core-2f-Src-2f-Project

