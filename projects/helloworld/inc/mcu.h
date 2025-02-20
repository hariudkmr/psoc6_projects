/*
 ============================================================================
 Name        : mcu.h
 Author      : Hari Udayakumar
 Version     : 1.0
 Copyright   : n.a.
 Description : Sumobot based on PSOC6
 ============================================================================
 */
/**
 * @file mcu.h
 * @author Hari Udayakumar
 * @date 07-07-2024
 */

#ifndef MCU_INIT_H
#define MCU_INIT_H

#include "cy_pdl.h"
#include "system_psoc6.h"
#include "cy_device.h"

#define DWT_DEMCR       0xE000EDFC // Debug Exception and Monitor Control Register
#define DWT_CTRL        0xE0001000 ///< DWT Control Register Address
#define DWT_CYCLE_COUNT 0xE0001004 ///< DWT Count Register Address

/*! \fn     System Clock Initialization
    \brief  Configures PSOC6 System Clock clock configuraiton.
    \return no return value
*/
void system_clk_init(void);

/*! \fn     Debug Watch Trace Initialization
    \brief  Enables the DWT Counter and Initiaizes the DWT Counter to 0
    \return no return value
*/
void dwt_init(void);

#endif
