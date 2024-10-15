#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;

class Interactable: public Transformable {
    public:
        Interactable();
        Interactable(String title);
        ~Interactable();

        float getValue();
        virtual void interact() = 0;
        Vector2f getPosition();
        void setPosition(Vector2f position);
        RectangleShape getShape();
        void setColour(Color colour);
        Vector2f getSize();
        void setSize(Vector2f size);
        Text getTitle();
        void setTitle(String title);
        virtual void setTitlePosition(Vector2f position) = 0;

    private:
        Text title;
        Vector2f titlePosition;
        float value;
        Vector2f position;
        RectangleShape shape;
        Vector2f size;
};

#endif