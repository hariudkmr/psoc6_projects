/*******************************************************************************
* File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

const cy_stc_scb_uart_config_t DebugInterface_config = 
{
    .uartMode = CY_SCB_UART_STANDARD,
    .enableMutliProcessorMode = false,
    .smartCardRetryOnNack = false,
    .irdaInvertRx = false,
    .irdaEnableLowPowerReceiver = false,
    .oversample = 8,
    .enableMsbFirst = false,
    .dataWidth = 8UL,
    .parity = CY_SCB_UART_PARITY_NONE,
    .stopBits = CY_SCB_UART_STOP_BITS_1,
    .enableInputFilter = false,
    .breakWidth = 11UL,
    .dropOnFrameError = false,
    .dropOnParityError = false,
    .receiverAddress = 0x0UL,
    .receiverAddressMask = 0x0UL,
    .acceptAddrInFifo = false,
    .enableCts = false,
    .ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rtsRxFifoLevel = 0UL,
    .rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rxFifoTriggerLevel = 63UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 63UL,
    .txFifoIntEnableMask = 0UL,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t DebugInterface_obj = 
    {
        .type = CYHAL_RSC_SCB,
        .block_num = 5U,
        .channel_num = 0U,
    };
#endif //defined (CY_USING_HAL)


void init_cycfg_peripherals(void)
{
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB5_CLOCK, CY_SYSCLK_DIV_8_BIT, 1U);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&DebugInterface_obj);
#endif //defined (CY_USING_HAL)
}
