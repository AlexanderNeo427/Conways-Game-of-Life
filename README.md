# Conway's Game of Life

Demo video: https://www.youtube.com/watch?v=tg9Nu65zjOE

For the uninitiated, Conway's Game of Life is a Cellular Automata. 
From Google, "A cellular automaton is a collection of cells on a grid of specified shape that evolves through a number of discrete time steps according to a set of rules based on the states of neighboring cells".
In this case, each small coloured square you see is a cell in the grid, and every time you see a change, that means all cells were just updated in unison according to the state of their neighbours.
Despite being quite rudimentary (each cell operates on only 3 rules), Conway's Game of Life helped popularise Cellular Automata due to the fact that interesting behaviour could emerge from such simple rules.

Technical Details: 
* Grid is represented as a 2D array of bools under the hood
* Made with C++ and the olcPixelGameEngine for rendering. Threw in some ombre colouring for the aesthetics, each "live" cell's colour is decided by it's position in the grid.
