#ifndef MAZEGAME_H
#define MAZEGAME_H
#include "Direction.h"
#include "Door.h"
#include "MapSide.h"
#include "Maze.h"
#include "Room.h"
#include "Wall.h"
#include <string>
#include "DesignPatterns.h"
#include "../patterns/creational/abstarctFactory/MazeFactory.h"
#include "../patterns/creational/abstarctFactory/enchanted/EnchantedMazeFactory.h"
#include "../patterns/creational/abstarctFactory/bombed/BombedMazeFactory.h"

class MazeGame {
public:
    void startGame(DesignPattern designPattern) {
        Maze* maze;

        switch(designPattern) {
            case AbstractFactory: maze = createMazeWithAbstractFactory(new EnchantedMazeFactory());
        }
    }

    Maze* createMazeWithAbstractFactory(MazeFactory* factory) {
        Maze* maze = factory->makeMaze();
        Room* room1 = factory->makeRoom(1);
        Room* room2 = factory->makeRoom(2);
        Door* doors = factory->makeDoor(room1, room2);

        maze->addRoom(room1);
        maze->addRoom(room2);

        room1->setSide(NORTH, factory->makeWall());
        room1->setSide(WEST,  factory->makeWall());
        room1->setSide(SOUTH, doors);
        room1->setSide(EAST,  factory->makeWall());

        room2->setSide(NORTH, doors);
        room2->setSide(WEST,  factory->makeWall());
        room2->setSide(SOUTH, factory->makeWall());
        room2->setSide(EAST,  factory->makeWall());

        return maze;
    }
};
#endif // MAZEGAME_H
