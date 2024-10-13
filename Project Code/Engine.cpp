#include "Engine.h"
#include <iostream>

Engine::Engine() {
}

void Engine::run() {

    //Render Window
    RenderWindow window(VideoMode(720,480), "Physics Engine"); // sf::Style::Fullscreen
    window.setPosition({100,100});
    window.setFramerateLimit(FPS);
    Vector2i boundary({window.getDefaultView().getSize().x, window.getDefaultView().getSize().y});
    Grid grid(boundary);

    for (int i = 0; i < 100; i++) {
        grid.addParticle();
        Particle *p = grid.getParticle(i);
        p->setPosition({rand() % boundary.x, rand() % boundary.y});
        p->setVelocity({rand() % 100, rand() % 100});
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

        for (int p = 0; p < grid.getNumParticles(); p++) {
            Particle *particle = grid.getParticle(p);
            particle->update(dt);
            particle->checkBoundary(boundary); 
            grid.checkCollisions(particle);
            
        }
    
        window.clear();
        for (int j = 0; j < grid.getNumParticles(); j++) {
            window.draw(grid.getParticle(j)->getShape());
        }
        window.display();

    }
}

Engine::~Engine() {
}