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
#include "../patterns/creational/builder/MazeBuilder.h"
#include "../patterns/creational/builder/StandartMazeBuilder.h"
#include "../patterns/creational/prototype/MazePrototypeFactory.h"
#include "../patterns/creational/singleton/Singleton.h"
#include <iostream>
using namespace std;

class MazeGame {
public:
    void startGame(DesignPattern designPattern) {
        Maze* maze;

        switch(designPattern) {
        case AbstractFactory: maze = createMazeWithAbstractFactory(new EnchantedMazeFactory());
        case Builder: maze = createMazeWithMazeBuilder(new StandardMazeBuilder());
        case Prototype: maze = createMazeWithPrototypeFactory();
        case Singleton: maze = createMazeWithSingletonFactory();
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

    Maze* createMazeWithMazeBuilder(MazeBuilder* builder) {
        builder->buildMaze();
        builder->buildRoom(0);
        builder->buildRoom(1) ;
        builder->buildDoor(0, 1);

        return builder->getMaze();
    }

    Maze* createMazeWithPrototypeFactory(){
        MazePrototypeFactory* bombedFactory = new MazePrototypeFactory(
                    new Maze(),
                    new BombedWall(),
                    new BombedRoom(0),
                    new Door(new BombedRoom(0), new BombedRoom(0), true)
                    );

        Maze* maze  = bombedFactory->makeMaze();
        Room* room1 = bombedFactory->makeRoom(1);
        Room* room2 = bombedFactory->makeRoom(2);
        Door* door  = bombedFactory->makeDoor(room1, room2) ;

        maze->addRoom(room1);
        maze->addRoom(room2);

        room1->setSide(NORTH, bombedFactory->makeWall());
        room1->setSide(WEST,  bombedFactory->makeWall());
        room1->setSide(SOUTH, door);
        room1->setSide(EAST,  bombedFactory->makeWall());

        room2->setSide(NORTH, door);
        room2->setSide(WEST,  bombedFactory->makeWall());
        room2->setSide(SOUTH, bombedFactory->makeWall());
        room2->setSide(EAST,  bombedFactory->makeWall());

        return maze;
    }

    Maze* createMazeWithSingletonFactory() {
        SingletonMazeFactory* factory = SingletonMazeFactory::getInstance();

        Maze* maze = factory->makeMaze();
        Room* room1 = factory->makeRoom(1);
        Room* room2 = factory->makeRoom(2);
        Door* door = factory->makeDoor(room1, room2);

        maze->addRoom(room1);
        maze->addRoom(room2);

        room1->setSide(NORTH, factory->makeWall());
        room1->setSide(WEST,  factory->makeWall());
        room1->setSide(SOUTH, door);
        room1->setSide(EAST,  factory->makeWall());

        room2->setSide(NORTH, door);
        room2->setSide(WEST,  factory->makeWall());
        room2->setSide(SOUTH, factory->makeWall());
        room2->setSide(EAST,  factory->makeWall());

        return maze;
    }

};
#endif // MAZEGAME_H
