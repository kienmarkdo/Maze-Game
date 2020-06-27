#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "Element.h"

using namespace std;

class Element;

class Stack
{
    public:
        Stack();

        void display();
        void push(char);
        void pop();
        char peak();

        void setTop(Element*);
        void setStackSize(int);

        Element* getTop();
        int getStackSize();

    protected:

    private:
        Element *top;
        int stackSize;
};

#endif // STACK_H
