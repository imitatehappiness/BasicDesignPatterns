#ifndef ROOM_H
#define ROOM_H
#include <MapSide.h>
#include <vector>
#include <Direction.h>
class Room : public MapSide {
public:
    void setSide(Direction direction, MapSide mapSite) {

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
        for(MapSide* site : sites)
            clone->sites.push_back(site);
        return clone;
    }

private:
    std::vector<MapSide*> sites;
    int mId;
    Room(int id) : mId(id) {
    }

};
#endif // ROOM_H
