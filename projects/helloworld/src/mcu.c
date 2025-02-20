/* ========================================================================= */
/**
 * @file mcu_init.c
 * @author Hari Udayakumar
 * @date 07-07-2024
 * @brief Contains System Confgiuration
 */
/* ========================================================================= */
/** @defgroup MCU MCU_INIT
 *  Controller Configured file for PSOC6 Project.
 * @{
 */
#include "mcu.h"

/**
 * Clock configuration to be setup for PSOC6 device:
 * The system currently uses IMO as the input source
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

/**
 * Enabled the Debut and Watch Trace Counter.
 * And initializes the counter value to 0 at the start of Application
 *
 */
void dwt_init(void)
{
    (*(int *)DWT_DEMCR) |= 1 << 24; // Set bit 24(TRCENA)
    (*(int *)DWT_CYCLE_COUNT) = 0; // Set counter to Zero
    (*(int *)DWT_CTRL) |= 0x1; // Counter enable
}
