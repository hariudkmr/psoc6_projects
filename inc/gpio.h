/*
 ============================================================================
 Name        : gpio.h
 Author      : Hari Udayakumar
 Version     : 1.0
 Copyright   : n.a.
 Description : Sumobot based on PSOC6
 ============================================================================*/

/**
 * @file gpio.h
 * @author Hari Udayakumar
 * @date 07-07-2024
 */

#ifndef GPIO_H
#define GPIO_H

#include "cy_pdl.h"
#include <string.h>
#include <assert.h>

typedef enum {
    IO_LOW,
    IO_HIGH,
} gpio_state;

typedef enum {
    LED9,
    LED8,
    TOTAL_IO_PINS,
} gpio_pin;

typedef struct
{
    GPIO_PRT_Type *port;
    uint32_t       pin;
} st_gpioconfig;

#define ARRAY_SIZE sizeof(gpio_configuration_array) / sizeof(st_gpioconfig)

/** \fn     GPIO Write
    \brief  Controls the GPIO State using the below functions.
    \param  gpio_pin pin -> Index of the GPIO Configuration in GPIO
    \param  gpio_state state -> State of the GPIO pin
    \return no return value
*/
void gpio_write(gpio_pin pin, gpio_state state);

/** \fn     GPIO Read
    \brief  Reads the state of the GPIO PIN using the below functions.
    \param  gpio_pin pin -> Index of the GPIO Configuration in st_gpioconfig structure array
    \return -> State of the GPIO pin
*/
gpio_state gpio_read(gpio_pin pin);

/** \fn     GPIO Toggle
    \brief  Toggles the stato of GPIO pin using the below functions.
    \param  gpio_pin pin -> Index of the GPIO Configuration in GPIO
    \return no return value
*/
void gpio_toggle(gpio_pin pin);

/** \fn     user_led_gpiotask(void *arg)
    \brief  Toggle User Led using RTOS Task.
*/
void user_led_gpiotask(void *arg);

/** \fn     user_led8_gpiotask(void *arg)
    \brief  Toggle User Led using RTOS Task.
*/
void user_led8_gpiotask(void *arg);

#endif
