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
#include "Neo_funcs.h"

Neo_Start()
{
    Neo_BITCNT_Start();
    Neo_ONTime_Start();
    Neo_OFFTime_Start();
    CY_SET_REG8(Neo_DPTH_D1_PTR, 24);
}

/* [] END OF FILE */
