################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/gpio.c \
../driver/src/otg.c \
../driver/src/timer.c 

OBJS += \
./driver/src/gpio.o \
./driver/src/otg.o \
./driver/src/timer.o 

C_DEPS += \
./driver/src/gpio.d \
./driver/src/otg.d \
./driver/src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/%.o driver/src/%.su driver/src/%.cyclo: ../driver/src/%.c driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"D:/khoahocstm32/driverf401/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver-2f-src

clean-driver-2f-src:
	-$(RM) ./driver/src/gpio.cyclo ./driver/src/gpio.d ./driver/src/gpio.o ./driver/src/gpio.su ./driver/src/otg.cyclo ./driver/src/otg.d ./driver/src/otg.o ./driver/src/otg.su ./driver/src/timer.cyclo ./driver/src/timer.d ./driver/src/timer.o ./driver/src/timer.su

.PHONY: clean-driver-2f-src

