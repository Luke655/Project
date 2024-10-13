#include "Grid.h"
#include <cmath>

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

void Grid::updateCells() {
    
}

void Grid::checkCollisions(Particle *p1) {


    for (int i = 0; i < numParticles; i++) {
        Particle *p2 = particles[i]; 
        if (p1 != p2) {
            Vector2f distance = p2->getPosition() - p1->getPosition();
            float length = sqrt(distance.x * distance.x + distance.y * distance.y);
            if (length <= p1->getRadius() + p2->getRadius()) {
                p1->setVelocity({-p2->getVelocity().x, -p2->getVelocity().y});
            }
        }
    }
}

Grid::~Grid() {
    delete[] cells;
    delete[] particles;
}

