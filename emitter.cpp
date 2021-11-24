#include "screen.h"
#include "math.h"

int main(int argc, char* argv[])
{
    G screen;

    int total = 0;
    int limit = 5000;
    float directions[5000][4];
    for(int i = 0; i < 5000; i++)
            directions[i][2] = 1;
    while(true) 
    {
        if(total < limit && directions[total][2] == 1)
        {   
            // add a new direction
            directions[total][0] = sin(rand());
            directions[total][1] = cos(rand());
            directions[total][2] = 1; // distance
            directions[total][3] = 0.1*(float)(rand()%10);
            total +=1;
        }
        // reset extended particles
        for(int i = 0; i < total; i++)
            if(directions[i][2] > 400)
                directions[i][2]=1;
        // draw all particles
        for(int i = 0; i < total; i++)
        {
            float x = directions[i][0] * directions[i][2] + (640/2);
            float y = directions[i][1] * directions[i][2] + (480/2);
            screen.drawpixel((int)x,(int)y);
        }
        // increase all particle distance by 1
        for(int i = 0; i < total; i++)
        {
            directions[i][2] += directions[i][3];
        }

        screen.update(); 
        screen.input();
        screen.clearpixels();
        SDL_Delay(16);
        
    }
    return 0;
}
