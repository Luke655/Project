#ifndef ENGINE_H
#define ENGINE_H

#include "Grid.h"
#include "Button.h"

class Engine {
    public:
        Engine();
        void run();
        ~Engine();

    private:
        float FPS = 60.f;
        Time dt;
        Particle **particles;
};

#endif