/*******************************************************************************
* File Name: cycfg_peripherals.h
*
* Description:
* Peripheral Hardware Block configuration
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_scb_uart.h"
#include "cy_sysclk.h"
#if defined (CY_USING_HAL)
    #include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)
#include "cy_usbfs_dev_drv.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define DebugInterface_ENABLED 1U
#define DebugInterface_HW SCB5
#define DebugInterface_IRQ scb_5_interrupt_IRQn
#define USBHID_ENABLED 1U
#define USBHID_ACTIVE_ENDPOINTS_MASK 1U
#define USBHID_ENDPOINTS_BUFFER_SIZE 512U
#define USBHID_ENDPOINTS_ACCESS_TYPE 0U
#define USBHID_HW USBFS0
#define USBHID_HI_IRQ usb_interrupt_hi_IRQn
#define USBHID_MED_IRQ usb_interrupt_med_IRQn
#define USBHID_LO_IRQ usb_interrupt_lo_IRQn

extern const cy_stc_scb_uart_config_t DebugInterface_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t DebugInterface_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_usbfs_dev_drv_config_t USBHID_config;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t USBHID_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PERIPHERALS_H */
