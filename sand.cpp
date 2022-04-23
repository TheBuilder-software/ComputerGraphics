#include "screen.h"
#include "math.h"
using namespace std;
class Sand{
    public:
    int position_x;
    int position_y; 
    int id;
    int y_move_dir;
    int x_move_dir;
    Sand(int x, int y, int sid) 
    {
        position_x = x;
        position_y = y;
        id = sid;
        y_move_dir = 1;
        x_move_dir = 0;
    }

};

bool isColliding(Sand& s, std::vector<Sand>& world)
{
    if(s.position_y > 350) return true;

    for(Sand& sand : world)
    {
        
        if( sand.position_x == s.position_x && 
            sand.position_y == s.position_y && 
            sand.id != s.id)
        {
            return true;
        }
            
    }
    return false;
}
void random_move(Sand& s)
{
    int d = rand() % 4;


    switch(d)
    {
        case 0:
        s.position_x += 1;
        break;
        case 1:
        s.position_x -= 1;
        break;
        case 3:
        s.position_y += 1;
        break;
        case 4: 
        s.position_y -= 1;
        break;
    }

}

int main()
{
    G screen;
    vector<Sand> world; 

    int id = 0;
    while(true)
    {
        // Add sand to world
        if(rand()%2 == 0)
        {
            world.emplace_back(320,240,id);
            id = rand();
        }

        for(Sand& s : world)
        {

            // down
            s.position_y += 1;
            if(isColliding(s,world))
            {
                s.position_y -= 1;
            }
            else 
            {
                continue;
            }
            if(rand()%2==0) 
            {
                // down left
                s.position_y += 1;
                s.position_x -= 1;
                if(isColliding(s,world))
                {
                    s.position_y -= 1;
                    s.position_x += 1;
                } 
                else 
                {
                    continue;
                }
            }
            else 
            {
                // down right
                s.position_y += 1;
                s.position_x += 1;
                if(isColliding(s,world))
                {
                    s.position_y -= 1;
                    s.position_x -= 1;
                } 
                else 
                {
                    continue;
                }
            }
        }
        // Render sand
        for(auto& s: world)
            screen.drawpixel(s.position_x,s.position_y);

        screen.update();
        SDL_Delay(20);
        screen.input();
        screen.clearpixels();
    }
    return 0;
}

