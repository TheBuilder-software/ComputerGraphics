#include "screen.h"
#include "math.h"
#include "drawing.h"

/*
150 is the centroid of this cube to get the centroid add up every value alone the x then
divide by the number of values, do this for y and z to get he centroid, 
this cubes centroid was 150, 150, 150 so I subtracted it from the point then added after the rotation
*/

void rotate_x(float rad, float* point)
{
    // Center rotation
    point[0] -= 150;
    point[1] -= 150;
    point[2] -= 150;
 
    float x_1 = point[0];
    float x_2 = (cos(rad) * point[1])  - ((sin(rad) * point[2]));
    float x_3 = (sin(rad) * point[1])  + ((cos(rad) * point[2]));

    // Center rotation
    point[0] = x_1+150;
    point[1] = x_2+150;
    point[2] = x_3+150;
}
void rotate_y(float rad, float* point)
{
    // Center rotation
    point[0] -= 150;
    point[1] -= 150;
    point[2] -= 150;

    float x_1 = (cos(rad) * point[0]) + sin(rad) * point[2] ;
    float x_2 = point[1];
    float x_3 = -(sin(rad)*point[0]) + cos(rad)*point[2];

    // Center rotation
    point[0] = x_1+150;
    point[1] = x_2+150;
    point[2] = x_3+150;
}
void rotate_z(float rad, float* point)
{
    // Center rotation
    point[0] -= 150;
    point[1] -= 150;
    point[2] -= 150;
    
    // Rot z
    float x_1 = (cos(rad) * point[0]) - (sin(rad)) * point[1] ;
    float x_2 = (sin(rad) * point[0])  + ((cos(rad) * point[1])) ;
    float x_3 = point[2];

    // Center rotation
    point[0] = x_1+150;
    point[1] = x_2+150;
    point[2] = x_3+150;
}

int main()
{
    G screen;

    int center[3] = {150,150,1};

    float cube[8][3] = {
        {100,100,100},
        {200,100,100},
        {200,200,100},
        {100,200,100},
        {100,100,200},
        {200,100,200},
        {200,200,200},
        {100,200,200},
    };

    while(true)
    {
        for(int i = 0; i < 8; i++)
        {
            rotate_x(0.001f,cube[i]);
            rotate_y(0.01f,cube[i]);
            rotate_z(0.001f,cube[i]);
            screen.drawpixel((int)cube[i][0] + center[0],(int)cube[i][1]+ center[1]);
        }
        screen.update(); 
        screen.input();
        screen.clearpixels();
        SDL_Delay(16);
    }


        
    return 0;
}