#include "Element.h"

Element::Element()
{
    //ctor
}

void Element::setNext(Element* _next)
{
    next = _next;
    return;
}

void Element::setContent(char _content)
{
    content = _content;
    return;
}

Element* Element::getNext()
{
    return next;
}

char Element::getContent()
{
    return content;
}
