#ifndef ROOM_H
#define ROOM_H
#include "MapSide.h">
#include "vector"
#include "Direction.h"
class Room : public MapSide {
public:
    void setSide(Direction direction, MapSide* mapSide) {

    }
    MapSide* getSide(Direction direction) {
        return nullptr;
    }
    int getId() {
        return mId;
    }
    void setId(int id) {
        mId = id;
    }
    virtual void enter() {
        // logic
    }
    Room* clone() {
        Room* clone = new Room(mId);
        for(MapSide* site : sites){
            clone->sites.push_back(site);
        }
        return clone;
    }

    Room(int id) : mId(id) {
    }
private:
    std::vector<MapSide*> sites;
    int mId;


};
#endif // ROOM_H
