/* ========================================
 *
 * API function definitions for NeoPixel
 * PSOC5 driver component.
 * 
 * Nick Burns (PolyVinalDistillate)
 *
 * ========================================
*/
#include "`$INSTANCE_NAME`_funcs.h"

volatile void* `$INSTANCE_NAME`_Start(unsigned int nNumberOfNeopixels, void* pBuffer, double fSpeedMHz)
{
    //work out cycles required at specified clock speed...
    `$INSTANCE_NAME`_g_pFrameBuffer = NULL;
    if((1.25/(1.0/(fSpeedMHz))) > 255) return NULL;
    
    unsigned char fCyclesTotal = (unsigned char)(1.25/(1.0/(fSpeedMHz)));
    unsigned char fCyclesOn = (unsigned char)(0.7/(1.0/(fSpeedMHz)));
    unsigned char fCyclesOff = (unsigned char)(0.35/(1.0/(fSpeedMHz)));
    
    `$INSTANCE_NAME`_g_nFrameBufferSize = nNumberOfNeopixels*3;
    //Configure for 19.2 MHz operation
    `$INSTANCE_NAME`_Neo_BITCNT_Start();        //Counts bits in a byte
    `$INSTANCE_NAME`_Neo_ONTime_Start();        //Sets number of clocks for logic 1 pulse width
    `$INSTANCE_NAME`_Neo_OFFTime_Start();       //clocks for logic 0 pulse width
    //Sets bitrate frequency in number of clocks. Must be larger than largest of above two counter periods
    CY_SET_REG8(`$INSTANCE_NAME`_Neo_DPTH_D1_PTR, fCyclesTotal);
    `$INSTANCE_NAME`_Neo_OFFTime_WritePeriod(fCyclesOff-1);
    `$INSTANCE_NAME`_Neo_ONTime_WritePeriod(fCyclesOn-1);
    //Setup a DMA channel
    `$INSTANCE_NAME`_g_nDMA_Chan = `$INSTANCE_NAME`_DMA_DmaInitialize(`$INSTANCE_NAME`_DMA_BYTES_PER_BURST, 
                                                        `$INSTANCE_NAME`_DMA_REQUEST_PER_BURST, 
                                                        HI16(`$INSTANCE_NAME`_DMA_SRC_BASE), 
                                                        HI16(`$INSTANCE_NAME`_DMA_DST_BASE));
    
    if(pBuffer == NULL)
    {
        `$INSTANCE_NAME`_g_pFrameBuffer = malloc(nNumberOfNeopixels*3);
        if(`$INSTANCE_NAME`_g_pFrameBuffer != NULL)
        {
            `$INSTANCE_NAME`_g_bOwnsBuffer = 1;
        }
        else
        {
            `$INSTANCE_NAME`_g_nFrameBufferSize = 0;
            return NULL;
        }
    }
    else
    {
        `$INSTANCE_NAME`_g_pFrameBuffer = pBuffer;
        `$INSTANCE_NAME`_g_bOwnsBuffer = 0;
    }
    return `$INSTANCE_NAME`_g_pFrameBuffer;
}

//copy frame buffer to LEDs
void `$INSTANCE_NAME`_Update()
{
    if(`$INSTANCE_NAME`_g_pFrameBuffer)
    {
        `$INSTANCE_NAME`_g_nDMA_TD = CyDmaTdAllocate();
        CyDmaTdSetConfiguration(`$INSTANCE_NAME`_g_nDMA_TD, `$INSTANCE_NAME`_g_nFrameBufferSize, CY_DMA_DISABLE_TD, TD_INC_SRC_ADR | TD_AUTO_EXEC_NEXT);
        CyDmaTdSetAddress(`$INSTANCE_NAME`_g_nDMA_TD, LO16((uint32)`$INSTANCE_NAME`_g_pFrameBuffer), LO16((uint32)`$INSTANCE_NAME`_Neo_DPTH_F0_PTR));
        CyDmaChSetInitialTd(`$INSTANCE_NAME`_g_nDMA_Chan, `$INSTANCE_NAME`_g_nDMA_TD);
        CyDmaChEnable(`$INSTANCE_NAME`_g_nDMA_Chan, 1);
    }
}

void `$INSTANCE_NAME`_Stop()
{
    if(`$INSTANCE_NAME`_g_pFrameBuffer != NULL)
    {
        CyDmaChFree(`$INSTANCE_NAME`_g_nDMA_Chan);
        CyDmaTdFree(`$INSTANCE_NAME`_g_nDMA_TD);
        if(`$INSTANCE_NAME`_g_bOwnsBuffer)
            free((void*)`$INSTANCE_NAME`_g_pFrameBuffer);
    }
    `$INSTANCE_NAME`_g_pFrameBuffer = NULL;
}
