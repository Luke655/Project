#ifndef ENGINE_H
#define ENGINE_H

#include "Grid.h"
#include "Button.h"
#include "Slider.h"

class Engine {
    public:
        Engine();
        void run(); // Starts the program.
        ~Engine();

    private:
        float FPS = 60.f;
        Particle **particles;

};

#endif