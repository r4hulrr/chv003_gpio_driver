################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v003_gpio_driver.c \
../User/ch32v00x_it.c \
../User/main.c \
../User/system_ch32v00x.c \
../User/testing.c 

C_DEPS += \
./User/ch32v003_gpio_driver.d \
./User/ch32v00x_it.d \
./User/main.d \
./User/system_ch32v00x.d \
./User/testing.d 

OBJS += \
./User/ch32v003_gpio_driver.o \
./User/ch32v00x_it.o \
./User/main.o \
./User/system_ch32v00x.o \
./User/testing.o 



# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HP/mounriver-studio-projects/Testing_GPIO/Debug" -I"c:/Users/HP/mounriver-studio-projects/Testing_GPIO/Core" -I"c:/Users/HP/mounriver-studio-projects/Testing_GPIO/User" -I"c:/Users/HP/mounriver-studio-projects/Testing_GPIO/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
