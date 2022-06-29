#include <iostream>
#define SIMPLE

using namespace std;

namespace PatternAbstractFactory{

class Shape {
public:
    Shape(){
        mID = mTotal++;
    }
    virtual void draw() = 0;
protected:
    int mID;
    static int mTotal;
};

int Shape::mTotal = 0;

/// @class Circle - AbstructProduct
class Circle : public Shape {
public:
    void draw() {
        cout << "circle " << mID << ": draw" << endl;
    }
};

/// @class Square - AbstructProduct
class Square : public Shape {
public:
    void draw() {
        cout << "square " << mID << ": draw" << endl;
    }
};

/// @class Ellipse - AbstructProduct
class Ellipse : public Shape {
public:
    void draw() {
        cout << "ellipse " << mID << ": draw" << endl;
    }
};

/// @class Rectangle - AbstructProduct
class Rectangle : public Shape {
public:
    void draw() {
        cout << "rectangle " << mID << ": draw" << endl;
    }
};

/// @class Factory - AbstructFactory
class Factory {
public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory {
public:
    Shape* createCurvedInstance() {
        return new Circle;
    }
    Shape* createStraightInstance() {
        return new Square;
    }
};

class RobustShapeFactory : public Factory {
public:
    Shape* createCurvedInstance()   {
        return new Ellipse;
    }
    Shape* createStraightInstance() {
        return new Rectangle;
    }
};

}


int main() {
#ifdef SIMPLE
    PatternAbstractFactory::Factory* factory = new PatternAbstractFactory::SimpleShapeFactory;
#elif ROBUST
    PatternAbstractFactory::Factory* factory = new PatternAbstractFactory::RobustShapeFactory;
#endif
    PatternAbstractFactory::Shape* shapes[3];

    shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Ellipse;
    shapes[1] = factory->createStraightInstance(); // shapes[1] = new Rectangle;
    shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Ellipse;

    for (int i=0; i < 3; i++) {
        shapes[i]->draw();
    }

}
