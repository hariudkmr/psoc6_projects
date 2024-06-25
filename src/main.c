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
    DWT->CTRL |= (1 << 0);

    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();

    /* Enable global interrupts */
    __enable_irq();

    retval = xTaskCreate(LedTask, "Toggle LED Task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
    retval = xTaskCreate(UartTask, "UART TX Task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);

    if (pdPASS == retval) {
        vTaskStartScheduler();
    }

    while (1) {
        /* vTaskStartScheduler never returns */
    }
}

/* [] END OF FILE */
