#include "../lib/animalstypes.h"

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