#include <iostream>
using namespace std;

#include "listaBase.h"
#include "datosStruct.h"
#include "archivos.h"

int main()
{   
    tLista list;
    int option;

    loadList(list, "ISFT151.txt");

    do
    {
        cout << endl;

        do 
        {
            option = menuPrincipal();

        } while (option < 0 || option > 5);

        switch (option)
        {
            case 1:
            { //-------Mostrar Lista--------------
                cout << endl;
                showList(list); 
            } break;

            case 2:
            { //----------Buscar-----------------
                int aux;

                cout << endl;
                cout << "Buscar por D.N.I. (Y/N): ";

                if (chooseTF())
                {
                    cout << "Ingrese N° DNI: ";
                    cin >> aux;
                    showSpecific(list, searchForID(list, aux));
                }
                else 
                {
                    cout << "Ingrese la matricula: ";
                    cin >> aux;
                    showSpecific(list, searchForMatricula(list, aux));
                }
                
            } break;

            case 3:
            { //------------Crear Nuevo--------------
                addNew (list, recieveNew() ); 
            } break;

            case 4:
            { //------------------------
                string answer;
                int aux, pos;
                
                cout << "Buscar por DNI? (Y/N) " << endl;
                
                if ( chooseTF() ) 
                {
                    cout << "Nro. de DNI: ";
                    cin >> aux;

                    showSpecific(list, searchForID(list, aux));
                    cout << endl << "Desea eliminarlo?" << endl;

                    if (chooseTF()) 
                    {
                        deleteOne(list, searchForID(list, aux));
                    }                    
                }
                else 
                {
                    cout << "Ingrese Matricula: ";
                    cin >> aux;

                    showSpecific(list, searchForID(list, aux));
                    cout << endl << "Desea eliminarlo?" << endl;

                    if (chooseTF())
                    {
                        deleteOne(list, searchForMatricula(list, aux));
                    }                    
                } 
                
            } break;

            case 5:
            {   //ordenar
                sortList(list);

                cout << endl;
                showList(list);
            } 
        }

    } while (option > 0);

    saveList(list, "ISFT151.txt");

    return 0;
}