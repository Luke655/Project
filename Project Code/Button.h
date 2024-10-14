#ifndef BUTTON_H
#define BUTTON_H

#include "Interactable.h"

class Button: public Interactable {
    public:
        Button();
        ~Button();

        void setValue(); 

    private:
        bool value;
};

#endif