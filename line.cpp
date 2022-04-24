#include "math.h"
#include "screen.h"
#include "drawing.h"

int main()
{
    G screen;

    line(screen,std::tuple<int,int>(100,100),std::tuple<int,int>(300,100));
    line(screen,std::tuple<int,int>(100,300),std::tuple<int,int>(300,300));
    line(screen,std::tuple<int,int>(100,100),std::tuple<int,int>(100,300));
    line(screen,std::tuple<int,int>(300,100),std::tuple<int,int>(300,300));
    
    screen.update(); 
    screen.input();
    screen.clearpixels();
    SDL_Delay(1000);

    return 0;
}
