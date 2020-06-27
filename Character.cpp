#include "Character.h"

Character::Character()
{
    health = 0;
    damage = 0;
}

Character::~Character()
{
    // requires a dtor
    // https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable
}

void Character::setCharType(char _charType)
{
    charType = _charType;
}

char Character::getCharType()
{
    return charType;
}

void Character::setHealth(int _health)
{
    health = _health;
}

int Character::getHealth()
{
    return health;
}

void Character::setDamage(int _damage)
{
    damage = _damage;
}

int Character::getDamage()
{
    return damage;
}

/// ============================ GET & SET CHARACTER COORDINATES ===============================

int Character::getRowCoord()
{
    return rowCoord;
}

int Character::getColCoord()
{
    return colCoord;
}

void Character::setRowCoord(int inputRow)
{
    rowCoord = inputRow;
}

void Character::setColCoord(int inputCol)
{
    colCoord = inputCol;
}

void Character::setCoord(int _row, int _col)
{
    rowCoord = _row;
    colCoord = _col;
}

