#include "MazeObject.h"

MazeObject::MazeObject()
{
    //ctor
}

MazeObject::~MazeObject()
{
    //dtor
}

// get and set charType

void MazeObject::setCharType(char _charType)
{
    charType = _charType;
}

char MazeObject::getCharType()
{
    return charType;
}

// coordinates

int MazeObject::getRowCoord()
{
    return rowCoord;
}

int MazeObject::getColCoord()
{
    return colCoord;
}

void MazeObject::setRowCoord(int inputRow)
{
    rowCoord = inputRow;
}

void MazeObject::setColCoord(int inputCol)
{
    colCoord = inputCol;
}

void MazeObject::setCoord(int _row, int _col)
{
    rowCoord = _row;
    colCoord = _col;
}
