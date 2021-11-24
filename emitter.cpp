#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ratio>

#include "screen.h"
#include "math.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;

class Particle {
public:
    high_resolution_clock::time_point creation_time;
    float direction;
    float velocity;

    Particle() :
        creation_time(high_resolution_clock::now()),
        direction(2 * M_PI * rand() / RAND_MAX),
        velocity(rand() % 100) {};

    void draw(G &screen) {
        float distance =
            duration<float>(high_resolution_clock::now() - creation_time).count() * velocity;

        if (distance < 0)
            return;

        screen.drawpixel(
            static_cast<int>(distance * sin(direction) + 320),
            static_cast<int>(distance * cos(direction) + 240)
        );

        if (distance > 400)
            creation_time = high_resolution_clock::now();
    }
};

int main(int argc, char* argv[])
{
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
        screen.clearpixels();
        SDL_Delay(16);
    }
    return 0;
}
