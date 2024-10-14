#include "Engine.h"
#include <iostream>

Engine::Engine() {
}

void Engine::run() {

    // Render Window
    RenderWindow window(VideoMode(1080,720), "Physics Engine"); // sf::Style::Fullscreen
    window.setPosition({100,100});
    window.setFramerateLimit(FPS);
    RectangleShape boundary({540, 700});
    boundary.setPosition({20.f,10.f});
    boundary.setOutlineThickness(2.f);
    boundary.setOutlineColor(Color::Black);
    boundary.setFillColor(Color::White);
    Grid grid(boundary.getSize());

    // Add particles
    for (int i = 0; i < 200; i++) {
        grid.addParticle();
        Particle *p = grid.getParticle(i);
        p->setPosition({rand() % (int)boundary.getSize().x, rand() % (int)boundary.getSize().y});
        p->setVelocity({rand() % 100, rand() % 100});
    }    

    // Render Interactables
    Button button;
    button.setPosition({650,40});
    button.setColour(Color::Green);
    button.setSize({100,75});

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
            particle->checkBoundary(boundary); 
            grid.checkCollisions(particle);
        }
    
        window.clear();
        window.draw(boundary);
        window.draw(button.getShape());
        for (int j = 0; j < grid.getNumParticles(); j++) {
            window.draw(grid.getParticle(j)->getShape());
        }
        window.display();

    }
}

Engine::~Engine() {
}