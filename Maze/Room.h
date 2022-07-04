#ifndef ROOM_H
#define ROOM_H
#include "MapSide.h"
#include "vector"
#include "Direction.h"
#include <iostream>

class Room : public MapSide {
public:
    Room(int id) : mId(id) {
        sites.resize(4);
    }

    void setSide(Direction direction, MapSide* mapSide) {
        int directionInd = static_cast<int>(direction);
        sites[directionInd] = mapSide;
    }

    MapSide* getSide(Direction direction) {
        size_t directionInd = static_cast<size_t>(direction);
        return sites[directionInd];
    }

    Room* clone() {
        Room* clone = new Room(mId);
        for(size_t i = 0; i < sites.size(); i++){
            clone->sites[i] = sites[i];
        }
        return clone;
    }

    int getId() {
        return mId;
    }
    void setId(int id){
        mId = id;
    }
    virtual void enter(){
    }

private:
    std::vector<MapSide*> sites;
    int mId;
};
#endif // ROOM_H
