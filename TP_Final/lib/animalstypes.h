#ifndef animalstypes_h
#define animalstypes_h

#include <iostream>

std::class Animal 
{
    private:
    std::string name;
    std::int code;

    public:
    virtual void eat() = 0; //una frase de que esta comiendo feliz, distinta por animal
    virtual void sleep() =0;
    
    std::string getName();
    void setName(std::string newName);
    std::int getCode();    
    void setCode(std::int newCode);
};


std::class    Oviparous: public Animal //interface
{
    public:
    virtual void layEggs() = 0; //modificar funcionalidad
};

std::class Mammal: public Animal //interface
{
    public:
    virtual void nurse() = 0; //modificar funcionalidad
};

#endif