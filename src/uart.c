/* ========================================================================= */
/**
 * @file uart.c
 * @author Hari Udayakumar
 * @date 06-07-2024
 */
/* ========================================================================= */

/** @defgroup UART uart.c
 * The UART Module handles the uart debug messages, which will be printed using SCB5
 * @{
 */

#include "uart.h"

#include "FreeRTOS.h"
#include "task.h"

const char *string = "HelloWorld : ";

/* Allocate context for UART operation */
cy_stc_scb_uart_context_t uartContext;
/* Populate configuration structure */
const cy_stc_scb_uart_config_t uartConfig = {
    .uartMode = CY_SCB_UART_STANDARD,
    .enableMutliProcessorMode = false,
    .smartCardRetryOnNack = false,
    .irdaInvertRx = false,
    .irdaEnableLowPowerReceiver = false,
    .oversample = 12UL,
    .enableMsbFirst = false,
    .dataWidth = 8UL,
    .parity = CY_SCB_UART_PARITY_NONE,
    .stopBits = CY_SCB_UART_STOP_BITS_1,
    .enableInputFilter = false,
    .breakWidth = 11UL,
    .dropOnFrameError = false,
    .dropOnParityError = false,
    .receiverAddress = 0UL,
    .receiverAddressMask = 0UL,
    .acceptAddrInFifo = false,
    .enableCts = false,
    .ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rtsRxFifoLevel = 0UL,
    .rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rxFifoTriggerLevel = 0UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 0UL,
    .txFifoIntEnableMask = 0UL,
};

uint8_t count = 0;

void uart_init()
{

    /* Connect assigned divider to be a clock source for UART */
    Cy_SysClk_PeriphAssignDivider(UART_CLK, UART_CLK_DIV_TYPE, UART_CLK_DIV_NUMBER);

    /* UART desired baud rate is 115200 bps (Standard mode).
     * The UART baud rate = (clk_scb / Oversample).
     * For clk_peri = 50 MHz, select divider value 36 and get SCB clock = (50 MHz / 36) = 1,389 MHz.
     * Select Oversample = 12. These setting results UART data rate = 1,389 MHz / 12 = 115750 bps.
     */
    Cy_SysClk_PeriphSetDivider(UART_CLK_DIV_TYPE, UART_CLK_DIV_NUMBER, 35UL);
    Cy_SysClk_PeriphEnableDivider(UART_CLK_DIV_TYPE, UART_CLK_DIV_NUMBER);

    Cy_SCB_UART_Init(UART, &uartConfig, &uartContext);

    Cy_SCB_UART_Enable(UART);
}

void uart_transmit()
{

    Cy_SCB_UART_PutString(UART, string);
    Cy_SCB_UART_Put(UART, count++);
    Cy_SCB_UART_PutString(UART, "\n");
}

void debug_print_uarttask(void *arg)
{
    (void)arg;

    uart_init();

    for (;;) {
        /* Toggle the LED periodically */
        uart_transmit();
        vTaskDelay(1000);
    }
}
