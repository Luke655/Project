#ifndef ENGINE_H
#define ENGINE_H

#include "Particle.h"

class Engine {
    public:
        Engine();
        Particle* addParticle();
        void removeParticle(Particle p);
        void run();
        ~Engine();

    private:
        int FPS = 60;
        Time dt;

        Particle** particles;
        int count = 0;
};

#endif