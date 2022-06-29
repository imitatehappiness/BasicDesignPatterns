#include <stdexcept>
#include <iostream>
#include <memory>

using namespace std;

namespace PatternFactoryMethod{

/// @class Pizza - Product
class Pizza {
public:
    virtual int getPrice() const = 0;
    virtual ~Pizza() {};  /* without this, no destructor for derived Pizza's will be called. */
};

/// @class HamAndMushroomPizza - ConcreteProduct
class HamAndMushroomPizza : public Pizza {
public:
    virtual int getPrice() const { return 850; };
    virtual ~HamAndMushroomPizza() {};
};

/// @class DeluxePizza - ConcreteProduct
class DeluxePizza : public Pizza {
public:
    virtual int getPrice() const { return 1050; };
    virtual ~DeluxePizza() {};
};

/// @class HawaiianPizza - ConcreteProduct
class HawaiianPizza : public Pizza {
public:
    virtual int getPrice() const { return 1150; };
    virtual ~HawaiianPizza() {};
};

/// @class PizzaFactory - ConcreteFactory
class PizzaFactory {
public:
    enum PizzaType {
        HamMushroom,
        Deluxe,
        Hawaiian
    };

    static unique_ptr<Pizza> createPizza(PizzaType pizzaType) {
        switch (pizzaType) {
        case HamMushroom: return make_unique<HamAndMushroomPizza>();
        case Deluxe:      return make_unique<DeluxePizza>();
        case Hawaiian:    return make_unique<HawaiianPizza>();
        }
        throw "invalid pizza type.";
    }
};

void pizzaInformation(PizzaFactory::PizzaType pizzaType){
    unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzaType);
    cout << "Price of " << pizzaType << " is " << pizza->getPrice() << std::endl;
}

}

int main(){
    PatternFactoryMethod::pizzaInformation(PatternFactoryMethod::PizzaFactory::HamMushroom);
    PatternFactoryMethod::pizzaInformation(PatternFactoryMethod::PizzaFactory::Deluxe);
    PatternFactoryMethod::pizzaInformation(PatternFactoryMethod::PizzaFactory::Hawaiian);
}
