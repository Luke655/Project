#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;

class Interactable: public Transformable {
    public:
        Interactable();
        ~Interactable();

        float getValue(); // Returns the value of the interactable.
        virtual void interact() = 0; // Registers a user imput on the interactable.
        Vector2f getPosition(); // Returns the position.
        void setPosition(Vector2f position); // Sets a new position.
        RectangleShape getShape(); // Returns the shape of the interactable.
        void setColour(Color colour); // Sets the fill colour for the interactable.
        Vector2f getSize(); // Returns the size.
        void setSize(Vector2f size); // Sets a new size.
        Text getTitle(); // Returns the title of the interactable.
        void setTitle(std::string title); // Sets the title of the interactable.

    private:
        Text title;
        Vector2f titlePosition;
        float value;
        Vector2f position;
        RectangleShape shape;
        Vector2f size;
        Font font;
};

#endif