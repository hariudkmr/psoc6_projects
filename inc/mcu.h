#ifndef MCU_INIT_H
#define MCU_INIT_H

#include "cy_pdl.h"
#include "system_psoc6.h"
#include "cy_device.h"

#define DWT_CTRL        0xE0001000 ///< DWT Control Register Address
#define DWT_CYCLE_COUNT 0xE0001004 ///< DWT Count Register Address

void system_clk_init(void);
void dwt_init(void);

#endif
