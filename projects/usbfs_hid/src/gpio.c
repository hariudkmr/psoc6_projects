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
#include "cy_sysint.h"

static uint32_t delay = 10;
static_assert(sizeof(gpio_pin) == 1, "Unexpected size");

st_gpioconfig gpio_configuration_array[TOTAL_IO_PINS] = {
    { LED9_PORT, LED9_PIN },
    { LED8_PORT, LED8_PIN },
    { USER_PORT, USER_PIN },
};

cy_stc_sysint_t user_switch_irq_cfg = {
    .intrSrc = USER_IRQ,
    .intrPriority = 7,
};

/*! \fn     GPIO Init
    \brief  GPIO Initialization function
*/

void gpio_init(void)
{
    Cy_SysInt_Init(&user_switch_irq_cfg, &user_switch_isr);
    NVIC_EnableIRQ(user_switch_irq_cfg.intrSrc);
}

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
    return Cy_GPIO_Read(gpio_configuration_array[pin].port, gpio_configuration_array[pin].pin);
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
        // vTaskDelay(delay);
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
        // vTaskDelay(1000);
    }
}

/*! \fn     user_switch ISR
 *  \brief  ISR routine for switch function.
 */

void user_switch_isr(void)
{
    Cy_GPIO_ClearInterrupt(USER_PORT, USER_NUM);
    if (delay > 2000)
        delay = 0;
    else
        delay += 100;
}
