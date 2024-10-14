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
        virtual void setValue() = 0;
        Vector2f getPosition();
        void setPosition(Vector2f position);
        RectangleShape getShape();
        void setColour(Color colour);
        Vector2f getSize();
        void setSize(Vector2f size);
        

    private:
        std::string Title;
        float value;
        Vector2f position;
        RectangleShape shape;
        Vector2f size;
};

#endif