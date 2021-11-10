#include "screen.h"
#include "math.h"

class Sand{
    public:
    int position_x;
    int position_y; 
    Sand(int x, int y) 
    {
        this->position_x = x;
        this->position_y = y;
    }
};


int main(int argc, char* argv[])
{
    G screen;
    vector<Sand> world; 
    
    //int emitter[2] = {640/2,480/2};
    while(true)
    {
        // Add sand to world
        world.push_back(Sand(320,240));
            

        // Update sand 
        for(auto it = begin(world); it != end(world); ++it) 
        {
            it->position_y += 1;

            // Check collision
            for(auto it2 = begin(world); it2 != end(world); ++it2) 
            {
                if(it2 == it) { continue; }
                
            }
        }

        // Render sand
        for(auto it = begin(world); it != end(world); ++it) 
        {
            screen.drawpixel(it->position_x, it->position_y);
        }

        screen.update();
        SDL_Delay(200);
        screen.input();
        screen.clearpixels();
    }
    return 0;
}

