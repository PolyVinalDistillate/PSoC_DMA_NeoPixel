/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "cytypes.h"

//DMA declarations
#define NeoPixel_1_DMA_BYTES_PER_BURST 1
#define NeoPixel_1_DMA_REQUEST_PER_BURST 1
#define NeoPixel_1_DMA_SRC_BASE (CYDEV_SRAM_BASE)
#define NeoPixel_1_DMA_DST_BASE (CYDEV_PERIPH_BASE)
uint8 NeoPixel_1_DMA_Chan;
uint8 NeoPixel_1_DMA_TD;

/* [] END OF FILE */
