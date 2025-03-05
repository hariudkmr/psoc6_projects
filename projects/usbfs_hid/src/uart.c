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
#include "cycfg_peripherals.h"
#include "uart.h"

cy_stc_scb_uart_context_t DebugInterfaceContext;

extern const char *hw_string;
extern uint8_t     count;

/*! \fn     UART Initialization
    \brief  Configures PSOC6 SCB as UART for printing the debug information.
    \return no return value
*/
void uart_init()
{

    Cy_SCB_UART_Init(DebugInterface_HW, &DebugInterface_config, &DebugInterfaceContext);
    Cy_SCB_UART_Enable(DebugInterface_HW);
}

/*! \fn     UART Initialization
    \brief  Configures PSOC6 SCB as UART for printing the debug information.
    \return no return value
*/
void uart_transmit(const char *string)
{

    Cy_SCB_UART_PutString(DebugInterface_HW, string);
    Cy_SCB_UART_Put(DebugInterface_HW, count++);
    Cy_SCB_UART_PutString(DebugInterface_HW, "\n");
}

/*! \fn     debug_print_uarttask(void *arg)
    \brief  Transmit a Constant string using RTOS Task.
*/
void debug_print_uarttask(void *arg)
{
    (void)arg;

    uart_init();

    for (;;) {
        /* Toggle the LED periodically */
        uart_transmit(hw_string);
        // vTaskDelay(1000);
    }
}
