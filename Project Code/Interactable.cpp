#include "Interactable.h"

Interactable::Interactable() {
    this-> value = 0;
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

Text Interactable::getTitle() {
    return title;
}
void Interactable::setTitle(std::string title) {
    font.loadFromFile("arial.ttf");
    this->title.setString(title);
    this->title.setPosition({position.x + 0.2f * size.x, position.y + 0.33f * size.y});
    this->title.setFont(font);
    this->title.setCharacterSize(24U);
    this->title.setFillColor(Color::Black);
    this->title.setStyle(Text::Bold);
}