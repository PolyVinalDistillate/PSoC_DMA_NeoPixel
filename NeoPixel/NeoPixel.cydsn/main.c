//PSOC5 (Project target = CY8C5888LTI-LP097) minimal example for NeoPixel component
//Nick Burns (PolyVinalDistillate)
#include <project.h>
#include "math.h"
//Allocate an array for 16 NeoPixels
unsigned char pPixelArray[16*3];
//Set up some variables for animation code
float power = 1;
float Deltapower = 0.005;
float offset = 0;
//Main function
int main()
{
    //Start the NeoPixel component (16 pix, User array, 12.8 MHz base clock)
    NP_Start(16, pPixelArray, 12.8);
    //Endless loop...
    for(;;)
    {      
        int i;
        for(i = 0; i < 16; i++) //Update each of the 16 pixels in turn here
        {
            //Compute Green Component
            pPixelArray[i*3] = (unsigned int)255.0 * pow(((1.0+sin(offset+(2.0*3.14159267/16.0)*((float)i+5.333)))/2), power);
            //Compute Red Component
            pPixelArray[1+i*3] = (unsigned int)255.0 * pow(((1.0+sin(offset+(2.0*3.14159267/16.0)*((float)i+10.667)))/2), power);
            //Compute Blue Component
            pPixelArray[2+i*3] = (unsigned int)255.0 * pow(((1.0+sin(offset+(2.0*3.14159267/16.0)*(float)i))/2), power);
        }
        //Call NeoPixel update function (non blocking) to trigger DMA pixel update
        NP_Update();
        //Update animation vars
        offset+=0.2;
        power+=Deltapower;
        if((power > 10) || (power < 0.1)) Deltapower = -Deltapower;

       //Delay before next frame
        CyDelay(5);
    }
}
