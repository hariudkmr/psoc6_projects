#ifndef GPIO_H
#define GPIO_H

#include "cy_gpio.h"
#include <string.h>

#define USER_LED_PORT GPIO_PRT13
#define USER_LED_PIN  P13_7_PIN

void gpio_init();
void gpio_toggle_user_led();

// FreeRTOS Task
void LedTask(void *arg);

#endif
