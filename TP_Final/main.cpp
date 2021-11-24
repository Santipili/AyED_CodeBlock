#include "./lib/animalsTypes.h"
#include "./lib/animalBase.h"
#include "./lib/funciones.h"

#include <iostream>
using namespace std;

int main()
{   
    Animal* animales[10];
    int op, position = 0;
    string name, meal;
    int code;

    cout << "bienvenido al zoologico STP" << endl;
    cout << endl;

    cout << "Vamos a crear una lista de 5 animales" << endl;

    for(int i=0; i<5; i++)
    {
        animales[i] = NULL;
        cout << endl;
        cout << "Que tipo de animal es? " << endl;
        cout << "1_Oviparo" << endl;
        cout << "2_Mamifero" << endl;
        cin >> op;
        // funcion creacion

       // creationAnimals(animales[i], op);

         switch (op)
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
                animales[i] = new Oviparous(name, meal, code);
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
                animales[i] = new Mammal(name, meal, code);
            }
        } 

        
    }

    // funcion para recorrer el array mostrando la info
    cout << "Veamos los datos de la lista" << endl;
   
    for(int i=0; i<5; i++)
    {
        showAnimals(animales[i]);
    } 

    
    // funcion erase
    for(int i=0; i<5; i++)
    {
        delete animales[i];
    }
    
    return 0;
}

 

