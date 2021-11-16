#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>


//Falta hacer la sobrecarga del operador y completar el ordenamiento, esto lo hare antes de terminar todo 
//el ordenamiento está hecho con metodo de burbujueo q parece ser el mas eficiente
//hay q poner q pueda elegir el metodo de ordenamiento

typedef struct 
{
    string carrera;
    int year;
    int matricula;
    double promedio; 
} tInstituto;

typedef struct 
{
    string nombre;
    string apellido;
    long int DNI;
} tPersona;

typedef struct 
{
    long int telefono;
    string mail;
} tContacto;

typedef struct 
{
    tInstituto datosInstituto;
    tPersona datosPersona;
    tContacto datosContacto;    
} tDatos;

const int Max=100;
typedef tDatos tArray[Max];

typedef struct 
{
    tArray alumno;
    int contador;    
} tLista;

int menuPrincipal ();
void sortList(tLista& LISTA);
void loadList(tLista& LISTA, const string path);
void saveList(tLista& LISTA, const string path);
void addNew (tLista& LISTA, tDatos nuevo);
void showList (tLista LISTA);
void deleteOne(tLista& LISTA, int pos); 
void showSpecific(tLista LISTA, int position);
int searchForID(tLista LISTA, int dni);
int searchForMatricula(tLista LISTA, int code);
bool chooseTF();
tDatos recieveNew(); 

bool operator<(tDatos opIzq, tDatos opDer) 
{
   return (opIzq.datosPersona.DNI < opDer.datosPersona.DNI);
} 


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

//-------Funciones--------------

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

void sortList(tLista& LISTA)
{
    int i=0;
    bool change= true;

    tDatos auxiliar;

    while ((i<LISTA.contador) && change) 
    {
        change = false;

        for (int j=LISTA.contador; j>i; j--) 
        {
            if (LISTA.alumno[j-1].datosPersona.DNI < LISTA.alumno[j-2].datosPersona.DNI) 
            {
                auxiliar = LISTA.alumno[j-1];
                LISTA.alumno[j-1] = LISTA.alumno[j-2];
                LISTA.alumno[j-2] = auxiliar;

                change = true;
            }
            else
            {
                change = false;
            }
                        
        }

        if (change) 
        {
            i++;
        }

    }

    
}

void loadList(tLista& LISTA, const string path) 
{

    ifstream archivoLista;

    char aux;
    int pos;

    LISTA.contador = pos = 0;

    archivoLista.open(path);

    if (archivoLista.is_open()) {
        
        while ( !archivoLista.eof() && (pos < Max) ) { 

            getline(archivoLista, LISTA.alumno[pos].datosPersona.nombre);
            getline(archivoLista, LISTA.alumno[pos].datosPersona.apellido);

            archivoLista >> LISTA.alumno[pos].datosPersona.DNI;

            archivoLista.get(aux);
            getline(archivoLista, LISTA.alumno[pos].datosInstituto.carrera);

            archivoLista >> LISTA.alumno[pos].datosInstituto.year >> LISTA.alumno[pos].datosInstituto.matricula >> LISTA.alumno[pos].datosInstituto.promedio >>  LISTA.alumno[pos].datosContacto.telefono;

            archivoLista.get(aux); 
            getline(archivoLista, LISTA.alumno[pos].datosContacto.mail);

            pos++;  
        }  

        LISTA.contador = pos ;
    }
    else 
    {
        cout << "No se encontro archivo" << endl;
    }

    archivoLista.close();

    return;
}

void saveList(tLista& LISTA, const string path) 
{
    ofstream archivoLista;
    
    archivoLista.open(path);

    if (archivoLista.is_open()) {

        if ( LISTA.alumno[0].datosPersona.nombre.length() != 0 )
        {
        
            for (int i = 0; i<LISTA.contador-1; i++ )
            {
                archivoLista << LISTA.alumno[i].datosPersona.nombre << endl;
                archivoLista << LISTA.alumno[i].datosPersona.apellido << endl;
                archivoLista << LISTA.alumno[i].datosPersona.DNI << endl;
                archivoLista << LISTA.alumno[i].datosInstituto.carrera << endl;
                archivoLista << LISTA.alumno[i].datosInstituto.year << endl;
                archivoLista << LISTA.alumno[i].datosInstituto.matricula << endl;
                archivoLista << LISTA.alumno[i].datosInstituto.promedio << endl;
                archivoLista << LISTA.alumno[i].datosContacto.telefono << endl;
                archivoLista << LISTA.alumno[i].datosContacto.mail << endl;
            }

            archivoLista << LISTA.alumno[LISTA.contador-1].datosPersona.nombre << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosPersona.apellido << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosPersona.DNI << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosInstituto.carrera << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosInstituto.year << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosInstituto.matricula << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosInstituto.promedio << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosContacto.telefono << endl;
            archivoLista << LISTA.alumno[LISTA.contador-1].datosContacto.mail;

        }

    }

    archivoLista.close();

    return;
}

