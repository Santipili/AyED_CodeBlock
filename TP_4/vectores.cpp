#include <iostream>
using namespace std;
#include <string>
#include <fstream>

//------------------------------------------------------------
typedef struct {
    string nombre;
    string apellido;
    int edad;
    int long DNI;
    int nota;
} tEstructura;
    
typedef tEstructura tVector[49];

typedef struct{
    tVector alumno;
    int contador;
} tLista;
//-----------------------------------------------------

void cargaDeArchivo (const string path, tLista& LISTA);
int menuPrincipal ();
void showList(tLista& LISTA);
void addNew (tLista& LISTA);
void changeOne (tLista& LISTA);

int main () {

    tLista lista;

    // cargar lista

    cargaDeArchivo("AyED1.txt", lista);

    //menu 
    int op;

    op = menuPrincipal ();
   
//casos main:


    switch (op){
        case 1:{
    //-----------VER LISTA-------------------------------------------------------
            showList(lista);

        } break;

        case 2:{
    //------Nuevo Elemento-----------------------------------------------------------------------------------------------------------
            addNew (lista);
        } break;

        case 3:{
    //------------Modificar elemento---------------------------------------------------------------------------------------------------
            changeOne (lista);
        }
    }

    return 0;
}

void cargaDeArchivo (const string path, tLista& LISTA) {

    ifstream archivoLista;

    char aux;
    int pos;

    LISTA.contador = pos = 0;

    archivoLista.open(path);

    if (archivoLista.is_open()) {
        
        do {

            archivoLista >> LISTA.alumno[pos].edad >> LISTA.alumno[pos].DNI >> LISTA.alumno[pos].nota >> LISTA.alumno[pos].apellido;
              
            archivoLista.get(aux);

            getline(archivoLista, LISTA.alumno[pos].nombre);

            pos++;  

        } while ( !archivoLista.eof() ); 

        LISTA.contador = pos ;

    }

    archivoLista.close();

    return;
}

int menuPrincipal (){

    int op;
    
    do {
        cout << "Que desea hacer?" << endl;
        cout << "1.- Ver Lista " << endl;
        cout << "2.- Agregar Alumno Nuevo" << endl;
        cout << "3.- Modificar Alumno" << endl;
        cin >> op;
    } while ( op < 1 || op > 3);

    return op;
}

void showList(tLista& LISTA){

    cout << "Lista de alumnos (" << LISTA.contador << "):" << endl;

    for (int i=0; i < LISTA.contador; i++) {

        cout << LISTA.alumno[i].apellido << ", " << LISTA.alumno[i].nombre << " - D.N.I.: " << LISTA.alumno[i].DNI << " - Edad: " << LISTA.alumno[i].edad << " - Nota: " << LISTA.alumno[i].nota << endl;

    }

    return;
}

void addNew (tLista& LISTA){

    cout << "Nuevo alumno.-" << endl;
    cout << "Nombre/s: " << LISTA.alumno[LISTA.contador].nombre << endl;
    cout << "Apellido: " << LISTA.alumno[LISTA.contador].apellido << endl;
    cout << "D.N.I.: " << LISTA.alumno[LISTA.contador].DNI << endl;
    cout << "Edad: " << LISTA.alumno[LISTA.contador].edad << endl;
    cout << "Nota: " << LISTA.alumno[LISTA.contador].nota << endl;
    LISTA.contador++;

    return;
}

void changeOne (tLista& LISTA) {
    
    int dni, pos;

    do { 
        cout << "DNI del alumno que desea modificar:" << endl;
        cin >> dni;

        pos = 0;

        while ( (LISTA.alumno[pos].DNI != dni) && pos < LISTA.contador ){
            pos++;
        }

        if ( LISTA.alumno[pos].DNI == dni) {
             cout << "Modificar a " << LISTA.alumno[pos].apellido << ", " << LISTA.alumno[pos].nombre << endl;

            cout << "Nombre/s: ";
            cin >> LISTA.alumno[pos].nombre;
    
            cout << "Apellido: ";
            cin >> LISTA.alumno[pos].apellido;

            cout << "D.N.I.: ";
            cin >> LISTA.alumno[pos].DNI;

            cout << "Edad: ";
            cin >> LISTA.alumno[pos].edad;

            cout << "Nota: ";
            cin >> LISTA.alumno[pos].nota;
        }
        else {
            cout << "No hubo coincidencia";
        }

    } while (LISTA.alumno[pos].DNI != dni);

    return;
}