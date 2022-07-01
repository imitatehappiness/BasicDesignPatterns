TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../patterns/creational/MazeFactory.cpp \
        ../patterns/creational/MazeFactory.cpp \
        ../patterns/creational/MazeFactory.cpp \
        ../patterns/creational/bombed/BombedMazeFactory.cpp \
        ../patterns/creational/bombed/BombedMazeFactory.cpp \
        ../patterns/creational/bombed/BombedRoom.cpp \
        ../patterns/creational/bombed/BombedRoom.cpp \
        ../patterns/creational/bombed/BombedWall.cpp \
        ../patterns/creational/bombed/BombedWall.cpp \
        ../patterns/creational/enchanted/EnchantedDoor.cpp \
        ../patterns/creational/enchanted/EnchantedDoor.cpp \
        ../patterns/creational/enchanted/EnchantedMazeFactory.cpp \
        ../patterns/creational/enchanted/EnchantedMazeFactory.cpp \
        ../patterns/creational/enchanted/EnchantedWall.cpp \
        ../patterns/creational/enchanted/EnchantedWall.cpp \
        main.cpp

HEADERS += \
    Direction.h \
    Door.h \
    MapSide.h \
    Maze.h \
    MazeGame.h \
    Room.h \
    Wall.h
