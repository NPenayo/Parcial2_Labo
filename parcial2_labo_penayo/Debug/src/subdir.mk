################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Arrays.c \
../src/Book.c \
../src/Controller.c \
../src/Editorial.c \
../src/LinkedList.c \
../src/Parser.c \
../src/Validations.c \
../src/main.c 

OBJS += \
./src/Arrays.o \
./src/Book.o \
./src/Controller.o \
./src/Editorial.o \
./src/LinkedList.o \
./src/Parser.o \
./src/Validations.o \
./src/main.o 

C_DEPS += \
./src/Arrays.d \
./src/Book.d \
./src/Controller.d \
./src/Editorial.d \
./src/LinkedList.d \
./src/Parser.d \
./src/Validations.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


