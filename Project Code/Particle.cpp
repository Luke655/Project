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

void Particle::update(Time dt) {

    velocity += netForce * mass * dt.asSeconds();
    position += velocity * dt.asSeconds();

    p.setPosition(position);

    netForce = {0,0};
}

void Particle::checkBoundary(Vector2i boundary) {

        if (position.x <= 0 || position.x + 2*radius >= boundary.x) {
            velocity.x *= -1;
        } else if (position.y <= 0 || position.y + 2*radius >= boundary.y) {
            velocity.y *= -1;
        }
}

Particle::~Particle() {
}