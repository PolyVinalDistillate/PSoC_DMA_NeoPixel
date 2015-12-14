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
#define Neo_DMA_BYTES_PER_BURST 1
#define Neo_DMA_REQUEST_PER_BURST 1
#define Neo_DMA_SRC_BASE (CYDEV_SRAM_BASE)
#define Neo_DMA_DST_BASE (CYDEV_PERIPH_BASE)
uint8 Neo_DMA_Chan;
uint8 Neo_DMA_TD;

/* [] END OF FILE */
