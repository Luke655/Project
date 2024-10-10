#ifndef ENGINE_H
#define ENGINE_H

#include "Grid.h"

class Engine {
    public:
        Engine();
        void run();
        ~Engine();

    private:
        int FPS = 60;
        Time dt;
        Particle **particles;
        int count = 0;
};

#endif