#ifndef MAZEBUILDER_H
#define MAZEBUILDER_H

#include "Maze.h"
#include <iostream>
using namespace std;

class MazeBuilder{
public:
    virtual void  buildMaze() = 0;
    virtual void  buildRoom(int room) = 0;
    virtual void  buildDoor(int from, int to) = 0;
    virtual Maze* getMaze() = 0;
};

#endif
