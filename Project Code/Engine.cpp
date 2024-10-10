#include "Engine.h"
#include <iostream>
#include <cmath>

Engine::Engine() {
}

void Engine::run() {

    //Render Window
    RenderWindow window(VideoMode(720,480), "Physics Engine"); // sf::Style::Fullscreen
    window.setPosition({100,100});
    window.setFramerateLimit(FPS);
    Vector2i boundary(window.getDefaultView().getSize());
    Grid grid(boundary);

    for (int i = 0; i < 100; i++) {
        grid.addParticle();
        grid.getParticle(i)->setPosition({rand() % boundary.x, rand() % boundary.y});
        grid.getParticle(i)->setVelocity({rand() % 100, rand() % 100});
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

            grid.getParticle(p)->update(dt);
            grid.getParticle(p)->checkBoundary(boundary); 
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