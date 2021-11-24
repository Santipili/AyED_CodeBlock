#pragma once

#include <iostream>
using namespace std;

class Animal 
{
    private:
    string name;
    string meal;
    int code;

    public:
    virtual void eat(); //una frase de que esta comiendo feliz, distinta por animal
    virtual void showType() = 0;
    virtual void sleep(); 
    
    string getName();
    void setName(string newName);
    int getCode();    
    void setCode(int newCode);
    string getMeal();

    Animal(string _name, string _meal, int _code);
    virtual ~Animal();
};
