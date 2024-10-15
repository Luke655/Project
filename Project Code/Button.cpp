#include "Button.h"

Button::Button() {
    value = false;
    title.setPosition(getPosition());
}

Button::~Button() {
}

void Button::setValue(bool value) {
    this->value = value;
}

void Button::interact() {
    if (value == true) {
        value = false;
    } else {
        value = true;
    }
}

void Button::setTitlePosition(Vector2f position) {
    title.setPosition(position);
}

bool Button::getValue() {
    return value;
}