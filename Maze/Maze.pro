TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../patterns/creational/abstarctFactory/MazeFactory.h \
    ../patterns/creational/abstarctFactory/bombed/BombedMazeFactory.h \
    ../patterns/creational/abstarctFactory/bombed/BombedRoom.h \
    ../patterns/creational/abstarctFactory/bombed/BombedWall.h \
    ../patterns/creational/abstarctFactory/enchanted/EnchantedDoor.h \
    ../patterns/creational/abstarctFactory/enchanted/EnchantedMazeFactory.h \
    ../patterns/creational/abstarctFactory/enchanted/EnchantedWall.h \
    DesignPatterns.h \
    Direction.h \
    Door.h \
    MapSide.h \
    Maze.h \
    MazeGame.h \
    Room.h \
    Wall.h
