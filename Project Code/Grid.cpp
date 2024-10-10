#include "Grid.h"

Grid::Grid(Vector2i boundary) {

    this->height = boundary.x;
    this->width = boundary.y;

    cellSize = height / particle.getRadius();
    numCells = height * width / cellSize;
    cells = new Particle*[numCells];
}

Particle* Grid::addParticle() {
    particles[numParticles] = new Particle;
    numParticles++;
    return particles[numParticles - 1];
}

void Grid::removeParticle(Particle p) {
    p.~Particle();
}

Particle** Grid::getParticles() {
    return particles;
}

Particle* Grid::getParticle(int i) {
    return particles[i];
}

int Grid::getNumParticles() {
    return numParticles;
}

Grid::~Grid() {
    delete[] cells;
    delete[] particles;
}

