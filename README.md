# Maze-Game

SUMMARY OF MAZE GAME PROJECT (for detailed rubric, see "Project Rubric" below)

Functionality:
- A maze game with user navigation, user interaction with objects and monsters.
- Contains a custom, self-made Depth-First Search (DFS) algorithm that automatically determines the solution to the maze.
- Contains two difficulty settings.
- Contains a cheat code that skips the Intro Menu and gives the user 9999999 health.

Programming Concepts:
- Objects and Classes
- Inheritance
- Custom Depth-first search (DFS) maze solving algorithm
- Custom stack used for maze solving algorithm
- Pointers

==============================              PROJECT RUBRIC              ==============================

Description: Your task is to create a game that requires the user to navigate a maze and interact with objects and other beings inside the maze. The game should end when either the user’s character dies or the character reaches the exit of the maze.

The game should have two settings.

The user controls the movement through the maze.
The program solves the maze on its own.
Your program MUST use the programming concepts described in the programming requirements.

Functionality Requirements:

General: (These must be satisfied in both settings)
- The program should offer a choice of the settings: user controlled and auto movement. 
- The program should end when either the character dies or the character reaches the exit of the maze.
- The maze should be solvable.
- There must be at least one object/location in the maze that is necessary to find/reach before the maze becomes solvable. • Your maze must contain a loop to demonstrate that the character can escape the loop.

User controlled: 
- There should be objects within the maze with which the character interacts. Ex: keys, potions, traps, etc…
- There should be beings in the maze other than the main character. These could be monsters to fight, or beings that ask you riddles etc…

Auto Solver
- The program should control the movement of the character.
- The program should be methodical as to choosing directions to try. It should not pick directions randomly.
- This setting does not require the other “beings” or any objects not necessary to solving the maze. Ex: If there is a key to open a door it should exist in this setting. If there is a potion that only increases your health it does not need to exist in this setting.

Programming Requirements:
- Objects should be used for all aspects of the game.
- Inheritance must be used somewhere in your program
- Pointers should be used in your program to facilitate passing information to functions.
- You must use a STACK for your auto-solver.
- You must program your own stack. You may not use a library.

Other Requirements:

You should comment your code.
Your program must use proper programming style (see rubric).
Your code should be reasonably efficient. ie: If your program repeats code unnecessarily, if a function would be more appropriate, or if variables are duplicated rather than passed to functions, this does not represent Level 4 efficiency.
