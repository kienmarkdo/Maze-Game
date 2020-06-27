#include "Maze.h"

Maze::Maze()
{
    //ctor
}

Maze::~Maze()
{
    //dtor
}

Monster Maze::getMonster()
{
    return _monster;
}

MazeObject Maze::getObject()
{
    return object;
}

/// ==================================================================

int Maze::getROW()
{
    return ROW;
}

int Maze::getCOLUMN()
{
    return COLUMN;
}

/// ==================================================================

char Maze::getBlock(int inputRow, int inputCol)
{
    return block[inputRow][inputCol];
}

void Maze::setBlock(int inputRow, int inputCol, char inputChar)
{
    block[inputRow][inputCol] = inputChar;
    return;
}

/// ==================================================================

char Maze::getKey()
{
    return KEY;
}

char Maze::getWin()
{
    return WIN;
}

/// ==================================================================

char Maze::getWall(int arrPosition)
{
    return wall[arrPosition];
}

char Maze::getTrailType(int arrPosition)
{
    return trailType[arrPosition];
}


