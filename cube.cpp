#include "screen.h"
#include "drawing.h"
#include "math.h"


void square(G& screen, int position_x, int position_y, int size)
{
    line(screen,std::tuple<int,int>(position_x,position_y),     std::tuple<int,int>(position_x+size,position_y));
    line(screen,std::tuple<int,int>(position_x,position_y+size),std::tuple<int,int>(position_x+size+1,position_y+size));
    line(screen,std::tuple<int,int>(position_x,position_y),     std::tuple<int,int>(position_x,position_y+size));
    line(screen,std::tuple<int,int>(position_x+size,position_y),std::tuple<int,int>(position_x+size,position_y+size));

}

int main()
{
    G screen;

    for(int i = 100; i < 640; i+=90)
    {
        for(int k = 75; k < 480; k+=96)
        {
            for(int j = 80; j > 1; j-=10) 
            {
                square(screen,i-(j/2),k-(j/2),j);
                screen.update();
                SDL_Delay(50);
                screen.input();
            }
        }
    }
    SDL_Delay(1000);
    screen.clearpixels();

    return 0;
}

