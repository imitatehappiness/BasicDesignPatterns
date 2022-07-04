#ifndef MAZEPROTOTYPEFACTORY_H
#define MAZEPROTOTYPEFACTORY_H

#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"
#include "../patterns/creational/abstarctFactory/MazeFactory.h"
class MazePrototypeFactory : public MazeFactory{
public:
    MazePrototypeFactory(Maze* prototypeMaze, Wall* prototypeWall, Room* prototypeRoom, Door* prototypeDoor):
        mPrototypeMaze(prototypeMaze), mPrototypeWall(prototypeWall),
        mPrototypeRoom(prototypeRoom), mPrototypeDoor(prototypeDoor){
    }

    Maze* makeMaze() {
        return mPrototypeMaze->clone();
    }

    Room* makeRoom(int id) {
        Room* product = mPrototypeRoom->clone();
        product->setId(id);
        return product;
    }

    Door* makeDoor(Room* from, Room* to) {
        return mPrototypeDoor->clone(from, to, rand() % 2);
    }

    Wall* makeWall() {
        return mPrototypeWall->clone();
    }

private:
    Maze* mPrototypeMaze;
    Wall* mPrototypeWall;
    Room* mPrototypeRoom;
    Door* mPrototypeDoor;
};
#endif