void addNew (tLista& LISTA, tDatos nuevo) 
{

    
    LISTA.alumno[LISTA.contador] = nuevo;

    LISTA.contador++;

    return;
}

void showList (tLista LISTA) 
{

    cout << "Lista de alumnos (" << LISTA.contador << "):" << endl;
    cout << "Carrera" << "|" << "Anio" << "|" << "Apellido" << "|" << "Nombre" << "|" << "D.N.I" << endl;
    cout << endl;

    for (int i=0; i < LISTA.contador; i++) 
    {
        cout << LISTA.alumno[i].datosInstituto.carrera << "|" << LISTA.alumno[i].datosInstituto.year << "|";
        cout << LISTA.alumno[i].datosPersona.apellido << "|" << LISTA.alumno[i].datosPersona.nombre << "|";
        cout << LISTA.alumno[i].datosPersona.DNI << endl;
    }

    return;
}

void deleteOne(tLista& LISTA, int pos) 
{ 

    for (int i = pos; i< LISTA.contador - 1; i++){
        LISTA.alumno[i] = LISTA.alumno[i+1];      
    }

    LISTA.contador--;
    
    return;
}

void showSpecific(tLista LISTA, int position)
{
    int i;
    i=0;
    cout << "Nombre     :" << LISTA.alumno[i].datosPersona.nombre << endl;
    cout << "Apellido   :" << LISTA.alumno[i].datosPersona.apellido << endl;
    cout << "D.N.I.     :" << LISTA.alumno[i].datosPersona.DNI << endl; 
    cout << "Telefono   :" << LISTA.alumno[i].datosContacto.telefono << endl;
    cout << "E-mail     :" << LISTA.alumno[i].datosContacto.mail << endl;
    cout << endl;
    cout << "Carrera    :" << LISTA.alumno[i].datosInstituto.carrera << endl;
    cout << "Anio       :" << LISTA.alumno[i].datosInstituto.year << endl;
    cout << "Matricula  :" << LISTA.alumno[i].datosInstituto.matricula << endl;
    cout << "Promedio   :" << LISTA.alumno[i].datosInstituto.promedio << endl;
    cout << endl;

    return;
}

int searchForID(tLista LISTA, int dni) 
{
    int pos, i;
    i = 0;
    pos = -1;

    while (LISTA.alumno[i].datosPersona.DNI != dni  && i< LISTA.contador)
    {
        i++;
    }

    if (i == LISTA.contador) pos = -1;
        else pos = i;
    
    return pos;
}

int searchForMatricula(tLista LISTA, int code) 
{
    int pos, i;
    i = 0;
    pos = -1;

    while (LISTA.alumno[i].datosInstituto.matricula != code  && i< LISTA.contador)
    {
        i++;
    }

    if (i == LISTA.contador) pos = -1;
        else pos = i;
  
    return pos;
}

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

tDatos recieveNew() 
{
    tDatos* other;
    other = new tDatos();

    cin.ignore();
    cout << "Nuevo alumno. Datos" << endl;
    cout << "Nombre     : "; getline(cin, other->datosPersona.nombre); 
    cout << "Apellido   : "; getline(cin, other->datosPersona.apellido); 
    cout << "D.N.I.     : "; cin >> other->datosPersona.DNI; 
    cin.ignore();
    cout << "Carrera    : "; getline(cin, other->datosInstituto.carrera);
    cout << "Telefono   : "; cin >> other->datosContacto.telefono;
    cin.ignore();
    cout << "E-mail     : "; getline(cin, other->datosContacto.mail);

    other->datosInstituto.matricula = 0000;
    other->datosInstituto.promedio = 0;
    other->datosInstituto.year = 1;
    
    return *other;

    delete other;
}

