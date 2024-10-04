#include "Engine.h"
#include <iostream>
#include <cmath>

Engine::Engine() {
    particles = new Particle*[250];
}

Particle* Engine::addParticle() {
    particles[count] = new Particle;
    count++;
    return particles[count - 1];
}

void Engine::removeParticle(Particle p) {
    p.~Particle();
}

void Engine::run() {

    //Render Window
    RenderWindow window(VideoMode(1920,1080), "Physics Engine"); // sf::Style::Fullscreen
    window.setPosition({0,0});
    window.setFramerateLimit(FPS);
    Vector2f boundary(window.getDefaultView().getSize());

    //Initialise particle
    for (int i = 0; i < 250; i++) {
        particles[i] = addParticle();
        particles[i]->setVelocity({rand() % 50, rand() % 20});
        particles[i]->setPosition({rand() % (int)boundary.x, rand() % (int)boundary.y});
    }
    //Clock
    Clock clock;

    //Run loop
    while (window.isOpen()) {
        
        dt = clock.restart();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        for (int p = 0; p < count; p++) {

            particles[p]->update(dt);
            particles[p]->checkCollision(boundary); 
        }
    
        window.clear();
        for (int j = 0; j < count; j++) {
            window.draw(particles[j]->getShape());
        }
        window.display();

    }
}

Engine::~Engine() {}