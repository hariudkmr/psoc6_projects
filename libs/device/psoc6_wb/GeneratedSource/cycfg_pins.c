/*******************************************************************************
* File Name: cycfg_pins.c
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

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t USER_config = 
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = USER_HSIOM,
    .intEdge = CY_GPIO_INTR_FALLING,
    .intMask = 1UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t USER_obj = 
    {
        .type = CYHAL_RSC_GPIO,
        .block_num = USER_PORT_NUM,
        .channel_num = USER_PIN,
    };
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t LED9_config = 
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = LED9_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t LED9_obj = 
    {
        .type = CYHAL_RSC_GPIO,
        .block_num = LED9_PORT_NUM,
        .channel_num = LED9_PIN,
    };
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t LED8_config = 
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = LED8_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t LED8_obj = 
    {
        .type = CYHAL_RSC_GPIO,
        .block_num = LED8_PORT_NUM,
        .channel_num = LED8_PIN,
    };
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_0_config = 
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_5_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t ioss_0_port_5_pin_0_obj = 
    {
        .type = CYHAL_RSC_GPIO,
        .block_num = ioss_0_port_5_pin_0_PORT_NUM,
        .channel_num = ioss_0_port_5_pin_0_PIN,
    };
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_1_config = 
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_5_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t ioss_0_port_5_pin_1_obj = 
    {
        .type = CYHAL_RSC_GPIO,
        .block_num = ioss_0_port_5_pin_1_PORT_NUM,
        .channel_num = ioss_0_port_5_pin_1_PIN,
    };
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_6_config = 
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLUP,
    .hsiom = ioss_0_port_6_pin_6_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t ioss_0_port_6_pin_6_obj = 
    {
        .type = CYHAL_RSC_GPIO,
        .block_num = ioss_0_port_6_pin_6_PORT_NUM,
        .channel_num = ioss_0_port_6_pin_6_PIN,
    };
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_7_config = 
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLDOWN,
    .hsiom = ioss_0_port_6_pin_7_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t ioss_0_port_6_pin_7_obj = 
    {
        .type = CYHAL_RSC_GPIO,
        .block_num = ioss_0_port_6_pin_7_PORT_NUM,
        .channel_num = ioss_0_port_6_pin_7_PIN,
    };
#endif //defined (CY_USING_HAL)


void init_cycfg_pins(void)
{
    Cy_GPIO_Pin_Init(USER_PORT, USER_PIN, &USER_config);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&USER_obj);
#endif //defined (CY_USING_HAL)

    Cy_GPIO_Pin_Init(LED9_PORT, LED9_PIN, &LED9_config);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&LED9_obj);
#endif //defined (CY_USING_HAL)

    Cy_GPIO_Pin_Init(LED8_PORT, LED8_PIN, &LED8_config);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&LED8_obj);
#endif //defined (CY_USING_HAL)

    Cy_GPIO_Pin_Init(ioss_0_port_5_pin_0_PORT, ioss_0_port_5_pin_0_PIN, &ioss_0_port_5_pin_0_config);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&ioss_0_port_5_pin_0_obj);
#endif //defined (CY_USING_HAL)

    Cy_GPIO_Pin_Init(ioss_0_port_5_pin_1_PORT, ioss_0_port_5_pin_1_PIN, &ioss_0_port_5_pin_1_config);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&ioss_0_port_5_pin_1_obj);
#endif //defined (CY_USING_HAL)

    Cy_GPIO_Pin_Init(ioss_0_port_6_pin_6_PORT, ioss_0_port_6_pin_6_PIN, &ioss_0_port_6_pin_6_config);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&ioss_0_port_6_pin_6_obj);
#endif //defined (CY_USING_HAL)

    Cy_GPIO_Pin_Init(ioss_0_port_6_pin_7_PORT, ioss_0_port_6_pin_7_PIN, &ioss_0_port_6_pin_7_config);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&ioss_0_port_6_pin_7_obj);
#endif //defined (CY_USING_HAL)
}
