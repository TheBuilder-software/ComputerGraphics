#include "screen.h"

/*
Le print pixel class
Le drawpixel(x,y) draw pixel at point x,y
Le input() exits if you want to exit
Le update() draws pixels to screen
Le clearpixels() clears pixels from screen
*/

int main()
{
    G screen;

    for(int k = 25; k > 0; k--) 
    {
        for(int i = 0; i < 640; i++) 
        {
            for(int j = 0; j < 480; j++ ) 
            {
                if(i%k==0 && j%k==0 ) 
                {
                    screen.drawpixel(i,j);
                }     
            }
        }
        screen.update(); 
        screen.input();
        screen.clearpixels();
        SDL_Delay(250);
        
    }
    return 0;
}
