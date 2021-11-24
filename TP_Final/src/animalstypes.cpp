#include "../lib/animalsTypes.h"
#include <iostream>

Oviparous::~Oviparous()
{
    std::cout << "Se elimino Oviparo" << std::endl;
}

void Oviparous::showType()
{
    std::cout << "Es un oviparo" << std::endl;
}

void Oviparous::layEggs()
{
    std::cout << "Pone huevos" << std::endl;
}

Mammal::~Mammal()
{
    std::cout << "Se elimino Mamifero" << std::endl;
}

void Mammal::showType()
{
    std::cout << "Es un mamifero" << std::endl;
}

void Mammal::nurse()
{
    std::cout << "Amamanta a su cria" << std::endl;
}

