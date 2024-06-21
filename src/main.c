/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
 */

#include "cy_pdl.h"
#include "main.h"
#include "system_psoc6.h"
#include "cy_device.h"
#include <gpio_psoc6_02_124_bga.h>

/*****************************************************************************
* Function Name: main(void)
******************************************************************************
* Summary:
*  Entry to the application.
*
* Parameters:
*  void

* Return:
*  Does not return.
*****************************************************************************/
int main(void)
{
    BaseType_t retval;

    /* Initialize the LED GPIO pin */
    gpio_init();
    uart_init();


    /* Enable global interrupts */
    __enable_irq();

    //retval = xTaskCreate(setTask, "Set LED Task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
    //retval = xTaskCreate(clrTask, "Clear LED Task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);

    //if (pdPASS == retval) {
    //    vTaskStartScheduler();
    //}

    while (1) {
        /* vTaskStartScheduler never returns */
	    uart_transmit();
	    gpio_toggle_user_led();
    }
}

/* [] END OF FILE */
