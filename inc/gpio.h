#ifndef GPIO_H
#define GPIO_H

#include "cy_pdl.h"
#include <string.h>

#if PSOC62

#define USER_LED_PORT (GPIO_PRT13)
#define USER_LED_PIN  (P13_7_PIN)

#endif

#if PSOCS3

#define USER_LED_PORT (GPIO_PRT11)
#define USER_LED_PIN  (P11_1_PIN)

#endif

void gpio_init();

// FreeRTOS Task
void LedTask(void *arg);

#endif
