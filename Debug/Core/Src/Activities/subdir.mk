################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Activities/Activity_10.c \
../Core/Src/Activities/Activity_11.c \
../Core/Src/Activities/Activity_8.c \
../Core/Src/Activities/create_struct.c \
../Core/Src/Activities/hello_world.c \
../Core/Src/Activities/timer.c 

OBJS += \
./Core/Src/Activities/Activity_10.o \
./Core/Src/Activities/Activity_11.o \
./Core/Src/Activities/Activity_8.o \
./Core/Src/Activities/create_struct.o \
./Core/Src/Activities/hello_world.o \
./Core/Src/Activities/timer.o 

C_DEPS += \
./Core/Src/Activities/Activity_10.d \
./Core/Src/Activities/Activity_11.d \
./Core/Src/Activities/Activity_8.d \
./Core/Src/Activities/create_struct.d \
./Core/Src/Activities/hello_world.d \
./Core/Src/Activities/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Activities/%.o Core/Src/Activities/%.su Core/Src/Activities/%.cyclo: ../Core/Src/Activities/%.c Core/Src/Activities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I/Users/ivanl/SWEN340/Core/Inc/Activities -I/Users/ivanl/SWEN340/Core/Inc/Demos -I/Users/ivanl/SWEN340/Core/Inc/Devices -I/Users/ivanl/SWEN340/Core/Inc/Homework -I/Users/ivanl/SWEN340/Core/Inc/Project -I/Users/ivanl/SWEN340/Core/Inc/System -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Activities

clean-Core-2f-Src-2f-Activities:
	-$(RM) ./Core/Src/Activities/Activity_10.cyclo ./Core/Src/Activities/Activity_10.d ./Core/Src/Activities/Activity_10.o ./Core/Src/Activities/Activity_10.su ./Core/Src/Activities/Activity_11.cyclo ./Core/Src/Activities/Activity_11.d ./Core/Src/Activities/Activity_11.o ./Core/Src/Activities/Activity_11.su ./Core/Src/Activities/Activity_8.cyclo ./Core/Src/Activities/Activity_8.d ./Core/Src/Activities/Activity_8.o ./Core/Src/Activities/Activity_8.su ./Core/Src/Activities/create_struct.cyclo ./Core/Src/Activities/create_struct.d ./Core/Src/Activities/create_struct.o ./Core/Src/Activities/create_struct.su ./Core/Src/Activities/hello_world.cyclo ./Core/Src/Activities/hello_world.d ./Core/Src/Activities/hello_world.o ./Core/Src/Activities/hello_world.su ./Core/Src/Activities/timer.cyclo ./Core/Src/Activities/timer.d ./Core/Src/Activities/timer.o ./Core/Src/Activities/timer.su

.PHONY: clean-Core-2f-Src-2f-Activities

