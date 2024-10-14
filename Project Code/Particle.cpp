#include "Particle.h"

Particle::Particle() { 

    setOrigin(radius, radius);
    position = {0,0};
    velocity = {0,0};
    mass = 1;
    p.setRadius(radius);
    p.setFillColor(Color::White);
}

CircleShape Particle::getShape() {
    return p;
}

Vector2f Particle::getPosition() {
    return position;
}

void Particle::setPosition(Vector2f pos) {
    position = {pos.x , pos.y};
    p.setPosition(position);
}

Vector2f Particle::getVelocity() {
    return velocity;
}

void Particle::setVelocity(Vector2f v) {
    velocity = v;
}

float Particle::getRadius() {
    return radius;
}

void Particle::setRadius(float r) {
    radius = r;
}

Vector2f Particle::getForce() {
    return netForce;
}

void Particle::applyForce(Vector2f force) {
    netForce += force;
}

void Particle::update(float FPS) {

    velocity += netForce * mass / FPS;
    position += velocity / FPS;

    p.setPosition(position);

    netForce = {0,0};
}

void Particle::checkBoundary(Vector2f boundary) {

        if (position.x <= 0 || position.x + 2*radius >= boundary.x) {
            velocity.x *= -1;
            if (position.x >= boundary.x) {
                position.x += boundary.x - position.x + radius;
            } else if (position.x <= 0) {
                position.x += 0.f -position.x + radius;
            }
        }
        if (position.y <= 0 || position.y + 2*radius >= boundary.y) {
            velocity.y *= -1;
            if (position.y >= boundary.y) {
                position.y += boundary.y - position.y + radius;
            } else if (position.y <= 0) {
                position.y += 0.f -position.y + radius;
            }
        }
}

Particle::~Particle() {
}