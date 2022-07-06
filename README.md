# Design Patterns. 
### Creational Patterns
1. [Abstract Factory](#AbstractFactory)
2. [Builder](#Builder)
3. [Factory Method](#FactoryMethod)
3. [Prototype](#Prototype)
4. [Singleton](#Singleton)
### Structural Patterns
### Behavioral Patterns
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

+ **Builder** - строитель:

  - Задает абстрактный интерфейс для создания частей объекта Product
  
+ **СoncreteBuilder** - конкретный строитель:

  - Конструирует и собирает вместе части продукта посредством реализации интерфейса Builder
  - Определяет создаваемое представление и следит за ним
  - Предоставляет интерфейс для доступа к продукту

+ **Director** - распорядитель:

  - Конструирует объект, пользуясь интерфейсом Builder
  
+ **Product** - продукт:

  - Представляет сложный конструируемый объект. ConcreteBuilder строит внутреннее представление продукта иопределяет процесс его сборки;
  - Включает классы, которые определяют составные части, в том числе интерфейсы для сборки конечного результата из частей
  
Example: [C++ Code](https://github.com/imitatehappiness/BasicDesignPatterns/tree/main/patterns/creational/builder)

<!--  Factory Method -->
## Factory Method <a name="FactoryMethod"></a>
Определяет интерфейс для создания объектов позволяя подклассам решить, экземпляр какого класса следует создать. Позволяет классу передать ответсвенность за создание экземпляра в подклассы.

+ **Product** - продукт:

  - Определяет интерфейс объектов, создаваемых фабричным методом

+ **ConcreteProduct** - конкретный продукт:

  - Реализует интерфейс Product

+ **Creator** - создатель:

  - Объявляет фабричный метод, возвращающий объект типа Product
Creator может также определять реализацию по умолчанию фабричного метода, который возвращает объект ConcreteProduct
  - Может вызывать фабричный метод для создания объекта Product
  
+ **ConcreteCreator** - конкретный создатель:

  - Замещает фабричный метод, возвращающий объект СoncreteProduct
  
 <!-- Example: [C++ Code](https://github.com/imitatehappiness/BasicDesignPatterns/blob/main/FactoryMethod.cpp) -->

<!--  Prototype -->
## Prototype <a name="Prototype"></a>

Задает виды создаваемых объектов с помощью экземпляра-прототипа и создает новые объекты путем копирования этого прототипа.

+ **Prototype** - прототип:

  - Объявляет интерфейс для клонирования самого себя
  
+ **ConcretePrototype** - конкретный прототип:

  - Реализует операцию клонирования себя

+ **Client** - клиент:

  - Создает новый объект, обращаясь к прототипу с запросом клонировать
себя

Example: [C++ Code](https://github.com/imitatehappiness/BasicDesignPatterns/tree/main/patterns/creational/prototype)

## Singleton <a name="Singleton"></a>

Гарантирует, что у класса существует только один экземпляр, и предоставляет к нему глобальную точку доступа.

+ **Singleton** - одиночка:

  - Определяет операцию Instance, которая позволяет клиентам получить
доступ к единственному экземпляру
  - Может нести ответственность за создание собственного уникального
экземпляра

# Sourse: 

[Design Patterns RUS Version](https://github.com/imitatehappiness/BasicDesignPatterns/files/9028323/default.pdf)

[Design Patterns ENG Version](https://github.com/imitatehappiness/BasicDesignPatterns/files/9028336/P020101022562155422801.pdf)

--- 
![https://img.shields.io/badge/Language-C++-blue](https://img.shields.io/badge/Language-C++-blue) 

