#include "screen.h"
#include "math.h"

int main()
{
    G screen;
    float rad = 0;
    float a[2] = {0.0,0.5};
    float height = 100;
    float width = 100;
    
    while(true) {
        for(float j = 0; j < 640; j+=width ) 
            for(float k = 0; k < 480; k+=height) 
                for(float i = 0; i < 100; i++) {
                    
                    int x = static_cast<int>((a[1]*i) + j);
                    int y = static_cast<int>((a[0]*i) + k);
                    
                    screen.drawpixel(x,y); 
                }
        rad+=0.005f;
        //a[0] = sin(rad);
        a[1] = cos(rad);

        screen.update(); 
        screen.input();
        screen.clearpixels();
        
        SDL_Delay(16);
        
    }
        
    

    return 0;
}
