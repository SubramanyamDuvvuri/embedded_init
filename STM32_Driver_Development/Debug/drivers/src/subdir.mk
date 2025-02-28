################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/stm32_gpio_driver.c \
../drivers/src/stm32_spi_driver.c 

OBJS += \
./drivers/src/stm32_gpio_driver.o \
./drivers/src/stm32_spi_driver.o 

C_DEPS += \
./drivers/src/stm32_gpio_driver.d \
./drivers/src/stm32_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g1 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"D:/embedded/embedded_workspace/STM32_Driver_Development/drivers/inc" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/stm32_gpio_driver.cyclo ./drivers/src/stm32_gpio_driver.d ./drivers/src/stm32_gpio_driver.o ./drivers/src/stm32_gpio_driver.su ./drivers/src/stm32_spi_driver.cyclo ./drivers/src/stm32_spi_driver.d ./drivers/src/stm32_spi_driver.o ./drivers/src/stm32_spi_driver.su

.PHONY: clean-drivers-2f-src

