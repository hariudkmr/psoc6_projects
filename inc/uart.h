#ifndef UART_H
#define UART_H

#include "cy_pdl.h"

/* Assign pins for UART on SCB5: P5[0], P5[1] */
#if PSOC62 || PSOCWB
#define UART        SCB5
#define UART_CLK    PCLK_SCB5_CLOCK
#define UART_PORT   P5_0_PORT
#define UART_RX_NUM P5_0_NUM
#define UART_TX_NUM P5_1_NUM
#define SCB_UART_RX P5_0_SCB5_UART_RX
#define SCB_UART_TX P5_1_SCB5_UART_TX
#endif

#if PSOCS3
#define UART        SCB1
#define UART_CLK    PCLK_SCB1_CLOCK
#define UART_PORT   P10_0_PORT
#define UART_RX_NUM P10_0_NUM
#define UART_TX_NUM P10_1_NUM
#define SCB_UART_RX P10_0_SCB1_UART_RX
#define SCB_UART_TX P10_1_SCB1_UART_TX
#endif

/* Assign divider type and number for UART */
#define UART_CLK_DIV_TYPE   (CY_SYSCLK_DIV_16_BIT)
#define UART_CLK_DIV_NUMBER (0U)

void uart_init();
void uart_transmit();

void UartTask(void *arg);
#endif
