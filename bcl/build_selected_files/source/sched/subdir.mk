################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/sched/bcl_sched.cpp \
../source/sched/bcl_sched_mutex.cpp \
../source/sched/bcl_sched_scheduler_interface.cpp \
../source/sched/bcl_sched_schedulers.cpp 

OBJS += \
./source/sched/bcl_sched.o \
./source/sched/bcl_sched_mutex.o \
./source/sched/bcl_sched_scheduler_interface.o \
./source/sched/bcl_sched_schedulers.o 

CPP_DEPS += \
./source/sched/bcl_sched.d \
./source/sched/bcl_sched_mutex.d \
./source/sched/bcl_sched_scheduler_interface.d \
./source/sched/bcl_sched_schedulers.d 


# Each subdirectory must supply rules for building sources it contributes
source/sched/%.o: ../source/sched/%.cpp source/sched/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	distcc g++ -I../include -I../example -I../apps -I../extern/noarch/mysql/5.1.48/include -I../extern/noarch/mysqlpp/3.1.0/include -I../extern/noarch/bzip2/1.0.5/include -I../extern/noarch/zlib/1.2.5/include -I../extern/noarch/ati/2.5/include -O2 -Wall -c -fmessage-length=0 -Wno-deprecated -fno-pretty-templates -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


