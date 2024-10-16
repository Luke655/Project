#ifndef BUTTON_H
#define BUTTON_H

#include "Interactable.h"

class Button: public Interactable {
    public:
        Button();
        ~Button();

        void interact(); // Turns the button on/off.
        bool getValue(); // Returns the state of the button.
        void setValue(bool value); // Sets a definite value for the button.

    private:
        bool value;
};

#endif