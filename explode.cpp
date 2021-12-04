#include "screen.h"
#include "math.h"

class Sand{

public:
    float position_x;
    float position_y; 
    int alivefor;
    float direction_x;
    float direction_y;
    float velocity;
    int id = 0;
    Sand(float x, float y, int life, float dx, float dy, float vel,int uid) 
    {
        this->position_x = x;
        this->position_y = y;
        this->alivefor = life;
        this->direction_x = dx;
        this->direction_y = dy;
        this->velocity = vel;
        this->id = uid;
    }
    void update()
    {
        this->position_x +=  (this->direction_x * this->velocity);
        this->position_y +=  (this->direction_y * this->velocity);

        if(this->position_x > 640 || this->position_x < 0)
            this->direction_x = -(this->direction_x);

        if(this->position_y > 480 || this->position_y < 0)
            this->direction_y = -(this->direction_y);

        if(this->alivefor > 0)
        {
            this->alivefor-=1;
        }
    }
    bool isalive()
    {
        return this->alivefor > 0;
    }

};

class Explosion{
    public:
    float position_x;
    float position_y;
    int life;
    int size;
    int id;
    G* screen;
    Explosion(float x, float y, int lifetime, int uid, G* scr):
    position_x(x),
    position_y(y),
    life(lifetime),
    id(uid),
    screen(scr){}

    void update()
    {
        if(this->life > 0) {
            float d = 0.0;
            for(int i = 0; i < 63; i++) 
            {
                this->screen->drawpixel(
                    sin(d) * this->size + this->position_x, 
                    cos(d) * this->size + this->position_y
                );
                d+=0.1;
            }
            this->size += 1;
            this->life -= 1;
        }
    }

};

bool areColiding(Sand& rhs, Sand& lhs)
{
    if( (int)rhs.position_y == (int)lhs.position_y &&
        (int)rhs.position_x == (int)lhs.position_x &&
        lhs.id != rhs.id
    )
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main(int argc, char* argv[])
{
    G screen;
    vector<Sand> world; 
    vector<Explosion> world_explosions;
    // create all particles with random values
    //
    for(int i = 0; i < 100; i++)
        world.push_back(Sand(
           rand()%640,
           rand()%480,
           -1,
           sin(rand()),
           cos(rand()), 
           ((float)(rand() % 100) )/55,
           i )           
        );
    
    while(true)
    {
        for(auto& w : world) 
        {
            screen.drawpixel(w.position_x, w.position_y);
            if(w.velocity > 0)
            {
                w.update();
            }
        }
        for(auto& w : world_explosions) 
        {
            w.update();
        }

        // process particles
        for(auto& w : world) 
            for(auto& m : world)
                if((m.velocity > 0 || w.velocity > 0) && areColiding(m,w))
                {
                    for(int i = 0; i < 665; i++)
                    {
                        world_explosions.push_back(Explosion(
                            w.position_x,w.position_y,60,rand(),&screen
                        ));
                    }
                    m.velocity = 0;
                    w.velocity = 0;
                }

        // process explosions


        screen.update();
        SDL_Delay(20);
        screen.input();
        screen.clearpixels();
    }
    return 0;
}

