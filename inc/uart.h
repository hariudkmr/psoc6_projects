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

void uart_init();
void uart_transmit();

void debug_print_uarttask(void *arg);
#endif
