#ifndef MAZE_H
#define MAZE_H

#include "MapSide.h"
#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include <vector>

class Maze {
public:
    Maze() {}

    void addRoom(Room* room) {
        mRooms.push_back(room);
    }
    void addDoor(Door* door) {
        mDoors.push_back(door);
    }
    Room* findRoom(int id) {
        // logic
        return mRooms[id];
    }
    std::vector<Room*> getRooms() {
        return mRooms;
    }
    std::vector<Door*> getDoors() {
        return mDoors;
    }
    Maze* clone() {
        Maze* clone = new Maze();

        for (size_t i = 0; i < mRooms.size(); i++){
            clone->mRooms.push_back(mRooms[i]);
        }
        for (size_t i = 0; i < mDoors.size(); i++) {
            Door* clonedDoor = mDoors[i];
            clone->mDoors.push_back(clonedDoor->clone(mRooms[clonedDoor->mRoom1->getId()], mRooms[clonedDoor->mRoom2->getId()]));
        }
        return clone;
    }
private:
    std::vector<Room*> mRooms;
    std::vector<Door*> mDoors;
};

#endif // MAZE_H
