/* ========================================
 *
 * API function definitions for NeoPixel
 * PSOC5 driver component.
 * 
 * Nick Burns (PolyVinalDistillate)
 *
 * ========================================
*/
#include "NP_funcs.h"

volatile void* NP_Start(unsigned int nNumberOfNeopixels, void* pBuffer, double fSpeedMHz)
{
    //work out cycles required at specified clock speed...
    NP_g_pFrameBuffer = NULL;
    if((1.25/(1.0/(fSpeedMHz))) > 255) return NULL;
    
    unsigned char fCyclesTotal = (unsigned char)(1.25/(1.0/(fSpeedMHz)));
    unsigned char fCyclesOn = (unsigned char)(0.7/(1.0/(fSpeedMHz)));
    unsigned char fCyclesOff = (unsigned char)(0.35/(1.0/(fSpeedMHz)));
    
    NP_g_nFrameBufferSize = nNumberOfNeopixels*3;
    //Configure for 19.2 MHz operation
    NP_Neo_BITCNT_Start();        //Counts bits in a byte
    NP_Neo_ONTime_Start();        //Sets number of clocks for logic 1 pulse width
    NP_Neo_OFFTime_Start();       //clocks for logic 0 pulse width
    //Sets bitrate frequency in number of clocks. Must be larger than largest of above two counter periods
    CY_SET_REG8(NP_Neo_DPTH_D1_PTR, fCyclesTotal);
    NP_Neo_OFFTime_WritePeriod(fCyclesOff-1);
    NP_Neo_ONTime_WritePeriod(fCyclesOn-1);
    //Setup a DMA channel
    NP_g_nDMA_Chan = NP_DMA_DmaInitialize(NP_DMA_BYTES_PER_BURST, 
                                                        NP_DMA_REQUEST_PER_BURST, 
                                                        HI16(NP_DMA_SRC_BASE), 
                                                        HI16(NP_DMA_DST_BASE));
    
    if(pBuffer == NULL)
    {
        NP_g_pFrameBuffer = malloc(nNumberOfNeopixels*3);
        if(NP_g_pFrameBuffer != NULL)
        {
            NP_g_bOwnsBuffer = 1;
        }
        else
        {
            NP_g_nFrameBufferSize = 0;
            return NULL;
        }
    }
    else
    {
        NP_g_pFrameBuffer = pBuffer;
        NP_g_bOwnsBuffer = 0;
    }
    return NP_g_pFrameBuffer;
}

//copy frame buffer to LEDs
void NP_Update()
{
    if(NP_g_pFrameBuffer)
    {
        NP_g_nDMA_TD = CyDmaTdAllocate();
        CyDmaTdSetConfiguration(NP_g_nDMA_TD, NP_g_nFrameBufferSize, CY_DMA_DISABLE_TD, TD_INC_SRC_ADR | TD_AUTO_EXEC_NEXT);
        CyDmaTdSetAddress(NP_g_nDMA_TD, LO16((uint32)NP_g_pFrameBuffer), LO16((uint32)NP_Neo_DPTH_F0_PTR));
        CyDmaChSetInitialTd(NP_g_nDMA_Chan, NP_g_nDMA_TD);
        CyDmaChEnable(NP_g_nDMA_Chan, 1);
    }
}

void NP_Stop()
{
    if(NP_g_pFrameBuffer != NULL)
    {
        CyDmaChFree(NP_g_nDMA_Chan);
        CyDmaTdFree(NP_g_nDMA_TD);
        if(NP_g_bOwnsBuffer)
            free((void*)NP_g_pFrameBuffer);
    }
    NP_g_pFrameBuffer = NULL;
}
