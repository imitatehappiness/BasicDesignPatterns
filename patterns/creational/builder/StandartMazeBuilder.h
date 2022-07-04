#ifndef STANDARTMAZEBUILDER_H
#define STANDARTMAZEBUILDER_H

#include "Maze.h"
#include "Room.h"
#include "Wall.h"
#include "Direction.h"
#include "MazeBuilder.h"
#include <iostream>
using namespace std;

class StandardMazeBuilder : public MazeBuilder{
public:
    virtual void  buildMaze();
    virtual void  buildRoom(int);
    virtual void  buildDoor(int, int);
    virtual Maze* getMaze();

private:
    Direction commonWall(Room*, Room*);
    Maze* mCurrentMaze;
};

void StandardMazeBuilder::buildMaze(){
    mCurrentMaze = new Maze;
}

void StandardMazeBuilder::buildRoom(int id){
    Room* room = new Room(id);
    mCurrentMaze->addRoom(room);

    room->setSide(NORTH, new Wall);
    room->setSide(SOUTH, new Wall);
    room->setSide(EAST,  new Wall);
    room->setSide(WEST,  new Wall);
}

void StandardMazeBuilder::buildDoor(int from, int to){
    vector<Room*> rooms = mCurrentMaze->getRooms();

    int isOpen = rand() % 2;

    Door* door = new Door(rooms[from], rooms[to], isOpen);
    rooms[from]->setSide(commonWall(rooms[from], rooms[to]), door);
    rooms[to]->setSide(commonWall(rooms[to], rooms[from]), door);


    mCurrentMaze->addDoor(door);
}

Maze *StandardMazeBuilder::getMaze(){
    return mCurrentMaze;
}

Direction StandardMazeBuilder::commonWall(Room *, Room *){
    int directionInd = rand() % 4 + 1;
    Direction direction = static_cast<Direction>(directionInd);
    return direction;
}

#endif
