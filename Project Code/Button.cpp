#include "Button.h"

Button::Button() {
    value = false;
}

Button::~Button() {
}

bool Button::isOn() {
    return value;
}

void Button::interact() {
    if (value == true) {
        value = false;
    } else {
        value = true;
    }
    return;
}