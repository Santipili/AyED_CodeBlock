#pragma once

#include "animalBase.h"
#include <iostream>
using namespace std;

class    Oviparous: public Animal 
{
    public:
    virtual void showType();
    virtual void layEggs(); 
    
    Oviparous(string _name, string _meal, int _code): Animal( _name, _meal, _code) {}
    virtual ~Oviparous();
};

class Mammal: public Animal 
{   
    public:
    virtual void showType();
    virtual void nurse(); 

    Mammal(string _name, string _meal, int _code): Animal( _name, _meal, _code) {}
    virtual ~Mammal();
};

