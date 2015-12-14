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
#include "NP_Neo_defs.h"
#include "NP_Neo_BITCNT.h"
#include "NP_Neo_OFFTime.h"
#include "NP_Neo_ONTime.h"
#include "NP_DMA_DMA.h"
#include "malloc.h"

//DMA declarations
#define NP_DMA_BYTES_PER_BURST 1
#define NP_DMA_REQUEST_PER_BURST 1
#define NP_DMA_SRC_BASE (CYDEV_SRAM_BASE)
#define NP_DMA_DST_BASE (CYDEV_PERIPH_BASE)
unsigned int NP_g_nNumberOfPixels;
uint8 NP_g_nDMA_Chan;
uint8 NP_g_nDMA_TD;
uint8 NP_g_bOwnsBuffer;
//Frame buffer vars
volatile uint8* NP_g_pFrameBuffer;
unsigned int NP_g_nFrameBufferSize;

//API Functions:

//Initialise Neopixel driver component
//nNumberOfPixels: Number of NeoPixel LEDs chained together
//pBuffer: User supplied char buffer (3*nNumberOfPixels in size) or NULL 
//fSpeedMHz: Speed of clock supplied to component
//Return value: Either pointer to user supplied buffer, pointer to own allocated buffer (if pBuffer = NULL) or NULL on fail
volatile void* NP_Start(unsigned int nNumberOfNeopixels, void* pBuffer, double fSpeedMHz);

//Copy "frame buffer" to LEDs. Updates LED chain with contents of buffer
void NP_Update();

//Cleanup Neopixel driver component (not *sure* I'm cleaning up the DMA correctly!)
void NP_Stop();
