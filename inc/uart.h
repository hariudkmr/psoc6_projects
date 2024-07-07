/*
 ============================================================================
 Name        : uart.h
 Author      : Hari Udayakumar
 Version     : 1.0
 Copyright   : n.a.
 Description : Sumobot based on PSOC6
 ============================================================================
 */
/**
 * @file uart.h
 * @author Hari Udayakumar
 * @date 07-07-2024
 */

#ifndef UART_H
#define UART_H

#include "cy_pdl.h"

#if PSOC62 || PSOCWB
#define UART     SCB5
#define UART_CLK PCLK_SCB5_CLOCK
#endif

#if PSOCS3
#define UART     SCB1
#define UART_CLK PCLK_SCB1_CLOCK
#endif

/* Assign divider type and number for UART */
#define UART_CLK_DIV_TYPE   (CY_SYSCLK_DIV_16_BIT)
#define UART_CLK_DIV_NUMBER (0U)

/*! \fn     UART Initialization
    \brief  Configures PSOC6 SCB as UART for printing the debug information.
    \return no return value
*/
void uart_init();

/*! \fn     UART Transmit
    \brief  Configures PSOC6 SCB as UART for printing the debug information.
    \param  string -> Debug String
    \return no return value
*/
void uart_transmit(const char *string);

/*! \fn     debug_print_uarttask(void *arg)
    \brief  Transmit a Constant string using RTOS Task.
*/
void debug_print_uarttask(void *arg);
#endif
