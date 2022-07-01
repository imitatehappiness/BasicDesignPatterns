#ifndef DOOR_H
#define DOOR_H
#include "MapSide.h"
#include "Room.h"
class Door : public MapSide{
public:
    Door(Room* room1, Room* room2, bool isOpen):
        mRoom1(room1), mRoom2(room2), mIsOpen(isOpen) {
    }

    virtual void open() {
        // logic
    }

    virtual void enter() {
        // logic
    }

    Door* clone(Room* clonedRoom1, Room* clonedRoom2) {
        return new Door(clonedRoom1, clonedRoom2, mIsOpen);
    }

    Room* mRoom1;
    Room* mRoom2;
    bool mIsOpen;
};

#endif // DOOR_H
