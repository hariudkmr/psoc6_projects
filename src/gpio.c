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

#include "FreeRTOS.h"
#include "task.h"

uint32_t delay = 0;

st_gpioconfig gpio_configuration_array[TOTAL_IO_PINS] = {
#if PSOC62 || PSOCWB
    { GPIO_PRT13, P13_7_PIN, CY_GPIO_DM_STRONG_IN_OFF, HSIOM_SEL_GPIO },
    { GPIO_PRT5, P5_1_PIN, CY_GPIO_DM_STRONG_IN_OFF, P5_1_SCB5_UART_TX },
    { GPIO_PRT5, P5_0_PIN, CY_GPIO_DM_HIGHZ, P5_0_SCB5_UART_RX },

#endif

#if PSOCS3
    { GPIO_PRT11, P11_1_PIN, CY_GPIO_DM_STRONG_IN_OFF, HSIOM_SEL_GPIO },
    { GPIO_PRT10, P10_1_PIN, CY_GPIO_DM_STRONG_IN_OFF, P10_1_SCB1_UART_TX },
    { GPIO_PRT10, P10_0_PIN, CY_GPIO_DM_HIGHZ, P10_0_SCB1_UART_RX },

#endif
};

void gpio_init()
{

    cy_stc_gpio_pin_config_t pinCfg;
    memset((void *)&pinCfg, 0, sizeof(pinCfg));

    for (int i = 0; i < TOTAL_IO_PINS; i++) {

        pinCfg.driveMode = gpio_configuration_array[i].drive_mode;
        pinCfg.hsiom = gpio_configuration_array[i].hsio;
        Cy_GPIO_Pin_Init(gpio_configuration_array[i].port, gpio_configuration_array[i].pin,
                         &pinCfg);
    }
}

void gpio_set(gpio_pin pin)
{
    Cy_GPIO_Set(gpio_configuration_array[pin].port, gpio_configuration_array[pin].pin);
}

void gpio_clear(gpio_pin pin)
{
    Cy_GPIO_Clr(gpio_configuration_array[pin].port, gpio_configuration_array[pin].pin);
}

void gpio_toggle(gpio_pin pin)
{
    Cy_GPIO_Inv(gpio_configuration_array[pin].port, gpio_configuration_array[pin].pin);
}

void user_led_gpiotask(void *arg)
{
    (void)arg;

    for (;;) {
        /* Toggle the LED periodically */
        gpio_toggle(USER_LED);
        vTaskDelay(500);
    }
}
