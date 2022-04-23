#include "screen.h"
#include "math.h"

int main()
{
    G screen;

    while(true) 
    {
        for(int i = 1; i < 100; i+=1) 
        {
            for(int j = 0; j < 640; j+=1 ) 
                for(int k = 0; k < 480; k+=i) 
                    screen.drawpixel(j,k);      

            for(int j = 0; j < 640; j+=i ) 
                for(int k = 0; k < 480; k+=1) 
                    screen.drawpixel(j,k);  

            screen.update(); 
            screen.input();
            screen.clearpixels();
            SDL_Delay(20);
        
        }
        for(int i = 100; i > 1; i-=1) 
        {
            for(int j = 0; j < 640; j+=1 ) 
                for(int k = 0; k < 480; k+=i) 
                    screen.drawpixel(j,k);      

            for(int j = 0; j < 640; j+=i ) 
                for(int k = 0; k < 480; k+=1) 
                    screen.drawpixel(j,k);  

            screen.update(); 
            screen.input();
            screen.clearpixels();
            SDL_Delay(20);
        
        }
        
    }
        
    

    return 0;
}
