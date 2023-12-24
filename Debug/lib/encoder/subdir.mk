################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/encoder/encoder.c 

OBJS += \
./lib/encoder/encoder.o 

C_DEPS += \
./lib/encoder/encoder.d 


# Each subdirectory must supply rules for building sources it contributes
lib/encoder/%.o lib/encoder/%.su lib/encoder/%.cyclo: ../lib/encoder/%.c lib/encoder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-encoder

clean-lib-2f-encoder:
	-$(RM) ./lib/encoder/encoder.cyclo ./lib/encoder/encoder.d ./lib/encoder/encoder.o ./lib/encoder/encoder.su

.PHONY: clean-lib-2f-encoder

