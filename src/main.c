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
#include "cy_pdl.h"
#include "main.h"
#include "system_psoc6.h"
#include "cy_device.h"

/*
 * Clock configuration to be setup for FX3G2 device:
 *
 * CLK_PATH #1: IMO (8 MHz) --> PLL0 (100 MHz) --> clk_hf0 --> clk_fast
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

void system_clk_init(void)
{
    cy_stc_pll_manual_config_t pll0_cfg;
    // cy_stc_pll_manual_config_t pll1_cfg;
    // cy_stc_fll_manual_config_t fll_cfg;

    /* Configure PLL0 to generate 150 MHz clock, enable it and
     * wait for it to lock.
     */
    pll0_cfg.feedbackDiv = 50u;
    pll0_cfg.referenceDiv = 2u;
    pll0_cfg.outputDiv = 2u;
    pll0_cfg.lfMode = false; /* VCO frequency is 300 MHz. */
    pll0_cfg.outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO;
    Cy_SysClk_PllManualConfigure(1, &pll0_cfg);
    Cy_SysClk_PllEnable(1, 0);
    while (!Cy_SysClk_PllLocked(1))
        ;

    /* Select PLL0 output as clk_hf0. */
    Cy_SysLib_SetWaitStates(false, 100UL);
    Cy_SysClk_ClkHfSetSource(0, CY_SYSCLK_CLKHF_IN_CLKPATH1);
    Cy_SysClk_ClkFastSetDivider(0U);

    /* clk_peri is (clk_fast / 2) or 50 MHz. clk_slow has same frequency as clk_peri. */
    Cy_SysClk_ClkPeriSetDivider(1);
    Cy_SysClk_ClkSlowSetDivider(0);

    /* Update modified frequency with the PDL. */
    // Cy_SysClk_ClkHfUpdateFrequency(100000000UL);
    SystemCoreClockUpdate();

    /* clk_hf1 configuration. */
    Cy_SysClk_ClkHfDisable(1);
    Cy_SysClk_ClkHfSetSource(1, CY_SYSCLK_CLKHF_IN_CLKPATH1);
    Cy_SysClk_ClkHfSetDivider(1, CY_SYSCLK_CLKHF_DIVIDE_BY_2);
    Cy_SysClk_ClkHfEnable(1);

#if 0

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
#endif
}

#define DWT_CTRL 0xE0001000

#define DWT_CYCLE_COUNT 0xE0001004

uint32_t clkPerifreq;

/*-----------------------------------------------------------*/

/* configUSE_STATIC_ALLOCATION is set to 1, so the application must provide an
 * implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
 * used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                    StackType_t ** ppxIdleTaskStackBuffer,
                                    uint32_t * pulIdleTaskStackSize )
{
    /* If the buffers to be provided to the Idle task are declared inside this
     * function then they must be declared static - otherwise they will be allocated on
     * the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle
     * task's state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
     * Note that, as the array is necessarily of type StackType_t,
     * configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
/*-----------------------------------------------------------*/

/**
 * @brief This is to provide the memory that is used by the RTOS daemon/time task.
 *
 * If configUSE_STATIC_ALLOCATION is set to 1, so the application must provide an
 * implementation of vApplicationGetTimerTaskMemory() to provide the memory that is
 * used by the RTOS daemon/time task.
 */
void vApplicationGetTimerTaskMemory( StaticTask_t ** ppxTimerTaskTCBBuffer,
                                     StackType_t ** ppxTimerTaskStackBuffer,
                                     uint32_t * pulTimerTaskStackSize )
{
    /* If the buffers to be provided to the Timer task are declared inside this
     * function then they must be declared static - otherwise they will be allocated on
     * the stack and so not exists after this function exits. */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle
     * task's state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task's stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
     * Note that, as the array is necessarily of type StackType_t,
     * configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

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

    system_clk_init();
    /* Initialize the LED GPIO pin */
    /* Enable global interrupts */
    (*(int *)DWT_CTRL) |= 0x1; // Counter enable

    (*(int *)DWT_CYCLE_COUNT) = 0; // Set counter to Zero
                                   //
    clkPerifreq = Cy_SysClk_ClkPeriGetFrequency();

    __enable_irq();

    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();

    xTaskCreate(LedTask, "Toggle LED Task", 512, NULL, 5, NULL);
    xTaskCreate(UartTask, "UART TX Task", 512, NULL, 5, NULL);

    vTaskStartScheduler();

    while (1) {
        /* vTaskStartScheduler never returns */
    }
}

/* [] END OF FILE */
