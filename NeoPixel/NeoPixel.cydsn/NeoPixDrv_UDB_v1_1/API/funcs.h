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

//DMA declarations
#define `$INSTANCE_NAME`_DMA_BYTES_PER_BURST 1
#define `$INSTANCE_NAME`_DMA_REQUEST_PER_BURST 1
#define `$INSTANCE_NAME`_DMA_SRC_BASE (CYDEV_SRAM_BASE)
#define `$INSTANCE_NAME`_DMA_DST_BASE (CYDEV_PERIPH_BASE)
uint8 `$INSTANCE_NAME`_DMA_Chan;
uint8 `$INSTANCE_NAME`_DMA_TD;

/* [] END OF FILE */
