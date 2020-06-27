#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

using namespace std;


class Character
{
    public:
        Character();
        virtual ~Character();

        void setCharType(char);
        char getCharType();

        void setHealth(int);
        int getHealth();

        void setDamage(int);
        int getDamage();

        /// ============================ GET & SET CHARACTER COORDINATES ===============================

        int getRowCoord();
        int getColCoord();
        void setRowCoord(int);
        void setColCoord(int);
        void setCoord(int, int);

    protected:

    private:
        char charType;
        int health;
        int damage; // damage that this character can deal

        int rowCoord;
        int colCoord;

        //int colour; // idea: indicates character type. eg: red is monster
};

#endif // CHARACTER_H
