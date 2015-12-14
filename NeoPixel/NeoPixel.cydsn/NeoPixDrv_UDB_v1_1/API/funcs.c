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
#include "`$INSTANCE_NAME`_funcs.h"

`$INSTANCE_NAME`_Start()
{
    `$INSTANCE_NAME`_BITCNT_Start();
    `$INSTANCE_NAME`_ONTime_Start();
    `$INSTANCE_NAME`_OFFTime_Start();
    CY_SET_REG8(`$INSTANCE_NAME`_DPTH_D1_PTR, 24);
}

/* [] END OF FILE */
