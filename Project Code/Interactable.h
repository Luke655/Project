#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;

class Interactable: public Transformable {
    public:
    Interactable();
    Interactable(std::string Title);
    ~Interactable();

    float getValue();
    virtual void setValue(float value);

    Vector2f getPosition();
    void setPosition(Vector2f position);
    
    private:
    std::string Title;
    float value;
    Vector2f position;

};

#endif