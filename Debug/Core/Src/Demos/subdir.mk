################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Demos/adc_dac_demo.c \
../Core/Src/Demos/demo.c 

OBJS += \
./Core/Src/Demos/adc_dac_demo.o \
./Core/Src/Demos/demo.o 

C_DEPS += \
./Core/Src/Demos/adc_dac_demo.d \
./Core/Src/Demos/demo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Demos/%.o Core/Src/Demos/%.su Core/Src/Demos/%.cyclo: ../Core/Src/Demos/%.c Core/Src/Demos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I/Users/ivanl/SWEN340/Core/Inc/Activities -I/Users/ivanl/SWEN340/Core/Inc/Demos -I/Users/ivanl/SWEN340/Core/Inc/Devices -I/Users/ivanl/SWEN340/Core/Inc/Homework -I/Users/ivanl/SWEN340/Core/Inc/Project -I/Users/ivanl/SWEN340/Core/Inc/System -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Demos

clean-Core-2f-Src-2f-Demos:
	-$(RM) ./Core/Src/Demos/adc_dac_demo.cyclo ./Core/Src/Demos/adc_dac_demo.d ./Core/Src/Demos/adc_dac_demo.o ./Core/Src/Demos/adc_dac_demo.su ./Core/Src/Demos/demo.cyclo ./Core/Src/Demos/demo.d ./Core/Src/Demos/demo.o ./Core/Src/Demos/demo.su

.PHONY: clean-Core-2f-Src-2f-Demos

