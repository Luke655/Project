#ifndef BUTTON_H
#define BUTTON_H

#include "Interactable.h"

class Button: public Interactable {
    public:
        Button();
        ~Button();

        bool isOn(); 
        void interact();

    private:
        bool value;
        Vector2f size;
};

#endif