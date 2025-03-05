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

    init_cycfg_all();

    /* Enable interrupts */
    __enable_irq();

    for (;;) {
        Cy_SysLib_Delay(10UL);
    }
}

/* [] END OF FILE */
