#include "Hero.h"

Hero::Hero()
{
    setCharType('X');
    setHealth(100);
    setDamage(0);
    setRowCoord(1);
    setColCoord(1);
}

Hero::~Hero()
{
    //dtor
}

// this function lets the hero know which Maze it is pointing to
void Hero::currentMaze(Maze* _currMaze)
{
    _maze = _currMaze;
}


/// ============================ GET DIRECTION BLOCK FUNCTIONS ===============================

// get functions

char Hero::getLeftBlock()
{
    return _maze->getBlock(getRowCoord(), getColCoord()-1);
}

char Hero::getRightBlock()
{
    return _maze->getBlock(getRowCoord(), getColCoord()+1);
}

char Hero::getTopBlock()
{
    return _maze->getBlock(getRowCoord()-1, getColCoord());
}

char Hero::getBottomBlock()
{
    return _maze->getBlock(getRowCoord()+1, getColCoord());
}

/// ============================ SET DIRECTION BLOCK FUNCTIONS ===============================

void Hero::setLeftBlock(char inputChar) // inputChar here should always be trail from int mainGame();
{
    _maze->setBlock(getRowCoord(), getColCoord()-1, getCharType()); // sets the left block to hero
    _maze->setBlock(getRowCoord(), getColCoord(), inputChar); // sets current block as trail
    setColCoord(getColCoord()-1); // sets current colCoord to the left
}

void Hero::setRightBlock(char inputChar)
{
    _maze->setBlock(getRowCoord(), getColCoord()+1, getCharType());
    _maze->setBlock(getRowCoord(), getColCoord(), inputChar);
    setColCoord(getColCoord()+1);
}

void Hero::setTopBlock(char inputChar)
{
    _maze->setBlock(getRowCoord()-1, getColCoord(), getCharType());
    _maze->setBlock(getRowCoord(), getColCoord(), inputChar);
    setRowCoord(getRowCoord()-1);
}

void Hero::setBottomBlock(char inputChar)
{
    _maze->setBlock(getRowCoord()+1, getColCoord(), getCharType());
    _maze->setBlock(getRowCoord(), getColCoord(), inputChar);
    setRowCoord(getRowCoord()+1);
}
