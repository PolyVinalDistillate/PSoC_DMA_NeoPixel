/* ========================================
 *
 * API function declarations, variables and
 * preproc definitions for NeoPixel PSOC5 
 * driver component.
 * 
 * Nick Burns (PolyVinalDistillate)
 *
 * ========================================
*/
#include "`$INSTANCE_NAME`_Neo_defs.h"
#include "`$INSTANCE_NAME`_Neo_BITCNT.h"
#include "`$INSTANCE_NAME`_Neo_OFFTime.h"
#include "`$INSTANCE_NAME`_Neo_ONTime.h"
#include "`$INSTANCE_NAME`_DMA_DMA.h"
#include "malloc.h"

//DMA declarations
#define `$INSTANCE_NAME`_DMA_BYTES_PER_BURST 1
#define `$INSTANCE_NAME`_DMA_REQUEST_PER_BURST 1
#define `$INSTANCE_NAME`_DMA_SRC_BASE (CYDEV_SRAM_BASE)
#define `$INSTANCE_NAME`_DMA_DST_BASE (CYDEV_PERIPH_BASE)
unsigned int `$INSTANCE_NAME`_g_nNumberOfPixels;
uint8 `$INSTANCE_NAME`_g_nDMA_Chan;
uint8 `$INSTANCE_NAME`_g_nDMA_TD;
uint8 `$INSTANCE_NAME`_g_bOwnsBuffer;
//Frame buffer vars
volatile uint8* `$INSTANCE_NAME`_g_pFrameBuffer;
unsigned int `$INSTANCE_NAME`_g_nFrameBufferSize;

//API Functions:

//Initialise Neopixel driver component
//nNumberOfPixels: Number of NeoPixel LEDs chained together
//pBuffer: User supplied char buffer (3*nNumberOfPixels in size) or NULL 
//fSpeedMHz: Speed of clock supplied to component
//Return value: Either pointer to user supplied buffer, pointer to own allocated buffer (if pBuffer = NULL) or NULL on fail
volatile void* `$INSTANCE_NAME`_Start(unsigned int nNumberOfNeopixels, void* pBuffer, double fSpeedMHz);

//Copy "frame buffer" to LEDs. Updates LED chain with contents of buffer
void `$INSTANCE_NAME`_Update();

//Cleanup Neopixel driver component (not *sure* I'm cleaning up the DMA correctly!)
void `$INSTANCE_NAME`_Stop();
