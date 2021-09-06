################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Articulo.c \
../src/PosicionArancelaria.c \
../src/calculosTransporte.c \
../src/controller.c \
../src/costosTransporte.c \
../src/main.c \
../src/utn.c 

OBJS += \
./src/Articulo.o \
./src/PosicionArancelaria.o \
./src/calculosTransporte.o \
./src/controller.o \
./src/costosTransporte.o \
./src/main.o \
./src/utn.o 

C_DEPS += \
./src/Articulo.d \
./src/PosicionArancelaria.d \
./src/calculosTransporte.d \
./src/controller.d \
./src/costosTransporte.d \
./src/main.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


