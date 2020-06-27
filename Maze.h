#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <windows.h>

#include "Hero.h"
#include "Monster.h"
#include "MazeObject.h"

using namespace std;

class Hero;
class Monster;
class MazeObject;

class Maze
{
    public:
        Maze();
        virtual ~Maze();

        Monster getMonster();
        MazeObject getObject();

        int getROW();
        int getCOLUMN();

        char getBlock(int, int);
        void setBlock(int, int, char);

        char getKey();
        char getWin();

        char getWall(int);
        char getTrailType(int);

    protected:

    private:
        Hero * _hero;
        Monster _monster;
        MazeObject object;

        /// ======================= Walls ===========================

        char HOR = 205; // horizontal
        char VER = 186; // vertical
        // ===== corners =====
        char LRC = 188; // lower left corner
        char URC = 187; // upper right corner
        char LLC = 200; // lower left corner
        char ULC = 201; // upper left corner
        // ===== wall at intersection =====
        char UPI = 202;
        char LOI = 203;
        char LEI = 185;
        char RII = 204;
        char FWI = 206;
        // other
        char EMP = ' ';
        char WIN = 'W';
        char KEY = 'K';
        int ROW = 15;
        int COLUMN = 15;

        /// ======================= Move Check ===========================

        char wall[11] = {UPI, LOI, RII, LEI, FWI, LLC, LRC, ULC, URC, HOR, VER}; // all walls
        char trailType[4] = {'<', '>', '^', 'v'}; // conditions for the auto solver only

        /// ======================= The Maze ===========================

        // the creation of the maze only contains necessary items
        // ie: walls, the key, the door, etc.
        // all other objects (monsters, potions) will be added in main.cpp as it is dependent on the user's input
        char block[15][15] =
        {
            //   0    1    2    3    4    5    6    7    8    9    10   11   12  13   14
            {
                ULC, HOR, LOI, HOR, HOR, HOR, HOR, HOR, LOI, HOR, LOI, HOR, HOR, HOR, URC // 0
            },
            {
                VER, ' ', VER, ' ', ' ', ' ', ' ', ' ', VER, ' ', VER, ' ', ' ', ' ', VER // 1
            },
            {
                VER, ' ', VER, ' ', VER, ' ', VER, ' ', VER, ' ', VER, ' ', VER, ' ', VER // 2
            },
            {
                VER, ' ', ' ', ' ', VER, ' ', VER, ' ', VER, ' ', VER, ' ', ' ', ' ', VER // 3
            },
            {
                RII, HOR, LOI, HOR, LRC, ' ', VER, ' ', VER, ' ', LLC, HOR, HOR, ' ', VER // 4
            },
            {
                VER, ' ', VER, ' ', ' ', ' ', VER, ' ', ' ', ' ', ' ', ' ', ' ', ' ', VER // 5
            },
            {
                VER, ' ', VER, ' ', VER, ' ', RII, HOR, HOR, ' ', ULC, HOR, HOR, ' ', VER // 6
            },
            {
                VER, ' ', VER, ' ', ' ', ' ', VER, ' ', ' ', ' ', VER, ' ', ' ', ' ', VER // 7
            },
            {
                VER, ' ', LLC, HOR, HOR, HOR, LRC, ' ', VER, ' ', VER, ' ', HOR, HOR, LEI // 8
            },
            {
                VER, ' ', ' ', ' ', ' ', ' ', ' ', ' ', VER, ' ', VER, ' ', ' ', ' ', VER // 9
            },
            {
                VER, ' ', HOR, HOR, LOI, HOR, HOR, HOR, FWI, HOR, UPI, HOR, HOR, ' ', VER // 10
            },
            {
                VER, ' ', ' ', ' ', VER, ' ', ' ', ' ', VER, KEY, ' ', ' ', ' ', ' ', VER // 11 KEY used to be here
            },
            {
                RII, HOR, HOR, HOR, LRC, ' ', VER, ' ', LLC, HOR, HOR, HOR, HOR, HOR, LEI // 12 (12,2) is open point
            },
            {
                VER, ' ', ' ', ' ', ' ', ' ', VER, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WIN // 13
            },
            {
                LLC, HOR, HOR, HOR, HOR, HOR, UPI, HOR, HOR, HOR, HOR, HOR, HOR, HOR, LRC // 14
            }
        };
};

#endif // MAZE_H
