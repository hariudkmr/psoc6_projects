/* ========================================================================= */
/**
 * @file main.c
 * @author Hari Udayakumar
 * @date 06-07-2024
 * @brief Redesign the Sumobot Project using PSOC6
 */
/* ========================================================================= */

/** @defgroup Sumobot Sumobot
 *  * Main file of the project.\n
 * @{
 */
#include "main.h"

/**
 * Main entry point of the program.
 */
int main(void)
{

    system_clk_init();
    /* Initialize the LED GPIO pin */
    /* Enable global interrupts */
    dwt_init();
    gpio_init();

    __enable_irq();

    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();

    xTaskCreate(user_led_gpiotask, "Toggle LED Task", 512, NULL, 5, NULL);
    xTaskCreate(debug_print_uarttask, "UART TX Task", 512, NULL, 5, NULL);

    vTaskStartScheduler();

    while (1) {
        /* vTaskStartScheduler never returns */
    }
}

/* [] END OF FILE */
