#include "Interactable.h"

Interactable::Interactable() {
    this->Title = "";
    this-> value = 0;
}

Interactable::Interactable(std::string Title) {
    this->Title = Title;
    this->value = 0;
}

Interactable::~Interactable() {
}

float Interactable::getValue() {
    return value;
}

Vector2f Interactable::getPosition() {
    return position;
}

void Interactable::setPosition(Vector2f position) {
    this->position = position;
    shape.setPosition(position);
}

RectangleShape Interactable::getShape() {
    return shape;
}

void Interactable::setColour(Color colour) {
    shape.setFillColor(colour);
}

Vector2f Interactable::getSize() {
    return size;
}

void Interactable::setSize(Vector2f size) {
    this->size = size;
    shape.setSize(size);
}