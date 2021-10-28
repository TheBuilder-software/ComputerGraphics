#include "screen.h"
#include "math.h"

 

// muh line function
void line(G &screen, tuple<float,float,float> start, tuple<float,float,float> end)
{
    // subtract one vector from another get distance
    float s1 = get<0>(start);
    float s2 = get<1>(start);
    float s3 = get<2>(start);

    float e1 = get<0>(end);
    float e2 = get<1>(end);
    float e3 = get<2>(end);

    tuple<float,float,float> endsubstart = tuple<float,float,float>(e1-s1, e2-s2, e3-e3);

    // get angle of the line (rise over run)


}
// muh rotation function


int main(int argc, char* argv[])
{

    vector<tuple<float,float,float>> cube;
    cube.push_back(tuple<float,float,float>(1,1,1)); //  
    cube.push_back(tuple<float,float,float>(2,1,2)); // 
    cube.push_back(tuple<float,float,float>(1,2,1)); // 
    cube.push_back(tuple<float,float,float>(2,1,1)); // 

    G screen;
    float rad = 0;
    float a[2] = {0.0,0.5};
    float height = 55;
    float width = 55;
    
    while(true) {
        for(int j = 0; j < 640; j+=width ) 
            for(int k = 0; k < 480; k+=height) 
                for(int i = 0; i < 55; i++) {
                    
                    int x = (int)(a[0]*i) + j;
                    int y = (int)(a[1]*i) + k;
                    screen.drawpixel(x,y);      
                }
        rad+=0.01;
        a[0] = sin(rad);
        a[1] = cos(rad);

        screen.update(); 
        screen.input();
        screen.clearpixels();
        
        SDL_Delay(16);
        
    }
        
    

    return 0;
}
