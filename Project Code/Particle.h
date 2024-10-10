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
        void setColor(float v);

        void setPosition(Vector2f pos);
        void setVelocity(Vector2f v);
        void setRadius(float r);

        void update(Time dt);
        void applyForce(Vector2f force); 
        void checkBoundary(Vector2i bounds);

    private:
        Vector2f position;
        Vector2f velocity;
        Vector2f netForce;
        float mass;

        float radius = 2.f;
        CircleShape p;
};

#endif