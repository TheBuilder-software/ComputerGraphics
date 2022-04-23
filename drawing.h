#include "screen.h"
#pragma once 

void line(G& screen, std::tuple<int,int> start, std::tuple<int,int> end)
{
    double a1 = (double)std::get<0>(start);
    double a2 = (double)std::get<1>(start);

    double b1 = (double)std::get<0>(end);
    double b2 = (double)std::get<1>(end);

    // difference between two points
    double p1 = b1 - a1;
    double p2 = b2 - a2;

    // length of point
    int length = (int)(sqrt(p1*p1 + p2*p2));
    
    // angle 
    double rad = atan2(p2,p1);
    for(int i = 0; i < length; i++)
    {
        screen.drawpixel( static_cast<int>(a1+cos(rad)) * i, static_cast<int>(a2+sin(rad)) * i );
    } 

}
