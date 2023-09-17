################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
HAL/%.obj: ../HAL/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv4 --code_state=32 --include_path="E:/EME-projects/misraChecking" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --check_misra="required,-2.2,-10,-16.9,-19.8,-19.9,-19.10,-19.11,-20.1,-20.2,-20.4,-20.5,-20.6,-20.7,-20.8,-20.9,-20.10,-20.11,-20.12" --preproc_with_compile --preproc_dependency="HAL/$(basename $(<F)).d_raw" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


