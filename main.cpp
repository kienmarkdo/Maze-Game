/**
Name: Kien Do
ICS4U - Mr. Maloley
Purpose: Summative Maze Game

Last edit: Jan 19 2020
**/

/// INCLUDE STATEMENTS
// library
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
// classes
// ===================
#include "Maze.h"
#include "MazeObject.h"
// ===================
#include "Character.h"
#include "Hero.h"
#include "Monster.h"
// ===================
#include "Stack.h"
#include "Element.h"

using namespace std;

// constants and global variables
bool FIRSTPLAY = false;
const int HEROHEALTHCOLOUR = 9;
const int MONSTERISTRUE = 10;
const int TRAPISTRUE = 15;
const int HEALTHPOTIONISTRUE = 20;
const int RANDOBJECTISTRUE = 30;
const int KEYISTRUE = 99;
const int WINISTRUE = 100;
const int TERMINATE = -1;

const int CHEATCODE = 2020;

/// FUNCTION PROTOTYPES
// general functions
void displayMazeEasy(Maze);
void displayMazeHard(Maze, Hero);
void clearScreen();
void showConsoleCursor(bool);
void pressEnterToContinue();
void setColor(int);
int startingMenu();
int mainGame(int);

// stack solver functions
int autoSolverGame();
char oppositeMoveFinder(char);
void refillStackAutoSolver(char, Stack*);
int autoSolverCheckMove(Maze, char);

// user game functions
void userGameIntro(int);
int userCheckMove(Maze, char);
int fightMonster(Hero*, Monster[]);
int userGame(int);

/// ===================================  ACTUAL FUNCTIONS  =======================================
void displayMazeEasy(Maze _maze)
{
    for (int i = 0; i < _maze.getROW(); i++)
    {
        for (int j = 0; j < _maze.getCOLUMN(); j++)
        {
            if ((i == 12 && j == 2) || (i == 11 && j == 9)) // location of the door and KEY
            {
                setColor(14);
                cout << _maze.getBlock(i, j);
                setColor(7);
            }
            else if (_maze.getBlock(i, j) == _maze.getWin())// location of WIN
            {
                setColor(10);
                cout << _maze.getBlock(i, j);
                setColor(7);
            }
            else if (_maze.getBlock(i, j) == 'X')
            {
                setColor(9);
                cout << _maze.getBlock(i, j);
                setColor(7);
            }
            else
                cout << _maze.getBlock(i, j);
            // writing the display function this way takes up a few more lines
            // but is slightly more efficient since we're making less calls to the
            // setColor function
        }
        cout << endl;
    } // else
} // for (j=0)


void displayMazeHard(Maze _maze, Hero _hero)
{
    for (int i = 0; i < _maze.getROW(); i++)
    {
        for (int j = 0; j < _maze.getCOLUMN(); j++)
        {
            if ((i == 12 && j == 2) || (i == 11 && j == 9)) // location of DOOR and KEY
            {
                setColor(14);
            }
            if (i == _hero.getRowCoord()-1 && j == _hero.getColCoord()) // top
            {
                cout << _hero.getTopBlock();
            }
            else if (i == _hero.getRowCoord() && j == _hero.getColCoord()-1) // left
            {
                cout << _hero.getLeftBlock();
            }
            else if (i == _hero.getRowCoord() && j == _hero.getColCoord()) // middle
            {
                cout << _hero.getCharType();
            }
            else if (i == _hero.getRowCoord() && j == _hero.getColCoord()+1) // right
            {
                cout << _hero.getRightBlock();
            }
            else if (i == _hero.getRowCoord()+1 && j == _hero.getColCoord()) // bottom
            {
                cout << _hero.getBottomBlock();
            }
            else if (i == _hero.getRowCoord()-1 && j == _hero.getColCoord()-1) // top left
            {
                cout << _maze.getBlock(_hero.getRowCoord()-1, _hero.getColCoord()-1);
            }
            else if (i == _hero.getRowCoord()-1 && j == _hero.getColCoord()+1) // top right
            {
                cout << _maze.getBlock(_hero.getRowCoord()-1, _hero.getColCoord()+1);
            }
            else if (i == _hero.getRowCoord()+1 && j == _hero.getColCoord()-1) // bottom left
            {
                cout << _maze.getBlock(_hero.getRowCoord()+1, _hero.getColCoord()-1);
            }
            else if (i == _hero.getRowCoord()+1 && j == _hero.getColCoord()+1) // bottom right
            {
                cout << _maze.getBlock(_hero.getRowCoord()+1, _hero.getColCoord()+1);
            }
            else
            {
                cout << ' ';
            }
            setColor(7);
        }
        cout << endl;
    }


    return;
}

