#include "../patterns/creational/abstarctFactory/MazeFactory.h"
#include "../patterns/creational/abstarctFactory/bombed/BombedRoom.h"
#include "../patterns/creational/abstarctFactory/bombed/BombedWall.h"
#include "Room.h"
#include "Maze.h"

class BombedMazeFactory : public MazeFactory {
public:
    virtual Maze* makeMaze() {
        return nullptr;
    }

    virtual Door* makeDoor(Room from, Room to) {
        return nullptr;
    }

    virtual Room* makeRoom(int id) {
        return  new BombedRoom(id);
    }

    virtual Wall* makeWall() {
        return new BombedWall();
    }
};
