#include "Particle.h"

Particle::Particle() { 

    setOrigin(radius, radius);
    position = {0,0};
    velocity = {0,0};
    mass = 1;
    p.setRadius(radius);
    p.setFillColor(Color::White);
    p.setOutlineColor(Color::Black);
    p.setOutlineThickness(2.f);
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

void Particle::checkBoundary(RectangleShape boundary) {

        if (position.x <= boundary.getPosition().x || position.x + 2*radius >= boundary.getPosition().x + boundary.getSize().x) {
            velocity.x *= -1;
            if (position.x + radius >= boundary.getSize().x + boundary.getPosition().x) {
                position.x -= boundary.getPosition().x + boundary.getSize().x - position.x + radius;
            } else if (position.x - radius <= boundary.getPosition().x) {
                position.x += boundary.getPosition().x - position.x + radius;
            }
        }
        if (position.y <= boundary.getPosition().y || position.y + 2*radius >= boundary.getSize().y + boundary.getPosition().y) {
            velocity.y *= -1;
            if (position.y + radius >= boundary.getPosition().y + boundary.getSize().y) {
                position.y -= boundary.getPosition().y + boundary.getSize().y - position.y + radius;
            } else if (position.y - radius <= boundary.getPosition().y) {
                position.y += boundary.getPosition().y - position.y + radius;
            }
        }
}

Particle::~Particle() {
}