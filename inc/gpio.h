#ifndef GPIO_H
#define GPIO_H

#include "cy_pdl.h"
#include <string.h>

typedef enum {
    IO_LOW,
    IO_HIGH,
} gpio_state;

typedef enum {
    USER_LED,
    DEBUG_UART_TX,
    DEBUG_UART_RX,
    TOTAL_IO_PINS,
} gpio_pin;

typedef struct
{
    GPIO_PRT_Type *port;
    uint32_t       pin;
    uint8_t        drive_mode;
    uint8_t        hsio; // high speed io matrix/multiplexer
} st_gpioconfig;

#define ARRAY_SIZE sizeof(gpio_configuration_array) / sizeof(st_gpioconfig)

void       gpio_init();
void       gpio_set(gpio_pin pin);
void       gpio_clear(gpio_pin pin);
gpio_state gpio_read(gpio_pin pin);
void       gpio_toggle(gpio_pin pin);

// FreeRTOS Task
void user_led_gpiotask(void *arg);

#endif
