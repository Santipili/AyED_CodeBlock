#include "../lib/funciones.h"
#include "../lib/animalBase.h"
#include "../lib/animalsTypes.h"
#include <iostream>
using namespace std;

void creationAnimals(Animal* animal, int option)
{
    string name, meal;
    int code;

    switch (option)
        {
            case 1:
            {
                cout << "Ingrese nombre del animal: ";
                cin >> name;
                cin.ignore();
                cout << "Que come? ";
                getline(cin, meal);
                cout << "Ingrese su codigo: ";
                cin >> code;
                animal = new Oviparous(name, meal, code);
            }
            break;

            case 2: 
            {
                cout << "Ingrese nombre del animal: ";
                cin >> name;
                cin.ignore();
                cout << "Que come? ";
                getline(cin, meal);
                cout << "Ingrese su codigo: ";
                cin >> code;
                animal = new Mammal(name, meal, code);
            }
        }

} 

void showAnimals(Animal* animal)
{
    cout << animal->getName() <<":"<< endl;
    animal->showType();
    animal->eat();
    animal->sleep();
    cout << endl;

}