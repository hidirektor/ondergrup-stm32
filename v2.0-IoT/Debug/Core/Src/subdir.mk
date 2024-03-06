################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/EEPROMProcess.c \
../Core/Src/ESP8266.c \
../Core/Src/ErrorProcess.c \
../Core/Src/GlobalVariables.c \
../Core/Src/HardwareTest.c \
../Core/Src/IoTMenu.c \
../Core/Src/Menu.c \
../Core/Src/Process.c \
../Core/Src/SystemDefaults.c \
../Core/Src/TextVariables.c \
../Core/Src/Translation.c \
../Core/Src/WifiProcess.c \
../Core/Src/i2c-lcd.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/EEPROMProcess.o \
./Core/Src/ESP8266.o \
./Core/Src/ErrorProcess.o \
./Core/Src/GlobalVariables.o \
./Core/Src/HardwareTest.o \
./Core/Src/IoTMenu.o \
./Core/Src/Menu.o \
./Core/Src/Process.o \
./Core/Src/SystemDefaults.o \
./Core/Src/TextVariables.o \
./Core/Src/Translation.o \
./Core/Src/WifiProcess.o \
./Core/Src/i2c-lcd.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/EEPROMProcess.d \
./Core/Src/ESP8266.d \
./Core/Src/ErrorProcess.d \
./Core/Src/GlobalVariables.d \
./Core/Src/HardwareTest.d \
./Core/Src/IoTMenu.d \
./Core/Src/Menu.d \
./Core/Src/Process.d \
./Core/Src/SystemDefaults.d \
./Core/Src/TextVariables.d \
./Core/Src/Translation.d \
./Core/Src/WifiProcess.d \
./Core/Src/i2c-lcd.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/EEPROMProcess.cyclo ./Core/Src/EEPROMProcess.d ./Core/Src/EEPROMProcess.o ./Core/Src/EEPROMProcess.su ./Core/Src/ESP8266.cyclo ./Core/Src/ESP8266.d ./Core/Src/ESP8266.o ./Core/Src/ESP8266.su ./Core/Src/ErrorProcess.cyclo ./Core/Src/ErrorProcess.d ./Core/Src/ErrorProcess.o ./Core/Src/ErrorProcess.su ./Core/Src/GlobalVariables.cyclo ./Core/Src/GlobalVariables.d ./Core/Src/GlobalVariables.o ./Core/Src/GlobalVariables.su ./Core/Src/HardwareTest.cyclo ./Core/Src/HardwareTest.d ./Core/Src/HardwareTest.o ./Core/Src/HardwareTest.su ./Core/Src/IoTMenu.cyclo ./Core/Src/IoTMenu.d ./Core/Src/IoTMenu.o ./Core/Src/IoTMenu.su ./Core/Src/Menu.cyclo ./Core/Src/Menu.d ./Core/Src/Menu.o ./Core/Src/Menu.su ./Core/Src/Process.cyclo ./Core/Src/Process.d ./Core/Src/Process.o ./Core/Src/Process.su ./Core/Src/SystemDefaults.cyclo ./Core/Src/SystemDefaults.d ./Core/Src/SystemDefaults.o ./Core/Src/SystemDefaults.su ./Core/Src/TextVariables.cyclo ./Core/Src/TextVariables.d ./Core/Src/TextVariables.o ./Core/Src/TextVariables.su ./Core/Src/Translation.cyclo ./Core/Src/Translation.d ./Core/Src/Translation.o ./Core/Src/Translation.su ./Core/Src/WifiProcess.cyclo ./Core/Src/WifiProcess.d ./Core/Src/WifiProcess.o ./Core/Src/WifiProcess.su ./Core/Src/i2c-lcd.cyclo ./Core/Src/i2c-lcd.d ./Core/Src/i2c-lcd.o ./Core/Src/i2c-lcd.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

