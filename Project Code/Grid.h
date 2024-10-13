#ifndef GRID_H
#define GRID_H

#include "Particle.h"

class Grid {
    public:
        Grid(Vector2i boundary);
        ~Grid();

        Particle *addParticle(); // Adds a particle to the 'particles' array.
        void removeParticle(Particle p); // Removes a particle from the 'particles' array.
        Particle **getParticles(); // Returns the 'particles' array.
        int getNumParticles(); // Returns the number of particles in the 'particles' array.
        Particle *getParticle(int i); // Returns the ith particle in the 'particles' array.
        void updateCells(); // Updates the cells to add/remove particles.
        void checkCollisions(Particle *p1); // Checks the collisions between particles.

    private:
        float height;
        float width;
        float cellSize;

        Particle particle;
        int numParticles = 0;
        int numCells;
        Particle **particles = new Particle*[100];
        Particle **cells;

};

#endif