/*
 ============================================================================
 Name        : main.h
 Author      : Hari Udayakumar
 Version     : 1.0
 Copyright   : n.a.
 Description : Sumobot based on PSOC6
 ============================================================================
 */
/**
 * @file main.h
 * @author Hari Udayakumar
 * @date 07-07-2024
 */

#ifndef MAIN_H
#define MAIN_H

#include "cy_pdl.h"
#include "system_psoc6.h"
#include "cy_device.h"

/*
 *
 *
 * Peripheral Driver Header Files
 *
 *
 */
#include "mcu.h"
#include "gpio.h"
#include "uart.h"

/*
 *
 * Free RTOS Header Files
 *
 */
#include "FreeRTOS.h"
#include "task.h"
#include "SEGGER_SYSVIEW.h"

#endif
