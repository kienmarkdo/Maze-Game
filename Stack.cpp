#include "Stack.h"

Stack::Stack() //ctor
{
    top = nullptr;
    stackSize = 0;
}

void Stack::display()
{
    Element *currentIndex = new Element;
    currentIndex = top;
    while (currentIndex != nullptr)
    {
        cout << currentIndex->getContent() << ' ';
        currentIndex = currentIndex->getNext();
    }
    return;
}

void Stack::push(char inputValue)
{
    Element *newElement = new Element;
    newElement->setContent(inputValue);

    if(getStackSize() == 0)
    {
        top = newElement;
        top->setNext(nullptr);
    }
    else
    {
        newElement->setNext(top);
        top = newElement;
    }
    stackSize++;
    return;
}

void Stack::pop()
{
    if (stackSize > 0)
    {
        Element *temp = new Element;
        temp = top;
        top = top->getNext();
        temp->setNext(nullptr);
        delete temp;
        stackSize--;
    }
    return;
}

char Stack::peak()
{
    Element *temp = new Element;
    if (stackSize == 0)
    {
        top = temp;
        top->setContent(' ');
    }
    return top->getContent();
}

void Stack::setTop(Element *_newElement)
{
    top = _newElement;
    return;
}

Element* Stack::getTop()
{
    return top;
}

void Stack::setStackSize(int _stackSize)
{
    stackSize = _stackSize;
    return;
}

int Stack::getStackSize()
{
    return stackSize;
}
