/*******************************************************************************
* File Name: cycfg_pins.h
*
* Description:
* Pin configuration
* This file was automatically generated and should not be modified.
* Tools Package 2.4.0.5972
* mtb-pdl-cat1 2.4.1.17937
* personalities 6.0.0.0
* udd 3.0.0.2024
*
********************************************************************************
* Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#if defined (CY_USING_HAL)
    #include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)
#include "cycfg_routing.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define USER_ENABLED 1U
#define USER_PORT GPIO_PRT0
#define USER_PORT_NUM 0U
#define USER_PIN 4U
#define USER_NUM 4U
#define USER_DRIVEMODE CY_GPIO_DM_HIGHZ
#define USER_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_4_HSIOM
    #define ioss_0_port_0_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define USER_HSIOM ioss_0_port_0_pin_4_HSIOM
#define USER_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
    #define USER_HAL_PORT_PIN P0_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define USER P0_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define USER_HAL_IRQ CYHAL_GPIO_IRQ_FALL
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define USER_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define USER_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define LED9_ENABLED 1U
#define LED9_PORT GPIO_PRT13
#define LED9_PORT_NUM 13U
#define LED9_PIN 7U
#define LED9_NUM 7U
#define LED9_DRIVEMODE CY_GPIO_DM_STRONG
#define LED9_INIT_DRIVESTATE 0
#ifndef ioss_0_port_13_pin_7_HSIOM
    #define ioss_0_port_13_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define LED9_HSIOM ioss_0_port_13_pin_7_HSIOM
#define LED9_IRQ ioss_interrupts_gpio_13_IRQn
#if defined (CY_USING_HAL)
    #define LED9_HAL_PORT_PIN P13_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9 P13_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ioss_0_port_14_pin_0_ENABLED 1U
#define ioss_0_port_14_pin_0_PORT GPIO_PRT14
#define ioss_0_port_14_pin_0_PORT_NUM 14U
#define ioss_0_port_14_pin_0_PIN 0U
#define ioss_0_port_14_pin_0_NUM 0U
#define ioss_0_port_14_pin_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_14_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_14_pin_0_HSIOM
    #define ioss_0_port_14_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_14_pin_0_IRQ ioss_interrupts_gpio_14_IRQn
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_0_HAL_PORT_PIN P14_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_0 P14_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define ioss_0_port_14_pin_1_ENABLED 1U
#define ioss_0_port_14_pin_1_PORT GPIO_PRT14
#define ioss_0_port_14_pin_1_PORT_NUM 14U
#define ioss_0_port_14_pin_1_PIN 1U
#define ioss_0_port_14_pin_1_NUM 1U
#define ioss_0_port_14_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_14_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_14_pin_1_HSIOM
    #define ioss_0_port_14_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_14_pin_1_IRQ ioss_interrupts_gpio_14_IRQn
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_1_HAL_PORT_PIN P14_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_1 P14_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_14_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define LED8_ENABLED 1U
#define LED8_PORT GPIO_PRT1
#define LED8_PORT_NUM 1U
#define LED8_PIN 1U
#define LED8_NUM 1U
#define LED8_DRIVEMODE CY_GPIO_DM_STRONG
#define LED8_INIT_DRIVESTATE 0
#ifndef ioss_0_port_1_pin_1_HSIOM
    #define ioss_0_port_1_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define LED8_HSIOM ioss_0_port_1_pin_1_HSIOM
#define LED8_IRQ ioss_interrupts_gpio_1_IRQn
#if defined (CY_USING_HAL)
    #define LED8_HAL_PORT_PIN P1_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED8 P1_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED8_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED8_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED8_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ioss_0_port_5_pin_0_ENABLED 1U
#define ioss_0_port_5_pin_0_PORT GPIO_PRT5
#define ioss_0_port_5_pin_0_PORT_NUM 5U
#define ioss_0_port_5_pin_0_PIN 0U
#define ioss_0_port_5_pin_0_NUM 0U
#define ioss_0_port_5_pin_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_5_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
    #define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_0_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_0_HAL_PORT_PIN P5_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_0 P5_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ioss_0_port_5_pin_1_ENABLED 1U
#define ioss_0_port_5_pin_1_PORT GPIO_PRT5
#define ioss_0_port_5_pin_1_PORT_NUM 5U
#define ioss_0_port_5_pin_1_PIN 1U
#define ioss_0_port_5_pin_1_NUM 1U
#define ioss_0_port_5_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_5_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
    #define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_1_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_1_HAL_PORT_PIN P5_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_1 P5_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define ioss_0_port_5_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)

extern const cy_stc_gpio_pin_config_t USER_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t USER_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t LED9_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t LED9_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_14_pin_0_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t ioss_0_port_14_pin_0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_14_pin_1_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t ioss_0_port_14_pin_1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t LED8_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t LED8_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_0_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t ioss_0_port_5_pin_0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_1_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t ioss_0_port_5_pin_1_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PINS_H */
