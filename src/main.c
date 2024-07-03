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

#if 0
/*
 * Clock configuration to be setup for FX3G2 device:
 *
 * CLK_PATH #1: IMO (8 MHz) --> PLL0 (150 MHz) --> clk_hf0 --> clk_fast
 *                                             |           |
 *                                             |           --> clk_peri (75 MHz) --> clk_slow
 *                                             |
 *                                             --> clk_hf1 (75 MHz) --> clk_smif
 *                                             |
 *                                             --> clk_hf4 (150 MHz) --> clk_lvds
 *
 * CLK_PATH #2: IMO (8 MHz) --> PLL1 (48 MHz) ----> clk_hf2 --> clk_usbfs
 *
 * CLK_PATH #0: IMO (8 MHz) --> FLL (24.576 MHz) --> clk_hf3 --> clk_pdm (3.072 MHz)
 *
 * CLK_PATH #3: ECO (24 MHz) --> USBHS PLL Reference
 */

void fx3g2_clk_init(void)
{
    cy_stc_pll_manual_config_t pll0_cfg;
    cy_stc_pll_manual_config_t pll1_cfg;
    cy_stc_fll_manual_config_t fll_cfg;

    /* Configure PLL0 to generate 150 MHz clock, enable it and
     * wait for it to lock.
     */
    pll0_cfg.feedbackDiv = 75u;
    pll0_cfg.referenceDiv = 2u;
    pll0_cfg.outputDiv = 2u;
    pll0_cfg.lfMode = false; /* VCO frequency is 300 MHz. */
    pll0_cfg.outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO;
    Cy_SysClk_PllManualConfigure(1, &pll0_cfg);
    Cy_SysClk_PllEnable(1, 0);
    while (!Cy_SysClk_PllLocked(1))
        ;

    /* Select PLL0 output as clk_hf0. */
    Cy_SysLib_SetWaitStates(false, 150UL);
    Cy_SysClk_ClkHfSetSource(0, CY_SYSCLK_CLKHF_IN_CLKPATH1);
    Cy_SysClk_ClkFastSetDivider(0U);

    /* clk_peri is (clk_fast / 2) or 75 MHz. clk_slow has same frequency as clk_peri. */
    Cy_SysClk_ClkPeriSetDivider(1);
    Cy_SysClk_ClkSlowSetDivider(0);

    /* Update modified frequency with the PDL. */
    Cy_SysClk_ClkHfUpdateFrequency(150000000UL);
    SystemCoreClockUpdate();

    /* clk_hf1 configuration. */
    Cy_SysClk_ClkHfDisable(1);
    Cy_SysClk_ClkHfSetSource(1, CY_SYSCLK_CLKHF_IN_CLKPATH1);
    Cy_SysClk_ClkHfSetDivider(1, CY_SYSCLK_CLKHF_DIVIDE_BY_2);
    Cy_SysClk_ClkHfEnable(1);

    /* clk_hf4 configuration. */
    Cy_SysClk_ClkHfDisable(4);
    Cy_SysClk_ClkHfSetSource(4, CY_SYSCLK_CLKHF_IN_CLKPATH1);
    Cy_SysClk_ClkHfSetDivider(4, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(4);

    /* Configure PLL1 to generate 48 MHz clock, enable it and
     * wait for it to lock.
     */
    pll1_cfg.feedbackDiv = 48u;
    pll1_cfg.referenceDiv = 2u;
    pll1_cfg.outputDiv = 4u;
    pll1_cfg.lfMode = true; /* VCO frequency is 192 MHz. */
    pll1_cfg.outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO;
    Cy_SysClk_PllManualConfigure(2, &pll1_cfg);
    Cy_SysClk_PllEnable(2, 0);
    while (!Cy_SysClk_PllLocked(2))
        ;

    /* Select PLL1 output as source for clk_hf2 and enable it. */
    Cy_SysClk_ClkHfDisable(2);
    Cy_SysClk_ClkHfSetSource(2, CY_SYSCLK_CLKHF_IN_CLKPATH2);
    Cy_SysClk_ClkHfSetDivider(2, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(2);

    /* FLL configuration to generate 24.576 MHz clock for PDM/TDM operation. */
    fll_cfg.fllMult = 498UL;
    fll_cfg.refDiv = 81U;
    fll_cfg.ccoRange = CY_SYSCLK_FLL_CCO_RANGE0; /* CCO frequency is 49.1 MHz. */
    fll_cfg.enableOutputDiv = true;
    fll_cfg.lockTolerance = 6U;
    fll_cfg.igain = 8U;
    fll_cfg.pgain = 7U;
    fll_cfg.settlingCount = 8U;
    fll_cfg.outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO;
    fll_cfg.cco_Freq = 108U;
    Cy_SysClk_FllDisable();
    Cy_SysClk_FllManualConfigure(&fll_cfg);
    Cy_SysClk_FllEnable(0);
    while (!Cy_SysClk_FllLocked())
        ;

    /* Select FLL output as source for clk_hf3 and enable it. */
    Cy_SysClk_ClkHfDisable(3);
    Cy_SysClk_ClkHfSetSource(3, CY_SYSCLK_CLKHF_IN_CLKPATH0);
    Cy_SysClk_ClkHfSetDivider(3, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(3);
}
#endif 

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

    /* Initialize the LED GPIO pin */
    /* Enable global interrupts */
    __enable_irq();

    xTaskCreate(LedTask, "Toggle LED Task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
    xTaskCreate(UartTask, "UART TX Task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);


    vTaskStartScheduler();

    while (1) {
        /* vTaskStartScheduler never returns */
    }
}

/* [] END OF FILE */
