#include <iostream>
#define FIRST_MIX

using namespace std;

namespace PatternAbstractFactory{

class Pizza {
public:
    Pizza(){
        mID = mTotal++;
    }
    virtual void draw() = 0;
protected:
    int mID;
    static int mTotal;
};

int Pizza::mTotal = 0;

/// @class Circle - AbstructProduct
class HamAndMushroomPizza: public Pizza {
public:
    void draw() {
        cout << "HamAndMushroomPizza " << mID << endl;
    }
};

/// @class Square - AbstructProduct
class DeluxePizza: public Pizza {
public:
    void draw() {
        cout << "DeluxePizza " << mID << endl;
    }
};

/// @class Ellipse - AbstructProduct
class HawaiianPizza: public Pizza {
public:
    void draw() {
        cout << "HawaiianPizza " << mID << endl;
    }
};

/// @class Factory - AbstructFactory
class Factory {
public:
    virtual Pizza* createFirstPizza() = 0;
    virtual Pizza* createSecondPizza() = 0;
};

class MixOneFactory : public Factory {
public:
    Pizza* createFirstPizza() {
        return new HamAndMushroomPizza;
    }
    Pizza* createSecondPizza() {
        return new DeluxePizza;
    }
};

class MixSecondFactory : public Factory {
public:
    Pizza* createFirstPizza()   {
        return new DeluxePizza;
    }
    Pizza* createSecondPizza() {
        return new HawaiianPizza;
    }
};

}

int main() {
#ifdef FIRST_MIX
    PatternAbstractFactory::Factory* factory = new PatternAbstractFactory::MixOneFactory;
#elif SECOND_MIX
    PatternAbstractFactory::Factory* factory = new PatternAbstractFactory::MixSecondFactory;
#endif
    PatternAbstractFactory::Pizza* pizzas[3];

    pizzas[0] = factory->createFirstPizza();   // shapes[0] = new Ellipse;
    pizzas[1] = factory->createSecondPizza();  // shapes[1] = new Rectangle;
    pizzas[2] = factory->createFirstPizza();   // shapes[2] = new Ellipse;

    for (int i=0; i < 3; i++) {
        pizzas[i]->draw();
    }
    return 0;
}
