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
