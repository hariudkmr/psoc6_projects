#ifndef UART_H
#define UART_H

#include "cy_pdl.h"

/* Assign pins for UART on SCB5: P5[0], P5[1] */
#define UART        SCB5
#define UART_CLK    PCLK_SCB5_CLOCK
#define UART_PORT   P5_0_PORT
#define UART_RX_NUM P5_0_NUM
#define UART_TX_NUM P5_1_NUM

/* Assign divider type and number for UART */
#define UART_CLK_DIV_TYPE   (CY_SYSCLK_DIV_16_BIT)
#define UART_CLK_DIV_NUMBER (0U)

void uart_init();
void uart_transmit();

void UartTask(void *arg);
#endif
