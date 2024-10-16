#include "Button.h"

Button::Button() {
    value = false;
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

bool Button::getValue() {
    return value;
}
