#ifndef STANDARTMAZEBUILDER_H
#define STANDARTMAZEBUILDER_H

#include "Maze.h"
#include "Room.h"
#include "Direction.h"
#include "MazeBuilder.h"
#include <iostream>
using namespace std;

class StandardMazeBuilder : public MazeBuilder{
public:
   // StandardMazeBuilder();

    virtual void  buildMaze();
    virtual void  buildRoom(int);
    virtual void  buildDoor(int, int);
    virtual Maze* getMaze();

private:
    Direction commonWall(Room*, Room*);
    Maze* mCurrentMazel;
};

void StandardMazeBuilder::buildMaze(){
    mCurrentMazel = new Maze;
}

void StandardMazeBuilder::buildRoom(int id){
    mCurrentMazel->addRoom(new Room(id));
}

void StandardMazeBuilder::buildDoor(int from, int to){
    vector<Room*> rooms = mCurrentMazel->getRooms();

    Door* door = new Door(rooms[from], rooms[to], rand() % 2);
    rooms[from]->setSide(commonWall(rooms[from], rooms[to]), door);
    rooms[to]->setSide(commonWall(rooms[to], rooms[from]), door);

    mCurrentMazel->addDoor(door);
}

Maze *StandardMazeBuilder::getMaze(){
    return mCurrentMazel;
}

Direction StandardMazeBuilder::commonWall(Room *, Room *){
    return NORTH;
}

#endif
