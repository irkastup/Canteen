#pragma once
#include <iostream>
#include <string>
using namespace std;

// Абстрактний базовий клас для напою
class Beverage {
public:
    virtual string getDescription() const = 0;
    virtual double kkalcost() const = 0;
    virtual double proteincost() const = 0;
    virtual double fatcost() const = 0;
    virtual double carbscost() const = 0;

    virtual ~Beverage() {}
};

class Coffee : public Beverage {
public:
    string getDescription() const   {
        return "Coffee";
    }

    double kkalcost() const   {
        return 2.0;
    }
    double proteincost() const   {
        return 0.12;
    }
    double fatcost() const   {
        return 0.2;
    }
    double carbscost() const   {
        return 0.0;
    }

};

class Tea : public Beverage {
public:
    string getDescription() const {
        return "Tea";
    }

    double kkalcost() const {
        return 1.0;
    }
    double proteincost() const {
        return 0.1;
    }
    double fatcost() const {
        return 0.0;
    }
    double carbscost() const {
        return 0.2;
    }

};

// Абстрактний декоратор
class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() const = 0;
};


class Milk : public CondimentDecorator {
private:
    Beverage* beverage;
public:
    Milk(Beverage* b) : beverage(b) {}

    string getDescription() const   {
        return beverage->getDescription() + ", Milk";
    }

    double kkalcost() const   {
        return beverage->kkalcost() + 51.0;
    }
    double proteincost() const   {
        return beverage->proteincost() + 3.0;
    }
    double fatcost() const   {
        return beverage->fatcost() + 2.5;
    }
    double carbscost() const   {
        return beverage->carbscost() + 5.0;
    }

    ~Milk() {
        delete beverage;
    }
};


class Sugar : public CondimentDecorator {
private:
    Beverage* beverage;
public:
    Sugar(Beverage* b) : beverage(b) {}

    string getDescription() const   {
        return beverage->getDescription() + ", Sugar";
    }

    double kkalcost() const {
        return beverage->kkalcost() + 19.9;
    }
    double proteincost() const {
        return beverage->proteincost() + 0.0;
    }
    double fatcost() const {
        return beverage->fatcost() + 0.5;
    }
    double carbscost() const {
        return beverage->carbscost() + 5.0;
    }
    ~Sugar() {
        delete beverage;
    }
};
/*
int main() {
    Beverage* myDrink = new Coffee();
    myDrink = new Milk(myDrink);
    myDrink = new Sugar(myDrink);

    cout << myDrink->getDescription() << " cost: " << myDrink->cost() << endl;

    delete myDrink;
    return 0;
}
*/