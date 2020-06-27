#ifndef HERO_H
#define HERO_H
#include <iostream>

#include "Character.h"
#include "Maze.h"

using namespace std;

class Maze;

class Hero: public Character
{
    public:
        Hero();
        virtual ~Hero();

        void currentMaze(Maze*);

        /// ======================= Get and Set Adjacent Blocks ===========================

        char getLeftBlock();
        char getRightBlock();
        char getTopBlock();
        char getBottomBlock();

        // char in setDIRECTIONblock functions below should always be trail from int mainGame();
        // go to Hero.cpp for more details
        void setLeftBlock(char); // move left
        void setRightBlock(char); // move right
        void setTopBlock(char); // move up
        void setBottomBlock(char); // move down

    protected:

    private:
        string name;
        Maze * _maze;

};

#endif // HERO_H
