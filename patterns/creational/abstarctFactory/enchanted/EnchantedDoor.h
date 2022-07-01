#include "Door.h"
#include "Room.h"

class EnchantedDoor : public Door {
public:
    EnchantedDoor(Room* room1, Room* room2, bool isOpen) :  Door(room1, room2, isOpen){
    }

    virtual void open(){
        //logic
    }
};
