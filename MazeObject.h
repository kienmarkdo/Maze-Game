#ifndef MAZEOBJECT_H
#define MAZEOBJECT_H
#include <iostream>

using namespace std;

class MazeObject
{
    public:
        MazeObject();
        virtual ~MazeObject();

        void setCharType(char);
        char getCharType();

        int getRowCoord();
        int getColCoord();
        void setRowCoord(int);
        void setColCoord(int);
        void setCoord(int, int);

    protected:

    private:
        char charType;
        int rowCoord;
        int colCoord;
};

#endif // MAZEOBJECT_H
