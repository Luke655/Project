#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/Graphics.hpp"
using namespace sf;

class Particle: public Transformable {
    public:
        Particle();
        ~Particle();

        CircleShape getShape(); // Returns the circle shape of the particle.
        Vector2f getPosition(); // Returns the position.
        Vector2f getVelocity(); // Returns the velocity.
        Vector2f getForce(); // Returns the net force of the particle.
        float getRadius(); // Returns the radius of the particle.

        void setPosition(Vector2f pos); // Changes the position of the particle.
        void setVelocity(Vector2f v); // Changes the velocity of the particle.
        void setRadius(float r); // Changes the radius of the particle.

        void update(float FPS); // Updates the particle for the given dt frame.
        void applyForce(Vector2f force); // Applies a force in some direction on the particle.
        void checkBoundary(RectangleShape boundary); // Checks particle-boundary collisions.

    private:
        Vector2f position;
        Vector2f velocity;
        Vector2f acceleration;
        Vector2f netForce;
        float mass;

        float radius = 5.f;
        CircleShape p;
};

#endif