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

    room->setSide(NORTH, new Wall);
    room->setSide(SOUTH, new Wall);
    room->setSide(EAST,  new Wall);
    room->setSide(WEST,  new Wall);

    mCurrentMaze->addRoom(room);
}

void StandardMazeBuilder::buildDoor(int from, int to){
    vector<Room*> rooms = mCurrentMaze->getRooms();

    Door* door = new Door(rooms[from], rooms[to], rand() % 2);
    rooms[from]->setSide(commonWall(rooms[from], rooms[to]), door);
    rooms[to]->setSide(commonWall(rooms[to], rooms[from]), door);

    mCurrentMaze->addDoor(door);
}

Maze* StandardMazeBuilder::getMaze(){
    return mCurrentMaze;
}

Direction StandardMazeBuilder::commonWall(Room* room1, Room* room2){
    return static_cast<Direction>(rand() % 4);
}

#endif
