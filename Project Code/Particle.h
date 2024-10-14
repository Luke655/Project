#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/Graphics.hpp"
using namespace sf;

class Particle: public Transformable {
    public:
        Particle();
        ~Particle();

        CircleShape getShape();
        Vector2f getPosition();
        Vector2f getVelocity();
        Vector2f getForce();
        float getRadius();

        void setPosition(Vector2f pos);
        void setVelocity(Vector2f v);
        void setRadius(float r);

        void update(float FPS); // Updates the particle for the given dt frame.
        void applyForce(Vector2f force); // Applies a force in some direction on the particle.
        void checkBoundary(Vector2f bounds); // Checks particle-boundary collisions.

    private:
        Vector2f position;
        Vector2f velocity;
        Vector2f netForce;
        float mass;

        float radius = 5.f;
        CircleShape p;
};

#endif