################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../apps/internal/util/bcl_app_cpu_benchmark.cpp \
../apps/internal/util/bcl_app_generate_license_file.cpp \
../apps/internal/util/bcl_app_minimize_score_weight_set.cpp \
../apps/internal/util/bcl_app_write_app_web_text.cpp \
../apps/internal/util/bcl_app_write_bcl_object.cpp 

OBJS += \
./apps/internal/util/bcl_app_cpu_benchmark.o \
./apps/internal/util/bcl_app_generate_license_file.o \
./apps/internal/util/bcl_app_minimize_score_weight_set.o \
./apps/internal/util/bcl_app_write_app_web_text.o \
./apps/internal/util/bcl_app_write_bcl_object.o 

CPP_DEPS += \
./apps/internal/util/bcl_app_cpu_benchmark.d \
./apps/internal/util/bcl_app_generate_license_file.d \
./apps/internal/util/bcl_app_minimize_score_weight_set.d \
./apps/internal/util/bcl_app_write_app_web_text.d \
./apps/internal/util/bcl_app_write_bcl_object.d 


# Each subdirectory must supply rules for building sources it contributes
apps/internal/util/%.o: ../apps/internal/util/%.cpp apps/internal/util/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	distcc g++ -I../include -I../example -I../apps -I../extern/noarch/mysql/5.1.48/include -I../extern/noarch/mysqlpp/3.1.0/include -I../extern/noarch/bzip2/1.0.5/include -I../extern/noarch/zlib/1.2.5/include -I../extern/noarch/ati/2.5/include -O2 -Wall -c -fmessage-length=0 -Wno-deprecated -fno-pretty-templates -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


