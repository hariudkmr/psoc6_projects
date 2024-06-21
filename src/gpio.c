#include "gpio.h"

#include "FreeRTOS.h"
#include "task.h"

uint32_t delay = 0;

void gpio_init()
{

    cy_stc_gpio_pin_config_t pinCfg;
    memset((void *)&pinCfg, 0, sizeof(pinCfg));

    pinCfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    pinCfg.hsiom = HSIOM_SEL_GPIO;

    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &pinCfg);
}

void gpio_toggle_user_led()
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    Cy_SysLib_Delay(delay);
}

void LedTask(void *arg)
{
    (void)arg;
    
    gpio_init();
    
    for (;;) {
        /* Toggle the LED periodically */
        Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        vTaskDelay(500);
    }
}

