#include "Engine.h"
#include <iostream>
#include <cstdlib>

Engine::Engine() {
}

void Engine::run() {

    // Render Window
    RenderWindow window(VideoMode(1080,720), "Physics Engine"); // sf::Style::Fullscreen
    window.setPosition({100,100});
    window.setFramerateLimit(FPS);
    RectangleShape boundary({540, 700});
    boundary.setPosition({20.f,10.f});
    boundary.setOutlineThickness(10.f);
    boundary.setOutlineColor(Color::Black);
    boundary.setFillColor(Color::White);
    Grid grid(boundary.getSize());

    // Add particles
    for (int i = 0; i < 200; i++) {
        grid.addParticle();
        Particle *p = grid.getParticle(i);
        p->setPosition({(float)((rand() % 500) + 40), (float)((rand() % 660) + 40)});
        p->setVelocity({(float)(rand() % 100), (float)(rand() % 100)});
    }    

    // Render Interactables
    Button start;
    start.setValue(false);
    start.setPosition({650,40});
    start.setColour(Color::Green);
    start.setSize({100,75});
    start.setTitle("Start");

    Button stop;
    stop.setValue(true);
    stop.setPosition({850, 40});
    stop.setColour(Color::Red);
    stop.setSize({100,75});
    stop.setTitle(String("Stop"));

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
                
                case Event::MouseButtonPressed:
                    if (Mouse::isButtonPressed(Mouse::Left)) {
                        Vector2i position = Mouse::getPosition(window);
                        std::cout << position.x << " " << position.y << std::endl;
                        if (position.x >= start.getPosition().x && position.x <= (start.getPosition().x + start.getSize().x) && position.y >= start.getPosition().y && (position.y <= start.getPosition().y + start.getSize().y)) {
                            start.interact();
                        } else if (position.x >= stop.getPosition().x && position.x <= (stop.getPosition().x + stop.getSize().x) && position.y >= stop.getPosition().y && position.y <= (stop.getPosition().y + stop.getSize().y)) {
                            stop.interact();
                            start.interact();
                        }
                        break;
                    }

                default:
                    break;
            }
    
        }

        if (start.getValue() == true) {
            for (int p = 0; p < grid.getNumParticles(); p++) {
                Particle *particle = grid.getParticle(p);
                particle->update(FPS);
                particle->checkBoundary(boundary); 
                grid.checkCollisions(particle);
            }
        }
    
        window.clear();
        window.draw(boundary);
        window.draw(start.getShape());
        window.draw(start.getTitle());
        window.draw(stop.getShape());
        window.draw(stop.getTitle());
        for (int j = 0; j < grid.getNumParticles(); j++) {
            window.draw(grid.getParticle(j)->getShape());
        }
        window.display();

    }
}

Engine::~Engine() {
}