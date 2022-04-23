#include "screen.h"
#include "math.h"

int main()
{
    G screen;
    float rad = 0;
    float a[2] = {0.0,0.5};
    int height = 55;
    int width = 55;
    
    while(true) {
        for(int j = 0; j < 640; j+=width ) 
            for(int k = 0; k < 480; k+=height) 
                for(int i = 0; i < 55; i++) {
                    
                    int x = (int)(a[0] * static_cast<float>(i) ) + j;
                    int y = (int)(a[1] * static_cast<float>(i) ) + k;
                    screen.drawpixel(x,y);      
                }
        rad+=0.01f;
        a[0] = sin(rad);
        a[1] = cos(rad);

        screen.update(); 
        screen.input();
        screen.clearpixels();
        
        SDL_Delay(16);
        
    }
        
    

    return 0;
}
