#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ratio>
#include <algorithm>
#include <numeric>
#include "screen.h"
#include "math.h"

using namespace std::chrono_literals;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

class Particle {
public:
    high_resolution_clock::time_point creation_time;
    float direction;
    float velocity;
    Particle() :
        creation_time(high_resolution_clock::now()),
        direction( static_cast<float>(2 * M_PI * rand() / RAND_MAX)),
        velocity( static_cast<float>(rand() % 100)) {};

    void draw(G &screen) {

        auto now = high_resolution_clock::now();
        float distance = duration<float>(now - creation_time).count() * velocity;

        if (distance < 0)
            return;

        screen.drawpixel(
            static_cast<int>(distance * sin(direction) + 320),
            static_cast<int>(distance * cos(direction) + 240)
        );

        // Reset particle
        //
        if (distance > 400)
        {
            creation_time = high_resolution_clock::now();
            velocity = static_cast<float>(rand() % 100);
        }
    }
    void update()
    {
    }
};

int main()
{
    G* screen2 = new G;
    screen2->drawpixel(1,1);
    G screen;
    std::array<Particle, 5000> particles;

    for(auto offset = 0ms; auto& p: particles)
        p.creation_time += offset += 15ms;
    
    while(true) 
    {

        for(auto& p: particles)
            p.draw(screen);


        screen.update(); 
        screen.input();
        screen2->input();
        screen.clearpixels();
        SDL_Delay(16);
    }
    return 0;
}
