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

#include "cy_pdl.h"
#include "cycfg.h"

#include "OneButtonC.h"

OneButton_t button1; // Declare global instance
uint16_t    press_cnt = 0;

void B1_press()
{ 
    // Basic function to count button presses
    press_cnt++;
    Cy_GPIO_Inv(LED8_PORT, LED8_PIN);
}

void B1_dpress()
{ 

    // Basic function to count button presses
    Cy_GPIO_Set(LED8_PORT, LED8_PIN);
}


/**
 * Main entry point of the program.
 */
int main(void)
{

    // Initialize the System
    init_cycfg_all();


    OB_Init(&button1); // Init the button with default params
    OB_Setup(&button1, USER_PORT, USER_PIN, true); // Configure the button

    // Setup callback function
    button1.maxClicks = 3;
    OB_AttachCallback(&button1, OB_EV_DOUBLE_CLICK, B1_press);

    // Enable interrupts
    __enable_irq();

    for (;;) {
        OB_Tick(&button1); // Call ticks in main loop
    }
}

/* [] END OF FILE */
