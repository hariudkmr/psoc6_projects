/* ========================================================================= */
/**
 * @file gpio.c
 * @author Hari Udayakumar
 * @date 06-07-2024
 */
/* ========================================================================= */

/** @defgroup GPIO gpio.c
 * The GPIO Modules handles all the initialization of the IO Pins, configures P13.7 USER LED
 * which toggles every second. This Led acts as the Heart Beat of the System
 * @{
 */

#include "gpio.h"
#include "cycfg_pins.h"

#include "FreeRTOS.h"
#include "task.h"

uint32_t delay = 0;
static_assert(sizeof(gpio_pin) == 1, "Unexpected size");

st_gpioconfig gpio_configuration_array[TOTAL_IO_PINS] = {
    { LED9_PORT, LED9_PIN },
    { LED8_PORT, LED8_PIN },
};

/*! \fn     GPIO Write
    \brief  Controls the GPIO State using the below functions.
    \param  gpio_pin pin -> Index of the GPIO Configuration in GPIO
    \param  gpio_state state -> State of the GPIO pin
    \return no return value
*/
void gpio_write(gpio_pin pin, gpio_state state)
{
    if (state == IO_LOW) {
        Cy_GPIO_Set(gpio_configuration_array[pin].port, gpio_configuration_array[pin].pin);
    } else if (state == IO_HIGH) {
        Cy_GPIO_Clr(gpio_configuration_array[pin].port, gpio_configuration_array[pin].pin);
    }
}

/*! \fn     GPIO Read
    \brief  Reads the state of the GPIO PIN using the below functions.
    \param  gpio_pin pin -> Index of the GPIO Configuration in st_gpioconfig structure array
    \return -> State of the GPIO pin
*/
gpio_state gpio_read(gpio_pin pin)
{
    return IO_LOW;
}

/*! \fn     GPIO Toggle
    \brief  Toggles the stato of GPIO pin using the below functions.
    \param  gpio_pin pin -> Index of the GPIO Configuration in GPIO
    \return no return value
*/
void gpio_toggle(gpio_pin pin)
{
    Cy_GPIO_Inv(gpio_configuration_array[pin].port, gpio_configuration_array[pin].pin);
}

/*! \fn     user_led_gpiotask(void *arg)
    \brief  Toggle User Led using RTOS Task.
*/
void user_led_gpiotask(void *arg)
{
    (void)arg;

    for (;;) {
        /* Toggle the LED periodically */
        gpio_toggle(LED9);
        vTaskDelay(500);
    }
}

/*! \fn     user_led_gpiotask(void *arg)
    \brief  Toggle User Led using RTOS Task.
*/
void user_led8_gpiotask(void *arg)
{
    (void)arg;

    for (;;) {
        /* Toggle the LED periodically */
        gpio_toggle(LED8);
        vTaskDelay(1000);
    }
}
