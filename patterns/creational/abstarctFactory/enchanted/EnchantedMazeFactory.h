#include "../patterns/creational/abstarctFactory/MazeFactory.h"
#include "../patterns/creational/abstarctFactory/enchanted/EnchantedDoor.h"
#include "../patterns/creational/abstarctFactory/enchanted/EnchantedWall.h"
#include "Room.h"
#include "Maze.h"
#include <iostream>
class EnchantedMazeFactory : public MazeFactory {
public:
    virtual Maze* makeMaze() {
        return new Maze();
    }
    virtual Room* makeRoom(int id) {
        return new Room(id);
    }
    virtual Wall* makeWall() {
        return new EnchantedWall();
    }
    virtual Door* makeDoor(Room* from, Room* to) {
        return new EnchantedDoor(from, to, rand() % 2);
    }
};
