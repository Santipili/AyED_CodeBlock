#include "archivos.h"
#include <iostream>
using namespace std;
#include <cctype>


bool chooseTF() //(Y/N question)
{
    char option;
    do 
    {
        cin >> option;
    } while (toupper(option) != 'Y' && toupper(option) !='N');

    if (toupper(option) == 'Y') 
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}


int menuPrincipal () 
{
    int op;
    
    do {
        cout << "Que desea hacer?" << endl;
        cout << "1.- Ver Lista Completa" << endl;
        cout << "2.- Buscar Alumno" << endl;
        cout << "3.- Agregar Alumno Nuevo" << endl;
        cout << "4.- Eliminar Alumno" << endl;
        cout << "5.- Ordenar Lista" << endl;
        cout << "0.- Guardar y Salir" << endl;
        cin >> op;
    } while ( op < 0 || op > 5);

    return op;
}