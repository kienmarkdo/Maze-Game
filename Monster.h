#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>

#include "Character.h"

using namespace std;


class Monster: public Character
{
    public:
        Monster();
        virtual ~Monster();

    protected:

    private:
};

#endif // MONSTER_H
