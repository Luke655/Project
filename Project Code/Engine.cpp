#include "Engine.h"
#include <iostream>

Engine::Engine() {
}

void Engine::run() {

    //Render Window
    RenderWindow window(VideoMode(1000,720), "Physics Engine"); // sf::Style::Fullscreen
    window.setPosition({100,100});
    window.setFramerateLimit(FPS);
    RectangleShape boundary(window.getDefaultView().getSize());
    boundary.setPosition({0.f,0.f});
    boundary.setOutlineThickness(2.f);
    boundary.setOutlineColor(Color::White);
    boundary.setFillColor(Color::Black);
    Grid grid(boundary.getSize());

    for (int i = 0; i < 200; i++) {
        grid.addParticle();
        Particle *p = grid.getParticle(i);
        p->setPosition({rand() % (int)boundary.getSize().x, rand() % (int)boundary.getSize().y});
        p->setVelocity({rand() % 100, rand() % 100});
    }    

    //Clock
    Clock clock;

    //Run loop
    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {

                case Event::Closed:
                    window.close();
                    break;

                case Event::KeyPressed:
                    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                        window.close();
                        break;
                    }

                default:
                    break;
            }
    
        }

        for (int p = 0; p < grid.getNumParticles(); p++) {
            Particle *particle = grid.getParticle(p);
            particle->update(FPS);
            particle->checkBoundary(boundary.getSize()); 
            grid.checkCollisions(particle);
            
        }
    
        window.clear();
        window.draw(boundary);
        for (int j = 0; j < grid.getNumParticles(); j++) {
            window.draw(grid.getParticle(j)->getShape());
        }
        window.display();

    }
}

Engine::~Engine() {
}