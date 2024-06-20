#ifndef GPIO_H
#define GPIO_H

#include "cy_gpio.h"
#include <string.h>

#define USER_LED_PORT GPIO_PRT11
#define USER_LED_PIN  P11_1_PIN

void gpio_init();
void gpio_toggle_user_led();

#endif
