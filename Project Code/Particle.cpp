#include "Particle.h"

Particle::Particle() { 

    position = {0,0};
    velocity = {0,0};
    mass = 1;
    p.setRadius(radius);
    p.setFillColor(Color::Yellow);
    p.setOutlineThickness(3.f);
    p.setOutlineColor(Color::White);
}

Particle::Particle(Vector2f position) {

    p.setPosition(position);
    position = position;;
    velocity = {0,0};
    mass = 1;
    p.setRadius(radius);
    p.setFillColor(Color::Black);
    p.setOutlineThickness(3.f);
    p.setOutlineColor(Color::White);
}
CircleShape Particle::getShape() {
    return p;
}

Vector2f Particle::getPosition() {
    return position;
}

void Particle::setPosition(Vector2f pos) {
    p.setPosition(pos);
    position = pos;
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

void Particle::setColor(float v) {
    p.setFillColor(Color::White);
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

void Particle::checkCollision(Vector2f boundary) {

        if (position.x + radius < 0) {

            velocity = {-velocity.x, velocity.y};

        } else if (position.x + radius > boundary.x) {

            velocity = {-velocity.x, velocity.y};

        } else if (position.y + radius < 0) {

            velocity = {velocity.x, - velocity.y};
        } else if (position.y + radius > boundary.y) {

            velocity = {velocity.x, - velocity.y};
        }
}

Particle::~Particle() {
}