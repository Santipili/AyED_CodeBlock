#include "../lib/animalBase.h"
#include <iostream>

string Animal::getName() 
{
    return name;
}

void Animal::setName(string newName)
{
    name = newName;
}

int Animal::getCode()
{
    return code;
}

void Animal::setCode(int newCode)
{
    code= newCode;
}

string Animal::getMeal()
{
    return meal;
}

Animal::Animal(string _name, string _meal, int _code)
{
    name= _name;
    meal = _meal;
    code = _code;
}

Animal::~Animal()
{
    std::cout << "Se borro animal" << std::endl;
}

void Animal::eat()
{
    std::cout << "Come " << Animal::getMeal() << std::endl;
}

void Animal::sleep()
{
    std::cout << "Esta durmiendo" << std::endl;
}
