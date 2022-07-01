#ifndef MAZEFACTORY_H
#define MAZEFACTORY_H

#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"

class MazeFactory {
public:
    virtual Maze* makeMaze() = 0;
    virtual Room* makeRoom(int id) = 0;
    virtual Door* makeDoor(Room* from, Room* to) = 0;
    virtual Wall* makeWall() = 0;
};

#endif
