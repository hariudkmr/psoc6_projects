/*******************************************************************************
* File Name: cycfg_peripherals.h
*
* Description:
* Peripheral Hardware Block configuration
* This file was automatically generated and should not be modified.
* Tools Package 2.4.1.9711
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_canfd.h"
#include "cy_sysclk.h"
#if defined (CY_USING_HAL)
    #include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)

#if defined(__cplusplus)
extern "C" {
#endif

#define canfd_0_chan_0_ENABLED 1U
#define canfd_0_chan_0_HW CANFD0
#define canfd_0_chan_0_CHANNEL CANFD0_CH0
#define canfd_0_chan_0_STD_ID_FILTER_ID_0 0
#define canfd_0_chan_0_EXT_ID_FILTER_ID_0 0
#define canfd_0_chan_0_DATA_0 0
#define canfd_0_chan_0_DATA_1 1
#define canfd_0_chan_0_DATA_2 2
#define canfd_0_chan_0_DATA_3 3
#define canfd_0_chan_0_DATA_4 4
#define canfd_0_chan_0_DATA_5 5
#define canfd_0_chan_0_DATA_6 6
#define canfd_0_chan_0_DATA_7 7
#define canfd_0_chan_0_DATA_8 8
#define canfd_0_chan_0_DATA_9 9
#define canfd_0_chan_0_DATA_10 10
#define canfd_0_chan_0_DATA_11 11
#define canfd_0_chan_0_DATA_12 12
#define canfd_0_chan_0_DATA_13 13
#define canfd_0_chan_0_DATA_14 14
#define canfd_0_chan_0_DATA_15 15
#define canfd_0_chan_0_IRQ_0 canfd_0_interrupts0_0_IRQn
#define canfd_0_chan_0_IRQ_1 canfd_0_interrupts1_0_IRQn

extern const cy_stc_canfd_bitrate_t canfd_0_chan_0_nominalBitrateConfig;
extern const cy_stc_canfd_bitrate_t canfd_0_chan_0_dataBitrateConfig;
extern const cy_stc_canfd_transceiver_delay_compensation_t canfd_0_chan_0_tdcConfig;
extern const cy_stc_id_filter_t canfd_0_chan_0_stdIdFilter_0;
extern const cy_stc_canfd_f0_t canfd_0_chan_0_extIdFilterF0Config_0;
extern const cy_stc_canfd_f1_t canfd_0_chan_0_extIdFilterF1Config_0;
extern const cy_stc_extid_filter_t canfd_0_chan_0_extIdFilter_0;
extern const cy_stc_extid_filter_t canfd_0_chan_0_extIdFilters[];
extern const cy_stc_canfd_extid_filter_config_t canfd_0_chan_0_extIdFiltersConfig;
extern const cy_stc_canfd_global_filter_config_t canfd_0_chan_0_globalFilterConfig;
extern const cy_en_canfd_fifo_config_t canfd_0_chan_0_rxFifo0Config;
extern const cy_en_canfd_fifo_config_t canfd_0_chan_0_rxFifo1Config;
extern const cy_stc_canfd_config_t canfd_0_chan_0_config;
extern cy_stc_canfd_t0_t canfd_0_chan_0_T0RegisterBuffer_0;
extern cy_stc_canfd_t1_t canfd_0_chan_0_T1RegisterBuffer_0;
extern uint32_t canfd_0_chan_0_dataBuffer_0[];
extern cy_stc_canfd_tx_buffer_t canfd_0_chan_0_txBuffer_0;
#if defined (CY_USING_HAL)
    extern const cyhal_resource_inst_t canfd_0_chan_0_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PERIPHERALS_H */
