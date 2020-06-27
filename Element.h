#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include "Stack.h"

using namespace std;

class Element
{
    public:
        Element();

        void setNext(Element*);
        void setContent(char);

        Element* getNext();
        char getContent();

    protected:

    private:
        Element* next;
        char content;
};

#endif // ELEMENT_H
