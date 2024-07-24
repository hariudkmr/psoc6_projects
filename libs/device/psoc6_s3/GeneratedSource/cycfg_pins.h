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
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#if defined(__cplusplus)
extern "C" {
#endif

#define LED9_ENABLED 1U
#define LED9_PORT GPIO_PRT11
#define LED9_PORT_NUM 11U
#define LED9_PIN 1U
#define LED9_NUM 1U
#define LED9_DRIVEMODE CY_GPIO_DM_ANALOG
#define LED9_INIT_DRIVESTATE 1
#ifndef ioss_0_port_11_pin_1_HSIOM
    #define ioss_0_port_11_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define LED9_HSIOM ioss_0_port_11_pin_1_HSIOM
#define LED9_IRQ ioss_interrupts_gpio_11_IRQn
#if defined (CY_USING_HAL)
    #define LED9_HAL_PORT_PIN P11_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9 P11_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
    #define LED9_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)

extern const cy_stc_gpio_pin_config_t LED9_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t LED9_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PINS_H */
