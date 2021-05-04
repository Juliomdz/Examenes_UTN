################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/arr.c \
../src/cliente.c \
../src/compra.c \
../src/informes.c \
../src/main.c \
../src/utn.c 

OBJS += \
./src/arr.o \
./src/cliente.o \
./src/compra.o \
./src/informes.o \
./src/main.o \
./src/utn.o 

C_DEPS += \
./src/arr.d \
./src/cliente.d \
./src/compra.d \
./src/informes.d \
./src/main.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


