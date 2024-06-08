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
#include "system_psoc6.h"
#include "cy_device.h"
#include <gpio_psoc6_02_124_bga.h>

const char* string = "HelloWorld : ";

/* Assign pins for UART on SCB5: P5[0], P5[1] */
#define UART            SCB5
#define UART_CLK        PCLK_SCB5_CLOCK
#define UART_PORT       P5_0_PORT
#define UART_RX_NUM     P5_0_NUM
#define UART_TX_NUM     P5_1_NUM

/* Assign divider type and number for UART */
#define UART_CLK_DIV_TYPE     (CY_SYSCLK_DIV_16_BIT)
#define UART_CLK_DIV_NUMBER   (0U)

/* Allocate context for UART operation */
cy_stc_scb_uart_context_t uartContext;
/* Populate configuration structure */
const cy_stc_scb_uart_config_t uartConfig =
{
    .uartMode                   = CY_SCB_UART_STANDARD,
    .enableMutliProcessorMode   = false,
    .smartCardRetryOnNack       = false,
    .irdaInvertRx               = false,
    .irdaEnableLowPowerReceiver = false,
    .oversample                 = 12UL,
    .enableMsbFirst             = false,
    .dataWidth                  = 8UL,
    .parity                     = CY_SCB_UART_PARITY_NONE,
    .stopBits                   = CY_SCB_UART_STOP_BITS_1,
    .enableInputFilter          = false,
    .breakWidth                 = 11UL,
    .dropOnFrameError           = false,
    .dropOnParityError          = false,
    .receiverAddress            = 0UL,
    .receiverAddressMask        = 0UL,
    .acceptAddrInFifo           = false,
    .enableCts                  = false,
    .ctsPolarity                = CY_SCB_UART_ACTIVE_LOW,
    .rtsRxFifoLevel             = 0UL,
    .rtsPolarity                = CY_SCB_UART_ACTIVE_LOW,
    .rxFifoTriggerLevel  = 0UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel  = 0UL,
    .txFifoIntEnableMask = 0UL,
};

#define USER_LED_PORT	GPIO_PRT11
#define USER_LED_PIN	P11_1_PIN


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
    cy_stc_gpio_pin_config_t pinCfg;
    memset((void *) &pinCfg, 0, sizeof(pinCfg));

     pinCfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
     pinCfg.hsiom = HSIOM_SEL_GPIO;

    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN,&pinCfg);
                       
  
    /* Connect assigned divider to be a clock source for UART */
    Cy_SysClk_PeriphAssignDivider(UART_CLK, UART_CLK_DIV_TYPE, UART_CLK_DIV_NUMBER);
    
    /* UART desired baud rate is 115200 bps (Standard mode).
    * The UART baud rate = (clk_scb / Oversample).
    * For clk_peri = 50 MHz, select divider value 36 and get SCB clock = (50 MHz / 36) = 1,389 MHz.
    * Select Oversample = 12. These setting results UART data rate = 1,389 MHz / 12 = 115750 bps.
    */
    Cy_SysClk_PeriphSetDivider   (UART_CLK_DIV_TYPE, UART_CLK_DIV_NUMBER, 35UL);
    Cy_SysClk_PeriphEnableDivider(UART_CLK_DIV_TYPE, UART_CLK_DIV_NUMBER);

    /* Connect SCB5 UART function to pins */
    Cy_GPIO_SetHSIOM(UART_PORT, UART_RX_NUM, P5_0_SCB5_UART_RX);
    Cy_GPIO_SetHSIOM(UART_PORT, UART_TX_NUM, P5_1_SCB5_UART_TX);

    /* Configure pins for UART operation */
    Cy_GPIO_SetDrivemode(UART_PORT, UART_RX_NUM, CY_GPIO_DM_HIGHZ);
    Cy_GPIO_SetDrivemode(UART_PORT, UART_TX_NUM, CY_GPIO_DM_STRONG_IN_OFF);
    
    Cy_SCB_UART_Init(UART, &uartConfig, &uartContext);

    Cy_SCB_UART_Enable(UART);

    /* Enable global interrupts */
    __enable_irq();
    uint32_t count = 0;

     while(1)
    {
        Cy_SCB_UART_PutString(UART, string);
        Cy_SCB_UART_Put(UART, count++);
        Cy_SCB_UART_PutString(UART, "\n");
	Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        Cy_SysLib_Delay(1000);
    }

    /* Return statement will not be hit. */
    return 0;
}

/* [] END OF FILE */
