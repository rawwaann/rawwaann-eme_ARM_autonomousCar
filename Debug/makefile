################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./APP/tasks.obj" \
"./HAL/LCD/LCD_program.obj" \
"./HAL/LDR.obj" \
"./HAL/hal.obj" \
"./HAL/motor.obj" \
"./HAL/temp_sensor.obj" \
"./HAL/ultrasonic.obj" \
"./MCAL/ADC.obj" \
"./MCAL/DIO.obj" \
"./MCAL/GPTM.obj" \
"./MCAL/PWM.obj" \
"./MCAL/systick.obj" \
"./MCAL/GPIO/GPIO_program.obj" \
"./OS/os.obj" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include APP/subdir_vars.mk
-include HAL/LCD/subdir_vars.mk
-include HAL/subdir_vars.mk
-include MCAL/subdir_vars.mk
-include MCAL/GPIO/subdir_vars.mk
-include OS/subdir_vars.mk
-include subdir_rules.mk
-include APP/subdir_rules.mk
-include HAL/LCD/subdir_rules.mk
-include HAL/subdir_rules.mk
-include MCAL/subdir_rules.mk
-include MCAL/GPIO/subdir_rules.mk
-include OS/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
misraChecking.out \

EXE_OUTPUTS__QUOTED += \
"misraChecking.out" \


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "misraChecking.out"

# Tool invocations
misraChecking.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv4 --code_state=32 -g --diag_warning=225 --diag_wrap=off --display_error_number --check_misra="required,-2.2,-10,-16.9,-19.8,-19.9,-19.10,-19.11,-20.1,-20.2,-20.4,-20.5,-20.6,-20.7,-20.8,-20.9,-20.10,-20.11,-20.12" -z -m"misraChecking.map" -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="misraChecking_linkInfo.xml" --rom_model -o "misraChecking.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "APP\tasks.obj" "HAL\LCD\LCD_program.obj" "HAL\LDR.obj" "HAL\hal.obj" "HAL\motor.obj" "HAL\temp_sensor.obj" "HAL\ultrasonic.obj" "MCAL\ADC.obj" "MCAL\DIO.obj" "MCAL\GPTM.obj" "MCAL\PWM.obj" "MCAL\systick.obj" "MCAL\GPIO\GPIO_program.obj" "OS\os.obj" 
	-$(RM) "main.d" "APP\tasks.d" "HAL\LCD\LCD_program.d" "HAL\LDR.d" "HAL\hal.d" "HAL\motor.d" "HAL\temp_sensor.d" "HAL\ultrasonic.d" "MCAL\ADC.d" "MCAL\DIO.d" "MCAL\GPTM.d" "MCAL\PWM.d" "MCAL\systick.d" "MCAL\GPIO\GPIO_program.d" "OS\os.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

