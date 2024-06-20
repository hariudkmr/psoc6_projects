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
    
    gpio_init();
    uart_init(); 
   
    /* Enable global interrupts */
    __enable_irq();
   
    while (1) {
                  uart_transmit();
		  gpio_toggle_user_led();  
    
    }

    /* Return statement will not be hit. */
    return 0;
}

/* [] END OF FILE */