void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void showConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void pressEnterToContinue()
{
    char enter;
    cout << "Press ENTER to continue . . ." << endl << endl;
    enter = getch();
    while (enter != '\r')
    {
        cout << "ERROR: Press ENTER to continue . . ." << endl;
        enter = getch();
    }
    return;
}

void setColor(int value)
{
    /**
    1: Blue
    2: Green
    3: Cyan
    4: Red
    5: Purple
    6: Yellow (Dark)
                                7: Default white
    8: Gray/Grey
    9: Bright blue
    10: Bright green
    11: Bright cyan
    12: Bright red
    13: Pink/Magenta
    14: Yellow
    15: Bright white
    **/
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

int startingMenu()
{
    int menuOption = 0;

    while (menuOption == 0)
    {
        cout << "=============================   Welcome to Kien Do's Maze Game   =============================" << endl << endl;
        cout << "\t1. Play Game" << endl;
        cout << "\t2. Instructions" << endl;
        cout << "\t3. Credits" << endl;
        cout << "\t4. Quit" << endl;
        cout << "\t10. *** FOR MR. MALOLEY ***" << endl;
        cin >> menuOption;
        system("CLS");
        switch (menuOption)
        {
        case 1:
            break;
        case 2:
            cout << "==================================     HOW IT WORKS     ==================================" << endl << endl;
            cout << "\tUpon loading the game, you will have two options." << endl << endl;
            cout << "\tOption 1: Play the game manually." << endl;
            cout << "\t          Here, you can navigate through the maze, fight monsters, collect items" << endl;
            cout << "\t          reach the end of the maze and ultimately winning the game." << endl << endl;
            cout << "\tOption 2: Solve the maze using the auto-solver." << endl;
            cout << "\t          You will not be playing the game. You will only watch the custom" << endl;
            cout << "\t          algorithm work its way to automatically solve the maze." << endl << endl;
            cout << "==============================     MAZE CHARACTER TABLE     ==============================" << endl << endl;
            cout << "NOTE: Only characters X and K are in Option 2." << endl << endl;
            cout << "\tX = This represents the HERO in which you will be controlling to beat the maze." << endl;
            cout << "\tK = The KEY in which the you need to obtain to unlock a door that must be" << endl;
            cout << "\t    opened to reach the end of the maze. The KEY and the DOOR are colour coded." << endl;
            cout << "\tW = the end of the maze; WIN." << endl;
            cout << "\tM = A monster. Upon encountering one, you must fight until either of you dies." << endl;
            cout << "\tH = Health Potion. Gains 20 health." << endl;
            cout << "\tT = Trap. Loses 30 health." << endl;
            cout << "\t? = Could be a trap, a health potion, or a monster. Test your luck!" << endl;
            cout << endl;
            pressEnterToContinue();
            menuOption = 0;
            break;
        case 3:
            cout << "This maze game is brought to you by Kien Do." << endl << endl;
            pressEnterToContinue();
            menuOption = 0;
            break;
        case 4:
            break;
        case CHEATCODE:
            cout << "CHEAT CODE ACTIVATED." << endl << endl;
            pressEnterToContinue();
            break;
        case 10:
            cout << "Instead of entering 1. for this menu, enter 2020." << endl;
            cout << "This is a cheat code which skips the intro screen as well as gives you 9999999 health." << endl << endl;
            cout << "However, if you chose 1. Play Game, the intro screen would only display for the first time." << endl;
            cout << "if you play again, it won't display." << endl << endl;
            pressEnterToContinue();
            menuOption = 0;
            break;
        default:
            cout << "ERROR: Select an option that corresponds to a choice in the menu, then press ENTER." << endl << endl;
            pressEnterToContinue();
            menuOption = 0;
            break;
        }
        system("CLS");
    }


    return menuOption;
}

int mainGame(int playGameOption)
{
    /// ========================  DECLARATION OF VARIABLES  ==========================

    int playOption = 0;
    int gameResult = 0;

    while (playOption != 1 && playOption != 2)
    {
        cout << "Play on your own or auto solve?" << endl << endl;
        cout << "\t1. Play the game manually" << endl;
        cout << "\t2. Auto solve" << endl << endl;
        cin >> playOption;
        if (playOption != 1 && playOption != 2)
        {
            cout << "ERROR: Please enter a number that corresponds to a choice." << endl;
            Sleep(1500);
        }
        system("CLS");
    }

    // ========================  DECLARING VARIABLES BASED ON THE USER'S CHOICE  ==========================

    if (playOption == 1)
    {
        gameResult = userGame(playGameOption);
    }

    else if (playOption == 2)
    {
        gameResult = autoSolverGame();
    }

    return gameResult;
}

/// ========= STACK SOLVER FUNCTIONS =========

int autoSolverGame()
{
    Maze myMaze;
    Hero myHero;
    myHero.currentMaze(&myMaze);

    Stack movesForSolver; // this stack stores char not string
    movesForSolver.push('a');
    movesForSolver.push('w');
    movesForSolver.push('d');
    movesForSolver.push('s');

    int turnResult = 0;
    char m; // move
    char trail = ' ';

    myMaze.setBlock(myHero.getRowCoord(), myHero.getColCoord(), myHero.getCharType()); // set hero at the start

    while (turnResult == 0)
    {
        displayMazeEasy(myMaze);
        m = movesForSolver.peak();
        cout << endl;
        Sleep(10);

        switch (m) // regular move checker
        {
        case 'a':
        case 'A': // a or left
            turnResult = autoSolverCheckMove(myMaze, myHero.getLeftBlock());
            if (turnResult != 1 && myHero.getLeftBlock() != '<') // wall check + same direction check
            {
                if (turnResult == 50) // if Hero hits a trail
                {
                    if (myHero.getLeftBlock() == '>') // valid if block is opposite move
                    {
                        // nothing happens. continue to make the move
                    }
                    else
                        break;
                }
                trail = '<';
                myHero.setLeftBlock(trail);
            }
            break;
        case 'w':
        case 'W': // w or up
            turnResult = autoSolverCheckMove(myMaze, myHero.getTopBlock());
            if (turnResult != 1 && myHero.getTopBlock() != '^') // wall check + same direction check
            {
                if (turnResult == 50) // if Hero hits a trail
                {
                    if (myHero.getTopBlock() == 'v')
                    {
                        // nothing happens. continue to make the move
                    }
                    else
                        break;
                }
                trail = '^';
                myHero.setTopBlock(trail);
            }
            break;
        case 's':
        case 'S': // s or down
            turnResult = autoSolverCheckMove(myMaze, myHero.getBottomBlock());
            if (turnResult != 1 && myHero.getBottomBlock() != 'v') // wall check + same direction check
            {
                if (turnResult == 50) // if Hero hits a trail
                {
                    if (myHero.getBottomBlock() == '^')
                    {
                        // nothing happens. continue to make the move
                    }
                    else
                        break;
                }
                trail = 'v';
                myHero.setBottomBlock(trail);
            }
            break;
        case 'd':
        case 'D': // d or right
            turnResult = autoSolverCheckMove(myMaze, myHero.getRightBlock());
            if (turnResult != 1 && myHero.getRightBlock() != '>') // wall check + same direction check
            {
                if (turnResult == 50) // if Hero hits a trail
                {
                    if (myHero.getRightBlock() == '<')
                    {
                        // nothing happens. continue to make the move
                    }
                    else
                        break;
                }
                trail = '>';
                myHero.setRightBlock(trail);
            }
            break;
        default:
            cout << "Error in switch case section of the autoSolverGame function." << endl;
            cout << endl << endl;
            pressEnterToContinue();
            system("CLS");
            break;
        }

        /// ========================  CHECKING TURN CONDITION  ==========================
        /*
        This section determines what to do after the user or the auto solver has submitted a move

        ====================  "turnResult" CHART (autoSolver)  ===================
        -1  = program terminated
        0   = valid move to blank spot
        1   = just hit a wall
        50 = hit a move that has previously been on
        99  = obtained the key
        100 = win
        */
        // ============== win condition ===============
        if (turnResult == 0 || turnResult == KEYISTRUE) // 99 == key
        {
            movesForSolver.pop();
            refillStackAutoSolver(m, &movesForSolver);
        }
        else if (turnResult == 1) // hit a wall
        {
            movesForSolver.pop();
        }
        else if (turnResult == 50) // hits a trail
        {
            movesForSolver.pop();
        }
        cout << endl;
        // ====================  win condition (autoSolver)  =======================
        // erases all trails
        // autoSolver continues as if this is the starting position
        if (turnResult == KEYISTRUE)
        {
            myMaze.setBlock(12, 2, ' '); // the door in which the key WILL OPEN
            for (int i = 1; i < myMaze.getROW() - 1; i++) // check and clear row
            {
                for (int j = 1; j < myMaze.getCOLUMN() - 1; j++) // check and clear column
                {
                    for (int z = 0; z < 4; z++) // check if WASD is true
                    {
                        if (myMaze.getBlock(i, j) == myMaze.getTrailType(z))
                        {
                            myMaze.setBlock(i, j, ' ');
                        }
                    }
                }
            }
        }
        if (turnResult != WINISTRUE) // if solver has not finished solving or stack is empty
        {
            turnResult = 0; // reset turnResult to 0 so that the while loop will run
            clearScreen();
        }
        if (movesForSolver.getStackSize() <= 0)
        {
            system("CLS");
            cout << "Stack is EMPTY! This maze is not solvable." << endl << endl;
            turnResult = TERMINATE;
        }
    } // while loop
    pressEnterToContinue();
    system("CLS");

    return turnResult;
}

char oppositeMoveFinder(char m)
{
    char result;
    if (m == 'w')
    {
        result = 's';
    }
    else if (m == 'a')
    {
        result = 'd';
    }
    else if (m == 's')
    {
        result = 'w';
    }
    else if (m == 'd')
    {
        result = 'a';
    }
    else
    {
        cout << "ERROR IN THE oppositeMoveFinder FUNCTION." << endl;
        system("PAUSE");
    }
    return result;
}

void refillStackAutoSolver(char moveMade, Stack* originalStackOfMoves)
{
    /*
    This function automatically refills the stack with the move that reverses the recent move at the bottom
        of the stack and everything else on top of the stack
    */
    char oppositeMove;
    char WASD[4] = {'a', 'w', 'd', 's'};

    oppositeMove = oppositeMoveFinder(moveMade);
    originalStackOfMoves->push(oppositeMove); // push the backtracking move first
    for (int i = 0; i < 4; i++) // push every other move
    {
        if (WASD[i] != oppositeMove)
        {
            originalStackOfMoves->push(WASD[i]);
        }
    }
    return;
}

int autoSolverCheckMove(Maze _maze, char _blockContent)
{
    int check = 0;

    for (int i = 0; i < 4; i++) // check if auto solver has hit a spot it has previously been on
    {
        if (_blockContent == _maze.getTrailType(i))
        {
            check = 50;
            return check;
        }
    }
    if (_blockContent == _maze.getKey())
    {
        check = KEYISTRUE; // key obtained
    }
    else if (_blockContent == _maze.getWin())
    {
        check = WINISTRUE; // user won
    }
    else
    {
        for (int i = 0; i < 11; i++) // wall check
        {
            if (_blockContent == _maze.getWall(i)) // if wall == true
            {
                check = 1;
                i = 12; // if wall == true early then there is no need iterate the rest of the turnType array
            }
        } // for
    } // else

    return check;
}

/// ========= USER GAME FUNCTIONS =========

void userGameIntro(int playGameOption)
{
    int sleepTime = 2000;
    if (playGameOption == CHEATCODE)
    {
        sleepTime = 0;
    }
    string dialogue[4] =
    {
        {
            "The enemy has captured you and are on their way to attack your country!"
        },
        {
            "Due to your creative prison escape methods, they've placed you in a maze!"
        },
        {
            "You must escape this maze in order to stop the attack from happening!"
        },
        {
            "The door to reach the end of the maze is locked so you will have to find the KEY needed to unlock the door!"
        }
    };

    for (int i = 0; i < 4; i++)
    {
        cout << dialogue[i] << endl << endl;
        Sleep(sleepTime);
    }
    cout << "The door and the KEY are highlighted in ";
    setColor(14);
    cout << "GOLD." << endl << endl;
    setColor(7);
    Sleep(sleepTime);
    cout << "The door looks like this \t ";
    setColor(14);
    cout << (char)205 << endl;
    Sleep(sleepTime);
    setColor(7);
    cout << "The KEY looks like this  \t ";
    setColor(14);
    cout << "K" << endl << endl;
    setColor(7);
    Sleep(sleepTime);
    sleepTime += 1000;
    cout << "Beware as there are ";
    setColor(4);
    cout << "traps(T)";
    setColor(7);
    cout << " and ";
    setColor(4);
    cout << "monsters(M)";
    setColor(7);
    cout << " in the maze. If you are lucky, you may find a" << endl;
    setColor(2);
    cout << "\t healing potion(H)!" << endl << endl;
    setColor(7);
    Sleep(sleepTime);
    cout << "Go! Save your country before it's too late!!" << endl << endl;
    Sleep(sleepTime);
    system("CLS");
}

int userCheckMove(Maze _maze, char _blockContent)
{
    int check = 0;
    /*
        This section determines what to do after the user or the auto solver has submitted a move

        ====================  "turnResult" CHART (autoSolver)  ===================
        -1  = program terminated
        0   = valid move to blank spot
        1   = just hit a wall

        10 = monster
        15 = trap
        20 = healthPotion

        30 = randObject

        99  = obtained the key
        100 = win
    */
    if (_blockContent == _maze.getKey()) // KEY
    {
        check = KEYISTRUE; // key obtained
    }
    else if (_blockContent == _maze.getWin()) // WIN
    {
        check = WINISTRUE; // user won
    }
    else if (_blockContent == _maze.getMonster().getCharType())
    {
        check = MONSTERISTRUE;
    }
    else if (_blockContent == 'T')
    {
        check = TRAPISTRUE;
    }
    else if (_blockContent == 'H')
    {
        check = HEALTHPOTIONISTRUE;
    }
    else if (_blockContent == '?')
    {
        check = RANDOBJECTISTRUE;
    }
    else
    {
        for (int i = 0; i < 11; i++) // wall check
        {
            if (_blockContent == _maze.getWall(i)) // if wall == true
            {
                check = 1;
                i = 12; // if wall == true early then there is no need iterate the rest of the turnType array
            }
        } // for
    } // else

    return check;
}

int fightMonster(Hero * _hero, Monster _monster[])
{
    int fightResult = 0; // 0 means win, otherwise return TERMINATE
    int turnCounter = 0;
    bool winner = false;
    int randResult = 0;

    Monster tempMonster;
    for (int i = 0; i < 3; i++)
    {
        if (_hero->getRowCoord() == _monster[i].getRowCoord() && _hero->getColCoord() == _monster[i].getColCoord())
        {
            tempMonster = _monster[i];
            i = 3;
        }
    }

    while (winner == false)
    {
        setColor(HEROHEALTHCOLOUR);
        cout << "Hero health     : " << _hero->getHealth() << endl;
        setColor(12);
        cout << "Monster health  : " << tempMonster.getHealth() << endl << endl;
        setColor(7);

        pressEnterToContinue();

        cout << endl;

        if (turnCounter == 0)
        {
            _hero->setDamage(rand() % 31 + 10); // possible damage interval [10, 40] using interval notation
            setColor(HEROHEALTHCOLOUR);
            cout << "Hero attacks    : " << _hero->getDamage() << endl << endl;
            setColor(7);
            tempMonster.setHealth(tempMonster.getHealth() - _hero->getDamage());
            turnCounter++;
        }
        else if (turnCounter == 1)
        {
            tempMonster.setDamage(rand() % 30 + 1); // possible damage interval [1, 30] using interval notation
            setColor(12);
            cout << "Monster attacks : " << tempMonster.getDamage() << endl << endl;
            setColor(7);
            _hero->setHealth(_hero->getHealth() - tempMonster.getDamage());
            turnCounter--;
        }

        if (_hero->getHealth() <= 0 || tempMonster.getHealth() <= 0)
        {
            winner = true;
            if (_hero->getHealth() <= 0)
            {
                randResult = rand() % 2;
                if (randResult == 0)
                    cout << "\"You thought you could beat me? Well you thought wrong.\"" << endl << endl;
                else if (randResult == 1)
                    cout << "\"But... but the player is supposed to win every time!\" - You" << endl << endl;
                Sleep(3000);
                fightResult = TERMINATE;
            }
            else if (tempMonster.getHealth() <= 0)
                fightResult = 0;
            else
                cout << "ERROR IN THE fightMonster FUNCTION." << endl;
        }
        cin.ignore();
        pressEnterToContinue();
        system("CLS");
    }

    return fightResult;
}

int userGame(int playGameOption)
{
    /// Variables / constructors
    Maze myMaze;
    Hero myHero;

    Monster myMonster[3] = {};
    MazeObject healthPotion[5] = {};
    MazeObject trap[3] = {};
    MazeObject randObject[3] = {};

    int difficultySetting = 0;
    int turnResult = 0;
    char m; // move
    char trail = ' ';
    int randResult = 0;

    myHero.currentMaze(&myMaze); // lets the hero know which maze it is in
    myMaze.setBlock(myHero.getRowCoord(), myHero.getColCoord(), myHero.getCharType()); // set hero in the maze

    while (difficultySetting != 1 && difficultySetting != 2)
    {
        cout << "Select difficulty." << endl << endl;
        cout << "\t1. Extremely easy" << endl;
        cout << "\t2. Extremely hard" << endl << endl;
        cin >> difficultySetting;
        if (difficultySetting != 1 && difficultySetting != 2)
        {
            cout << "ERROR: Please enter a number that corresponds to a choice." << endl;
            Sleep(1500);
        }
        system("CLS");
    }

    /// setting coordinates of objects and placing them in the maze
    myMonster[0].setCoord(3, 9);
    myMonster[1].setCoord(6, 1);
    myMonster[2].setCoord(11, 11);
    for (int i = 0; i < 3; i++) // placing in maze
    {
        myMaze.setBlock(myMonster[i].getRowCoord(), myMonster[i].getColCoord(), myMonster[i].getCharType());
    }

    healthPotion[0].setCoord(7, 3);
    healthPotion[1].setCoord(1, 11);
    healthPotion[2].setCoord(2, 9);
    healthPotion[3].setCoord(1, 9);
    healthPotion[4].setCoord(11, 3);
    for (int i = 0; i < 5; i++) // placing in maze
    {
        healthPotion[i].setCharType('H');
        myMaze.setBlock(healthPotion[i].getRowCoord(), healthPotion[i].getColCoord(), healthPotion[i].getCharType());
    }

    trap[0].setCoord(6, 5);
    trap[1].setCoord(1, 13);
    trap[2].setCoord(5, 1);
    for (int i = 0; i < 3; i++) // placing in maze
    {
        trap[i].setCharType('T');
        myMaze.setBlock(trap[i].getRowCoord(), trap[i].getColCoord(), trap[i].getCharType());
    }

    randObject[0].setCoord(3, 11);
    randObject[1].setCoord(6, 3);
    randObject[2].setCoord(9, 9);
    for (int i = 0; i < 3; i++) // placing in maze
    {
        randObject[i].setCharType('?');
        myMaze.setBlock(randObject[i].getRowCoord(), randObject[i].getColCoord(), randObject[i].getCharType());
    }

    // CHEAT CODE ACTIVATES
    if (playGameOption == CHEATCODE)
        myHero.setHealth(999999);

    if (FIRSTPLAY == false)
    {
        userGameIntro(playGameOption);
    }

    while (turnResult == 0) // begin game loop for the user
    {
        setColor(HEROHEALTHCOLOUR);
        cout << "HEALTH: " << myHero.getHealth() << endl << endl;
        setColor(7);
        if (difficultySetting == 1)
            displayMazeEasy(myMaze);
        else if (difficultySetting == 2)
            displayMazeHard(myMaze, myHero);
        else
            cout << "ERROR: Cannot display Maze in the userGame() function." << endl;
        m = getch();
        cout << endl;
        switch (m) // regular move checker
        {
        case 'a':
        case 'A': // a or left
            turnResult = userCheckMove(myMaze, myHero.getLeftBlock());
            if (turnResult != 1) // if the the block is not a wall, proceed to move hero
            {
                myHero.setLeftBlock(trail);
            }
            break;
        case 'w':
        case 'W': // w or up
            turnResult = userCheckMove(myMaze, myHero.getTopBlock());
            if (turnResult != 1)
            {
                myHero.setTopBlock(trail);
            }
            break;
        case 's':
        case 'S': // s or down
            turnResult = userCheckMove(myMaze, myHero.getBottomBlock());
            if (turnResult != 1)
            {
                myHero.setBottomBlock(trail);
            }
            break;
        case 'd':
        case 'D': // d or right
            turnResult = userCheckMove(myMaze, myHero.getRightBlock());
            if (turnResult != 1)
            {
                myHero.setRightBlock(trail);
            }
            break;
        case 27:
            system("CLS");
            cout << "PROGRAM TERMINATED." << endl << endl;
            turnResult = TERMINATE;
            break;
        default:
            cout << "Error: Use the WASD pad to control your character." << endl;
            cout << "       Enter ESC at anytime to quit." << endl;
            cout << endl << endl;
            pressEnterToContinue();
            system("CLS");
            break;
        }
        /// ========================  CHECKING TURN CONDITION  ==========================
        /*
        This section determines what to do after the user or the auto solver has submitted a move

        ====================  "turnResult" CHART (user) ===================
        Refer to userCheckMove() function;
        */
        // ============== turnResult conditions ===============
        if (turnResult == RANDOBJECTISTRUE)
        {
            randResult = rand() % 3 + 1;
            if (randResult == 1)
                turnResult = MONSTERISTRUE;
            else if (randResult == 2)
                turnResult = TRAPISTRUE;
            else if (randResult == 3)
                turnResult = HEALTHPOTIONISTRUE;
            else
                cout << "ERROR IN \"win condition\" SECTION OF userGame() FUNCTION." << endl;
        }
        if (turnResult == KEYISTRUE) // 99 == key
        {
            myMaze.setBlock(12, 2, ' '); // opens the door since the key is obtained
        }
        else if (turnResult == MONSTERISTRUE)
        {
            setColor(12);
            cout << "MONSTER ENCOUNTERED. BEGIN FIGHT!!" << endl << endl;
            setColor(7);
            pressEnterToContinue();
            system("CLS");
            turnResult = fightMonster(&myHero, myMonster);
        }
        else if (turnResult == TRAPISTRUE)
        {
            setColor(12);
            cout << "TRAP ENCOUNTERED. YOU LOST 30 HEALTH." << endl << endl;
            setColor(7);
            myHero.setHealth(myHero.getHealth() - 30);
            if (myHero.getHealth() <= 0)
            {
                randResult = rand() % 4;
                if (randResult == 0 && difficultySetting == 2)
                    cout << "\"Roses are red, violets are blue. Your curiosity killed you.\"";
                else if (randResult == 1 && difficultySetting == 2)
                    cout << "\"I thought behind this trap was a large reward.\" - You";
                else if (randResult == 2)
                    cout << "\"Wh... THAT WAS A TRAP!?\" - You right now";
                else
                    cout << "\"Curiosity killed the cat.\"";
                cout << endl << endl;
                Sleep(3000);
                turnResult = TERMINATE;
            }
            getch();
            system("CLS");
        }
        else if (turnResult == HEALTHPOTIONISTRUE)
        {
            setColor(2);
            cout << "HEALTH POTION RECEIVED. YOU GAINED 20 HEALTH." << endl << endl;
            setColor(7);
            myHero.setHealth(myHero.getHealth() + 20);
            //pressEnterToContinue();
            getch();
            system("CLS");
        }
        if (turnResult != WINISTRUE && turnResult != TERMINATE) // if user has not won
        {
            turnResult = 0; // reset turnResult to 0 so that the while loop will run
            clearScreen();
        }
    } // while loop
    pressEnterToContinue();
    system("CLS");

    return turnResult; // returning to int main()
}

/// ========= INT MAIN =========

int main()
{
    showConsoleCursor(false);
    int mainGameResult = 0;
    int playGameOption = 1;
    srand(time(nullptr));

    while (playGameOption == 1 || playGameOption == CHEATCODE)
    {
        playGameOption = startingMenu();
        while (playGameOption == 1 || playGameOption == CHEATCODE)
        {
            cout << "Loading game..." << endl;
            Sleep(1000);
            system("CLS");
            // begin game
            mainGameResult = mainGame(playGameOption);
            FIRSTPLAY = true;
            if (mainGameResult == WINISTRUE)
            {
                cout << "YOU ESCAPED THE MAZE AND PREVENTED YOUR COUNTRY FROM IMMINENT DANGER!" << endl << endl;
            }
            else if (mainGameResult == TERMINATE)
            {
                cout << "YOU LOST! YOUR COUNTRY HAS BEEN DEMOLISHED BY THE ENEMY! IT'S GONE. REDUCED TO ATOMS." << endl << endl;
            }
            else
            {
                cout << "MainGameResult error." << endl << endl;
            }
            cout << "Loading..." << endl << endl;
            Sleep(1000);
            pressEnterToContinue();
            system("CLS");
            playGameOption = startingMenu();
        }
    }
    cout << "Thank you for playing my Maze Game!" << endl << endl;
    cout << "Sincerely," << endl;
    cout << "Kien Do" << endl << endl;

    return 0;
}

