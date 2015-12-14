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
#include "NeoPixel_1_funcs.h"

NeoPixel_1_Start()
{
    NeoPixel_1_Neo_BITCNT_Start();
    NeoPixel_1_Neo_ONTime_Start();
    NeoPixel_1_Neo_OFFTime_Start();
    CY_SET_REG8(NeoPixel_1_Neo_DPTH_D1_PTR, 24);
}

/* [] END OF FILE */
