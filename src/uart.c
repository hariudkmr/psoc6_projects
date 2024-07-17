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

#include "FreeRTOS.h"
#include "task.h"

const char *hw_string = "HelloWorld : ";
uint8_t     count = 0;

/*! \fn     UART transmit function
    \brief  Tranmits Helloworld string with the counter value.
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

    for (;;) {
        /* Toggle the LED periodically */
        uart_transmit(hw_string);
        vTaskDelay(1000);
    }
}
