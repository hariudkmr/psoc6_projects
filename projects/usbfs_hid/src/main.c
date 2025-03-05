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

#include "cy_usb_dev.h"
#include "cy_usb_dev_audio.h"
#include "cy_usb_dev_cdc.h"
#include "cy_usb_dev_hid.h"

#include "cycfg_usbdev.h"
#include "cycfg.h"

/*******************************************************************************
 * Global constants
 *******************************************************************************/
cy_stc_usbfs_dev_drv_context_t USBHID_context;
cy_stc_usb_dev_context_t       USBHID_devContext;
cy_stc_usb_dev_hid_context_t   USBHID_hidContext;

/*******************************************************************************
 * USBFS interrupts functions and configurations
 *******************************************************************************/
static void USBD_IsrLow(void);
static void USBD_IsrMedium(void);
static void USBD_IsrHigh(void);

const cy_stc_sysint_t USBD_IntrHighConfig = {
    .intrSrc = (IRQn_Type)usb_interrupt_hi_IRQn,
    .intrPriority = 5U,
};
const cy_stc_sysint_t USBD_IntrMeduimConfig = {
    .intrSrc = (IRQn_Type)usb_interrupt_med_IRQn,
    .intrPriority = 6U,
};
const cy_stc_sysint_t USBD_IntrLowConfig = {
    .intrSrc = (IRQn_Type)usb_interrupt_lo_IRQn,
    .intrPriority = 7U,
};

/*******************************************************************************
 * Function Name: USBD_IsrHigh
 *******************************************************************************/
static void USBD_IsrHigh(void)
{
    /* Call interrupt processing */
    Cy_USBFS_Dev_Drv_Interrupt(USBHID_HW, Cy_USBFS_Dev_Drv_GetInterruptCauseHi(USBHID_HW),
                               &USBHID_context);
}
/*******************************************************************************
 * Function Name: USBD_IsrMedium
 *******************************************************************************/
static void USBD_IsrMedium(void)
{
    /* Call interrupt processing */
    Cy_USBFS_Dev_Drv_Interrupt(USBHID_HW, Cy_USBFS_Dev_Drv_GetInterruptCauseMed(USBHID_HW),
                               &USBHID_context);
}
/*******************************************************************************
 * Function Name: USBD_IsrLow
 *******************************************************************************/
static void USBD_IsrLow(void)
{
    /* Call interrupt processing */
    Cy_USBFS_Dev_Drv_Interrupt(USBHID_HW, Cy_USBFS_Dev_Drv_GetInterruptCauseLo(USBHID_HW),
                               &USBHID_context);
}

/**
 * Main entry point of the program.
 */
int main(void)
{

    cy_en_usb_dev_status_t status;
    init_cycfg_all();

    /* Initialize USB */
    status = Cy_USB_Dev_Init(USBHID_HW, &USBHID_config, &USBHID_context, &usb_devices[0],
                             &usb_devConfig, &USBHID_devContext);
    if (CY_USB_DEV_SUCCESS != status) {
        /* Initialization error - stop execution */
        while (1)
            ;
    }
    status = Cy_USB_Dev_HID_Init(&usb_hidConfig, &USBHID_hidContext, &USBHID_devContext);
    if (CY_USB_DEV_SUCCESS != status) {
        /* HID Initialization error - stop execution */
        while (1)
            ;
    }
    /* Hook interrupt service routines */
    (void)Cy_SysInt_Init(&USBD_IntrLowConfig, &USBD_IsrLow);
    (void)Cy_SysInt_Init(&USBD_IntrMeduimConfig, &USBD_IsrMedium);
    (void)Cy_SysInt_Init(&USBD_IntrHighConfig, &USBD_IsrHigh);

    /* Enable interrupts */
    NVIC_EnableIRQ((IRQn_Type)USBD_IntrLowConfig.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)USBD_IntrMeduimConfig.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)USBD_IntrHighConfig.intrSrc);

    /* Enable interrupts */
    __enable_irq();

    Cy_USB_Dev_Connect(true, CY_USB_DEV_WAIT_FOREVER, &USBHID_devContext);

    const uint32_t CURSOR_X_POS = 1UL;
    const uint32_t MOUSE_DATA_LEN = 3UL;
    const uint32_t MOUSE_IN_EP = 1UL;
    const uint8_t  CURSOR_STEP = 5U;
    const uint32_t STEPS_NUMBER = 96UL;
    uint8_t        counter = 0U;
    bool           moveRight = true;
    /* Mouse packet array: buttons (1st byte), X (2nd byte), Y (3rd byte) */
    CY_USB_DEV_ALLOC_ENDPOINT_BUFFER(mouseData, 3U);

    mouseData[2U] = 0U; /* No changes in Y - position */
    for (;;) {
        /* Move mouse to the right or to the left appropriate number of steps */
        mouseData[CURSOR_X_POS] = moveRight ? CURSOR_STEP : (uint8_t)-CURSOR_STEP;
        /* Define direction of the movement */
        if (0U == counter) {
            counter = STEPS_NUMBER;
            moveRight = !moveRight;
        }
        /* Update mouse position */
        Cy_USB_Dev_WriteEpBlocking(MOUSE_IN_EP, mouseData, MOUSE_DATA_LEN, CY_USB_DEV_WAIT_FOREVER,
                                   &USBHID_devContext);
        counter--;
        Cy_SysLib_Delay(10UL);
    }
}

/* [] END OF FILE */
