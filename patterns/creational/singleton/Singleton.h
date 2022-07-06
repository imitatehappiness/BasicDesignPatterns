#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include "Maze.h"
#include "Door.h"
#include "Wall.h"
#include "Room.h"


class SingletonMazeFactory {
public:
    static SingletonMazeFactory* getInstance() {
        if (instance == nullptr){
            instance = new SingletonMazeFactory();
        }
        return instance;
    }
    Maze* makeMaze() {
        return new Maze();
    }
    Room* makeRoom(int id) {
        return new Room(id);
    }
    Wall* makeWall() {
        return new Wall();
    }
    Door* makeDoor(Room* from, Room* to) {
        return new Door(from, to, true);
    }
protected:
    SingletonMazeFactory(){
    }
    //SingletonMazeFactory(const SingletonMazeFactory&);
    //SingletonMazeFactory& operator =(const SingletonMazeFactory&);
private:
    static SingletonMazeFactory* instance;
};

SingletonMazeFactory* SingletonMazeFactory::instance = nullptr;

#endif
