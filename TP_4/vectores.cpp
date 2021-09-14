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
    double nota;
} tEstructura;
    
typedef tEstructura tVector[49];

typedef struct{
    tVector alumno;
    int contador;
} tLista;
//-----------------------------------------------------

void cargaDeArchivo (const string path, tLista& LISTA);
int menuPrincipal ();
void showList(tLista LISTA);
void addNew (tLista& LISTA);
void changeOne (tLista& LISTA);
void saveList (const string path, tLista& LISTA);
void deleteOne (tLista& LISTA);
void changeNotes(tLista& LISTA);
void clasificateNotes (tLista LISTA);
double searchHigestNote (tLista LISTA);
int calculatePromedio (tLista LISTA);

int main () {
    tLista lista;
    int option;
    
    cargaDeArchivo("AyED1.txt", lista); // cargar lista

    do {
        option = menuPrincipal ();
        
        switch (option){
            case 1:{
            //-----------LISTA Completa-------------------------------------------------------------------------------
                showList(lista);
                cout << endl;
            } break;

            case 2:{
            //------Nuevo Elemento------------------------------------------------------------------------------------
                addNew (lista);
                cout << endl;
            } break;

            case 3:{
            //------------Modificar elemento--------------------------------------------------------------------------
                changeOne (lista);
                cout << endl;
            }break;

            case 4:{
            //-------------Borrar elemento------------------------------------------------------------------           
                deleteOne (lista);
                cout << endl;
            } break;

            case 5:{
            //-------------Carga de Notas-----------------------------------------------------------------------------
                changeNotes(lista);
                cout << endl;
            } break;

            case 6:{
            //-------------Lista de Notas------------------------------------------------------------------------------  
                cout << "Mejores notas" << endl;
                clasificateNotes(lista);
                cout << endl << "La nota promedio de " << lista.contador << " alumnos es: " << calculatePromedio(lista) << endl;
                cout << endl;
            }
        }

    } while (option < 7);

    saveList ("AyED1.txt", lista);

    cout << "Adios, gracias!!";

    return 0;
}

void cargaDeArchivo (const string path, tLista& LISTA) {

    ifstream archivoLista;

    char aux;
    int pos;

    LISTA.contador = pos = 0;

    archivoLista.open(path);

    if (archivoLista.is_open()) {
        
        while ( !archivoLista.eof() ) {

            archivoLista >> LISTA.alumno[pos].edad >> LISTA.alumno[pos].DNI >> LISTA.alumno[pos].nota >> LISTA.alumno[pos].apellido;
              
            archivoLista.get(aux);

            getline(archivoLista, LISTA.alumno[pos].nombre);

            pos++;  

        }  

        LISTA.contador = pos ;

    }

    archivoLista.close();

    return;
}

int menuPrincipal () {

    int op;
    
    do {
        cout << "Que desea hacer?" << endl;
        cout << "1.- Ver Lista Completa" << endl;
        cout << "2.- Agregar Alumno Nuevo" << endl;
        cout << "3.- Modificar Alumno" << endl;
        cout << "4.- Eliminar Alumno" << endl;
        cout << "5.- Cargar Notas" << endl;
        cout << "6.- Lista de Notas" << endl;
        cout << "7.- Salir" << endl;
        cin >> op;
    } while ( op < 1 || op > 7);

    return op;
}

void showList(tLista LISTA) {

    cout << "Lista de alumnos (" << LISTA.contador << "):" << endl;

    for (int i=0; i < LISTA.contador; i++) {

        cout << LISTA.alumno[i].apellido << ", " << LISTA.alumno[i].nombre << " - D.N.I.: " << LISTA.alumno[i].DNI << " - Edad: " << LISTA.alumno[i].edad << " - Nota: " << LISTA.alumno[i].nota << endl;

    }

    return;
}

void addNew (tLista& LISTA) {

    cout << "Nuevo alumno.-" << endl;
    cout << "Nombre/s: "; cin >> LISTA.alumno[LISTA.contador].nombre;
    cout << "Apellido: "; cin >> LISTA.alumno[LISTA.contador].apellido;
    cout << "D.N.I.: "; cin >> LISTA.alumno[LISTA.contador].DNI;
    cout << "Edad: "; cin >> LISTA.alumno[LISTA.contador].edad;
    cout << "Nota: "; cin >> LISTA.alumno[LISTA.contador].nota;
    LISTA.contador++;

    return;
}

void changeOne (tLista& LISTA) { //debo crear otra funcion para utilizar adentro
    
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

void saveList (const string path, tLista& LISTA) {
    ofstream archivoLista;
    int pos;

    pos = 0;

    archivoLista.open(path);

    if (archivoLista.is_open()) {
        
        do {
            archivoLista << endl << LISTA.alumno[pos].edad << " " <<  LISTA.alumno[pos].DNI << " " << LISTA.alumno[pos].nota << " " << LISTA.alumno[pos].apellido << " " << LISTA.alumno[pos].nombre;

            pos++;  

        } while ( pos < LISTA.contador ); 

    }

    archivoLista.close();

    return;
}

void deleteOne (tLista& LISTA) { //debo crear otra funcion para utilizar adentro
    int dni, pos;

    pos = 0;

    cout << "DNI del alumno que desea borrar: ";
    cin >> dni;

    while ( (LISTA.alumno[pos].DNI != dni) && pos < LISTA.contador ){
        pos++;
    }
        
    if (LISTA.alumno[pos].DNI == dni){

        for (int i = pos; i< LISTA.contador - 1; i++){

            LISTA.alumno[i] = LISTA.alumno[i+1];
           
        }

        LISTA.contador--;
    }
    else {
        cout << "No hubo coincidencia";
    }

    return;
}

void changeNotes(tLista& LISTA) { 

    for (int i=0; i < LISTA.contador; i++){
        cout << LISTA.alumno[i].apellido << ", " << LISTA.alumno[i].nombre << "; " << LISTA.alumno[i].DNI << " - Nota: " << endl;
        cin >> LISTA.alumno[i].nota;
    }

    return;
}

void clasificateNotes (tLista LISTA) {// lista de alumnos con nota mas alta (mandar al main una parte)
    int pos;
    double nota;

    pos = 0;

    // Valor nota mas alta
    nota = searchHigestNote (LISTA);

    // muestra todos los que tienen esa nota
    for (int i=0; i < LISTA.contador; i++) {
       
        if (LISTA.alumno[i].nota == nota) 
        {
            cout << LISTA.alumno[i].apellido << ", " << LISTA.alumno[i].nombre << " - Nota: " << LISTA.alumno[i].nota << endl; 
        }   
    }

    return;
}

double searchHigestNote (tLista LISTA)
{
    double nota;

    for (int i=0; i < LISTA.contador; i++) {
        if (LISTA.alumno[i].nota > nota) 
            nota = LISTA.alumno[i].nota;    
    }

    return nota;
}

int calculatePromedio (tLista LISTA) {
    double suma;
    double promedio;

    for (int i=0; i < LISTA.contador; i++){
        suma = suma + LISTA.alumno[i].nota;
    }

    promedio = suma / LISTA.contador;

    return promedio;
}



