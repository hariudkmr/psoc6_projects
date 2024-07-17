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
#include "cycfg.h"

/**
 * Main entry point of the program.
 */
int main(void)
{

    BaseType_t retval;

    init_cycfg_all();
    /* Initialize the LED GPIO pin */
    /* Enable global interrupts */
    dwt_init();

    __enable_irq();

    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();

    retval = xTaskCreate(user_led_gpiotask, "Toggle LED9 Task", 512, NULL, 5, NULL);
    CY_ASSERT(retval == pdPASS);
    retval = xTaskCreate(user_led8_gpiotask, "Toggle LED8 Task", 512, NULL, 5, NULL);
    CY_ASSERT(retval == pdPASS);

    vTaskStartScheduler();

    while (1) {
        /* vTaskStartScheduler never returns */
    }
}

/* [] END OF FILE */
