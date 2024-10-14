#include "Button.h"

Button::Button() {
    value = false;
}

Button::~Button() {
}

void Button::setValue() {
   
    if (value == true) {
        value = false;
    } else {
        value = true;
    }
    return;
}
