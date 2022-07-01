#include "Room.h"

class BombedRoom : public Room {
public:
    BombedRoom(int id): Room(id){
    }

    virtual void enter() {
        // Logic
    }

private:
};
