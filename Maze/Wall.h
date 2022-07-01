#ifndef WALL_H
#define WALL_H
#include "MapSide.h"

class Wall : public MapSide {
public:
    Wall(){}

    virtual void enter(){}

    Wall* clone() {
        return new Wall();
    }
};

#endif // WALL_H
