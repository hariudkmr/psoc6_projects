/*******************************************************************************
* File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

#define STD_ID_FILTER_0 \
{\
    .sfid2 = 0U, \
    .sfid1 = 0U, \
    .sfec = CY_CANFD_SFEC_STORE_RX_FIFO_0, \
    .sft = CY_CANFD_SFT_RANGE_SFID1_SFID2, \
 }
#define EXT_ID_FILTER_0 \
{\
    .f0_f = &canfd_0_chan_0_extIdFilterF0Config_0, \
    .f1_f = &canfd_0_chan_0_extIdFilterF1Config_0, \
 }

const cy_stc_canfd_bitrate_t canfd_0_chan_0_nominalBitrateConfig = 
{
    .prescaler = 3U - 1U,
    .timeSegment1 = 7U - 1U,
    .timeSegment2 = 2U - 1U,
    .syncJumpWidth = 2U - 1U,
};
const cy_stc_canfd_bitrate_t canfd_0_chan_0_dataBitrateConfig = 
{
    .prescaler = 2U - 1U,
    .timeSegment1 = 15U - 1U,
    .timeSegment2 = 8U - 1U,
    .syncJumpWidth = 4U - 1U,
};
const cy_stc_canfd_transceiver_delay_compensation_t canfd_0_chan_0_tdcConfig = 
{
    .tdcEnabled = false,
    .tdcOffset = 0U,
    .tdcFilterWindow = 0U,
};
const cy_stc_id_filter_t canfd_0_chan_0_stdIdFilter_0 = 
{
    .sfid2 = 0U,
    .sfid1 = 0U,
    .sfec = CY_CANFD_SFEC_STORE_RX_FIFO_0,
    .sft = CY_CANFD_SFT_RANGE_SFID1_SFID2,
};
static const cy_stc_id_filter_t canfd_0_chan_0_stdIdFilters[] = 
{
    [0] = STD_ID_FILTER_0,
};
static const cy_stc_canfd_sid_filter_config_t canfd_0_chan_0_sidFiltersConfig = 
{
    .numberOfSIDFilters = 1U,
    .sidFilter = canfd_0_chan_0_stdIdFilters,
};
const cy_stc_canfd_f0_t canfd_0_chan_0_extIdFilterF0Config_0 = 
{
    .efid1 = 0U,
    .efec = CY_CANFD_EFEC_STORE_RX_FIFO_0,
};
const cy_stc_canfd_f1_t canfd_0_chan_0_extIdFilterF1Config_0 = 
{
    .efid2 = 0U,
    .eft = CY_CANFD_EFT_RANGE_EFID1_EFID2,
};
const cy_stc_extid_filter_t canfd_0_chan_0_extIdFilter_0 = 
{
    .f0_f = &canfd_0_chan_0_extIdFilterF0Config_0,
    .f1_f = &canfd_0_chan_0_extIdFilterF1Config_0,
};
const cy_stc_extid_filter_t canfd_0_chan_0_extIdFilters[] = 
{
    [0] = EXT_ID_FILTER_0,
};
const cy_stc_canfd_extid_filter_config_t canfd_0_chan_0_extIdFiltersConfig = 
{
    .numberOfEXTIDFilters = 1U,
    .extidFilter = (cy_stc_extid_filter_t*)&canfd_0_chan_0_extIdFilters,
    .extIDANDMask = 536870911UL,
};
const cy_stc_canfd_global_filter_config_t canfd_0_chan_0_globalFilterConfig = 
{
    .nonMatchingFramesStandard = CY_CANFD_ACCEPT_IN_RXFIFO_0,
    .nonMatchingFramesExtended = CY_CANFD_ACCEPT_IN_RXFIFO_0,
    .rejectRemoteFramesStandard = false,
    .rejectRemoteFramesExtended = false,
};
const cy_en_canfd_fifo_config_t canfd_0_chan_0_rxFifo0Config = 
{
    .mode = CY_CANFD_FIFO_MODE_BLOCKING,
    .watermark = 0U,
    .numberOfFIFOElements = 0U,
    .topPointerLogicEnabled = false,
};
const cy_en_canfd_fifo_config_t canfd_0_chan_0_rxFifo1Config = 
{
    .mode = CY_CANFD_FIFO_MODE_BLOCKING,
    .watermark = 0U,
    .numberOfFIFOElements = 0U,
    .topPointerLogicEnabled = false,
};
const cy_stc_canfd_config_t canfd_0_chan_0_config = 
{
    .txCallback = NULL,
    .rxCallback = NULL,
    .errorCallback = NULL,
    .canFDMode = false,
    .bitrate = &canfd_0_chan_0_nominalBitrateConfig,
    .fastBitrate = &canfd_0_chan_0_dataBitrateConfig,
    .tdcConfig = &canfd_0_chan_0_tdcConfig,
    .sidFilterConfig = &canfd_0_chan_0_sidFiltersConfig,
    .extidFilterConfig = &canfd_0_chan_0_extIdFiltersConfig,
    .globalFilterConfig = &canfd_0_chan_0_globalFilterConfig,
    .rxBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
    .rxFIFO1DataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
    .rxFIFO0DataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
    .txBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
    .rxFIFO0Config = &canfd_0_chan_0_rxFifo0Config,
    .rxFIFO1Config = &canfd_0_chan_0_rxFifo1Config,
    .noOfRxBuffers = 1U,
    .noOfTxBuffers = 1U,
    .messageRAMaddress = CY_CAN0MRAM_BASE + 0U,
    .messageRAMsize = 4096U,
};
cy_stc_canfd_t0_t canfd_0_chan_0_T0RegisterBuffer_0 = 
{
    .id = 0U,
    .rtr = CY_CANFD_RTR_DATA_FRAME,
    .xtd = CY_CANFD_XTD_STANDARD_ID,
    .esi = CY_CANFD_ESI_ERROR_ACTIVE,
};
cy_stc_canfd_t1_t canfd_0_chan_0_T1RegisterBuffer_0 = 
{
    .dlc = 0U,
    .brs = false,
    .fdf = CY_CANFD_FDF_STANDARD_FRAME,
    .efc = false,
    .mm = 0U,
};
uint32_t canfd_0_chan_0_dataBuffer_0[] = 
{
    [canfd_0_chan_0_DATA_0] = 0U,
    [canfd_0_chan_0_DATA_1] = 0U,
};
cy_stc_canfd_tx_buffer_t canfd_0_chan_0_txBuffer_0 = 
{
    .t0_f = &canfd_0_chan_0_T0RegisterBuffer_0,
    .t1_f = &canfd_0_chan_0_T1RegisterBuffer_0,
    .data_area_f = canfd_0_chan_0_dataBuffer_0,
};
#if defined (CY_USING_HAL)
    const cyhal_resource_inst_t canfd_0_chan_0_obj = 
    {
        .type = CYHAL_RSC_CAN,
        .block_num = 0U,
        .channel_num = 0U,
    };
#endif //defined (CY_USING_HAL)


void init_cycfg_peripherals(void)
{
    Cy_SysClk_PeriphAssignDivider(PCLK_CANFD0_CLOCK_CAN0, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&canfd_0_chan_0_obj);
#endif //defined (CY_USING_HAL)
}
