#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <iomanip> //lo utilizare cuando tenga q ordenar los datos en pantalla


string chekConfirmation (int confirmacion);



    typedef struct 
    {
        string name;
        double phone; //tuve que poner el phone como double porq como int excedia el limite
        string calle;
        int altura;
        int confirmation;
        int ticket;
       // string country;
    } tInvitado;

    const int Dim = 10001; // de 0 a 9999 el 10.000 es el ticket 1111111111
    typedef tInvitado tVector[Dim];
    
    typedef struct
    {
        tVector invitado;
        int contador;
    } tLista;
    




int main () 
{
    tLista lista;

    ifstream archivoLista;

    char aux;
    int contador = 0;

    archivoLista.open("lista_de_invitados.txt");

// con esto tomo el archivo y lleno los datos de mi estructura
// el archivo dsps lo cierro pues ya lo tengo en memoria
    if (archivoLista.is_open()) {
        archivoLista >> lista.invitado[contador].ticket;

        while ( invitados[contador].ticket > 1111111111 ) {
            archivoLista >> lista.invitado[contador].confirmation >> lista.invitado[contador].phone >> lista.invitado[contador].calle >> lista.invitado[contador].altura;

            archivoLista.get(aux);

            getline(archivoLista, lista.invitado[contador].name);

            contador++;
            archivoLista >> lista.invitado[contador].ticket;
        }

    }

    archivoLista.close();


// Esto me muestra todos los invitados 
    cout << "los invitados son:" << endl;

    for (int i = 0 ; i < contador; i++) {

        cout << setw(10) << chekConfirmation(invitados[i].confirmation) << " - " << invitados[i].name << " - Num. Ticket: " << invitados[i].ticket << endl;
    }


// Agregar un nuevo invitado




// Ve un invitado especifico 

    int posicion;
    int numticket;
    int continuar;
    int op;
    

    cout << "ingrese el numero de ticket " << endl;
    cin >> numticket;

    posicion = numticket - 1750250000; 

    cout << endl; 
    cout << invitados[posicion].name << endl;
    cout << setprecision(10) << invitados[posicion].phone << endl;
    cout << invitados[posicion].calle << " " << invitados[posicion].altura << endl;
    cout << chekConfirmation(invitados[posicion].confirmation) << endl;



// Modificar datos

    cout << "Desea modificar algun dato? (y/n)" << endl;
    cout << "1.- Si" << endl;
    cout << "2.- No" << endl;
    cin >> continuar;

    while (continuar == 1) {
        cout << "Cual? " << endl;
        cout << "1.- Telefono" << endl;
        cout << "2.- Direccion" << endl;
        cout << "3.- Confirmacion" << endl;
        cin >> op; 

        switch (op) {
            case 1:{

                cout << "Ingrese nuevo telefono: ";
                cin >> invitados[posicion].phone;

            } break;

            case 2:{

                cout << "Ingrese Nueva direccion " << endl;

                cin >> invitados[posicion].calle;
                cin >> invitados[posicion].altura;

            } break;

            case 3:{
                int aux;
                cout << "Confirmado:" << endl;
                cout << "1.- NO" << endl;
                cout << "2.- SI" << endl;
                cin >> aux;
                invitados[posicion].confirmation = aux - 1;

            }
        }

        cout << "Desea modificar otro dato? (y/n)" << endl;
        cout << "1.- Si" << endl;
        cout << "2.- No" << endl;
        cin >> continuar;
    }


    cout << "Hasta luego";


    return 0;
}

string chekConfirmation (int confirmacion) {
    string confirmado;

    if (confirmacion == 0){
        confirmado = " ";
    } else {
        confirmado = "Confirmado";
    }

    return confirmado;
}



