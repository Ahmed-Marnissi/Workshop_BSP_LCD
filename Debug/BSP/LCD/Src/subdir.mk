################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/LCD/Src/lcd.c 

OBJS += \
./BSP/LCD/Src/lcd.o 

C_DEPS += \
./BSP/LCD/Src/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/LCD/Src/%.o BSP/LCD/Src/%.su: ../BSP/LCD/Src/%.c BSP/LCD/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/21624/Desktop/Workspace/Workshop_BSP/BSP/LCD/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-LCD-2f-Src

clean-BSP-2f-LCD-2f-Src:
	-$(RM) ./BSP/LCD/Src/lcd.d ./BSP/LCD/Src/lcd.o ./BSP/LCD/Src/lcd.su

.PHONY: clean-BSP-2f-LCD-2f-Src

