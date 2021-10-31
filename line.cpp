#include "math.h"
#include "screen.h"
#include "drawing.h"

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
