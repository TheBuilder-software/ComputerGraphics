#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>
#include <time.h>  
#include <vector>
#include <tuple>

#pragma once 

using namespace std;

class G {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_bool done;
    int x;
    int y;
    vector<tuple<int, int>> points;
    SDL_Event event;
    public:
    G() 
    {
       x = 0;
       y = 0;
       SDL_Init(SDL_INIT_VIDEO); 
       SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    }

    void drawpixel(int xm, int ym) 
    {
        tuple<int,int> t = tuple<int,int>(xm,ym);
        points.push_back( t );
    }
    void clearpixels()
    {
        this->points.clear();
    }

    void update() {

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, this->x, this->y);

        for(auto it = begin(this->points); it != end(this->points); ++it) 
        {
            SDL_RenderDrawPoint(renderer, get<0>(*it),get<1>(*it));
        }

        SDL_RenderPresent(renderer);
    }
    void input() {
        while( SDL_PollEvent( &event ) )
        {  
            switch( event.type )
            {
                /* SDL_QUIT event (window close) */
                case SDL_QUIT:
                    SDL_Quit();
                    exit(0);
                    break;

                default:
                    break;
            }
        }
    }

};