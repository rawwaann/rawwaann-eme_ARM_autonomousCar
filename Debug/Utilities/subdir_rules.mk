################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Utilities/%.obj: ../Utilities/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv4 --code_state=32 --include_path="E:/EME-projects/misraChecking" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --check_misra="required" --preproc_with_compile --preproc_dependency="Utilities/$(basename $(<F)).d_raw" --obj_directory="Utilities" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


