#include "screen.h"
#include "math.h"

void line(G& screen, tuple<int,int> start, tuple<int,int> end)
{
    double a1 = (double)get<0>(start);
    double a2 = (double)get<1>(start);

    double b1 = (double)get<0>(end);
    double b2 = (double)get<1>(end);

    double p1 = b1 - a1;
    double p2 = b2 - a2;
    int length = (int)(sqrt(p1*p1 + p2*p2));
    double rad = atan(p2/p1);

    for(int i = 0; i < length; i++)
    {
        screen.drawpixel(a1+cos(rad)*i,a2+sin(rad)*i);
    } 

}

int main(int argc, char* argv[])
{
    G screen;

    line(screen,tuple<int,int>(100,100),tuple<int,int>(300,100));
    line(screen,tuple<int,int>(100,300),tuple<int,int>(300,300));
    line(screen,tuple<int,int>(100,100),tuple<int,int>(100,300));
    line(screen,tuple<int,int>(300,100),tuple<int,int>(300,300));

    screen.update(); 
    screen.input();
    screen.clearpixels();
    SDL_Delay(1000);
    return 0;
}
