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
    float averageVelocity = 0;
    for (int i = 0; i < 400; i++) {
        grid.addParticle();
        Particle *p = grid.getParticle(i);
        p->setPosition({(float)((rand() % 500) + 40), (float)((rand() % 660) + 40)});
        p->setVelocity({(float)(rand() % 100), (float)(rand() % 100)});
        averageVelocity += sqrt(p->getVelocity().x * p->getVelocity().x * p->getVelocity().y * p->getVelocity().y);
    }

    averageVelocity /= grid.getNumParticles();

    // Render Interactables
    Font font;
    font.loadFromFile("arial.ttf");

    Button start;
    start.setValue(false);
    start.setPosition({700,40});
    start.setColour(Color::Green);
    start.setSize({100,75});
    start.setTitle("Play");

    Button stop;
    stop.setValue(true);
    stop.setPosition({850, 40});
    stop.setColour(Color::Red);
    stop.setSize({100,75});
    stop.setTitle("Pause");

    Text pressure;
    float Pressure;
    std::string pressureStr;
    pressure.setFont(font);
    pressure.setFillColor(Color::White);
    pressure.setPosition({600,300});
    pressure.setCharacterSize(24U);
    pressure.setStyle(Text::Bold);

    Text aveVelocity;
    std::string aveVelocityStr;
    aveVelocity.setFont(font);
    aveVelocity.setFillColor(Color::White);
    aveVelocity.setPosition({600,350});
    aveVelocity.setCharacterSize(24U);
    aveVelocity.setStyle(Text::Bold);

    Text numParticles;
    int NumParticles = grid.getNumParticles();
    std::string numParticlesStr = std::to_string(NumParticles);
    numParticles.setFont(font);
    numParticles.setFillColor(Color::White);
    numParticles.setPosition({600,400});
    numParticles.setCharacterSize(24U);
    numParticles.setStyle(Text::Bold);
    numParticles.setString("Number of Particles:  " + numParticlesStr);

    Text temperature;
    int Temperature;
    std::string temperatureStr;
    temperature.setFont(font);
    temperature.setFillColor(Color::White);
    temperature.setPosition({600,450});
    temperature.setCharacterSize(24U);
    temperature.setStyle(Text::Bold);

    Text density;
    float densityNum = boundary.getSize().x * boundary.getSize().y / (grid.getNumParticles()* 3.1415 * 25);
    std::string densityStr = std::to_string(densityNum);
    density.setFont(font);
    density.setFillColor(Color::White);
    density.setPosition({600,500});
    density.setCharacterSize(24U);
    density.setStyle(Text::Bold);
    density.setString("Density:                     " + densityStr + "kg/m^2");

    Text escape;
    escape.setFont(font);
    escape.setFillColor(Color::White);
    escape.setPosition({600,650});
    escape.setCharacterSize(18U);
    escape.setString("Press ESC to exit the program.");

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
                        if (position.x >= start.getPosition().x && position.x <= (start.getPosition().x + start.getSize().x) && position.y >= start.getPosition().y && (position.y <= start.getPosition().y + start.getSize().y)) {
                            start.setValue(true);
                        } else if (position.x >= stop.getPosition().x && position.x <= (stop.getPosition().x + stop.getSize().x) && position.y >= stop.getPosition().y && position.y <= (stop.getPosition().y + stop.getSize().y)) {
                            start.setValue(false);
                        }
                        break;
                    }

                default:
                    break;
            }
    
        }

        if (start.getValue() == true) {
            averageVelocity = 0;
            for (int p = 0; p < grid.getNumParticles(); p++) {
                Particle *particle = grid.getParticle(p);
                particle->update(FPS);
                particle->checkBoundary(boundary); 
                grid.checkCollisions(particle);
                averageVelocity += sqrt(particle->getVelocity().x * particle->getVelocity().x * particle->getVelocity().y * particle->getVelocity().y);
            }
        }
        averageVelocity /= grid.getNumParticles() * 378;
        Temperature = 0.5f * averageVelocity * averageVelocity;
        Pressure = 8.314f * Temperature / (boundary.getSize().x * boundary.getSize().y);

        aveVelocityStr = std::to_string(averageVelocity);
        aveVelocity.setString("Average Velocity:       " + aveVelocityStr + "m/s");
        temperatureStr = std::to_string(Temperature);
        temperature.setString("Temperature:             " + temperatureStr + "C");
        pressureStr = std::to_string(Pressure);
        pressure.setString("Pressure:                   " + pressureStr + "kPa");


        window.clear();
        window.draw(boundary);
        window.draw(start.getShape());
        window.draw(start.getTitle());
        window.draw(stop.getShape());
        window.draw(stop.getTitle());
        window.draw(pressure);
        window.draw(aveVelocity);
        window.draw(numParticles);
        window.draw(temperature);
        window.draw(density);
        window.draw(escape);
        for (int j = 0; j < grid.getNumParticles(); j++) {
            window.draw(grid.getParticle(j)->getShape());
        }
        window.display();

    }
}

Engine::~Engine() {
}