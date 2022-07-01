# Design Patterns. 
### Creational Patterns
1. [Abstract Factory](#AbstractFactory)
2. [Builder](#Builder)
3. [Factory Method](#FactoryMethod)

<!--  Abstract Factory -->
## Abstract Factory <a name="AbstractFactory"></a>
Предоставляет интерфейс для создания семейств связанных между собой или зависимых объектов без указания их конкретных классов.

+ **AbstractFactory** - абстрактная фабрика:

  - Объявляет интерфейс для операций, создающих абстрактные объекты-продукты

+ **ConcreteFactory** - конкретная фабрика:

  - Реализует операции, создающие конкретные объекты-продукты
    
+ **AbstractProduct** - абстрактный продукт:

  - Объявляет интерфейс для типа объекта-продукта

+ **ConcreteProduct** - конкретный продукт:

  - Определяет объект-продукт, создаваемый соответсвующей конкретной фабрикой
    
+ **Client** - клиент:

  - Пользуется исключительно интерфейсами, которые объявлены в классах AbstractFactory и AbstractProduct
    
Example: [C++ Code](https://github.com/imitatehappiness/BasicDesignPatterns/tree/main/patterns/creational/abstarctFactory)

<!--  Builder -->
## Builder <a name="Builder"></a>
Отделяет конструирование сложного объекта от его представления, чтобы один процесс конструирования мог использоваться для создания различных представлений

<!--  Example: [C++ Code](https://github.com/imitatehappiness/BasicDesignPatterns/blob/main/Builder.cpp) -->

<!--  Factory Method -->
## Factory Method <a name="FactoryMethod"></a>
Определяет интерфейс для создания объектов позволяя подклассам решить, экземпляр какого класса следует создать. Позволяет классу передать ответсвенность за создание экземпляра в подклассы.

 <!-- Example: [C++ Code](https://github.com/imitatehappiness/BasicDesignPatterns/blob/main/FactoryMethod.cpp) -->

<!--```c++

```
-->

![https://img.shields.io/badge/Language-C++-blue](https://img.shields.io/badge/Language-C++-blue)

Example: [Source](http://www.sugardas.lt/~p2d/books/Priemioop.pdf)
