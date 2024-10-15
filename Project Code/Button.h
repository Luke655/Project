#ifndef BUTTON_H
#define BUTTON_H

#include "Interactable.h"

class Button: public Interactable {
    public:
        Button();
        ~Button();

        void setValue(bool value);
        void interact();
        void setTitlePosition(Vector2f position);
        bool getValue();

    private:
        bool value;
        Text title = Interactable::getTitle();
};

#endif