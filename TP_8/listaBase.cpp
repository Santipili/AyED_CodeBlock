#include "listaBase.h"
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>

//----------IMPLEMENTACION----------------



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

void deleteOne(tLista& LISTA, int pos) 
{ 

    for (int i = pos; i< LISTA.contador - 1; i++){
        LISTA.alumno[i] = LISTA.alumno[i+1];      
    }

    LISTA.contador--;
    
    return;
}

void addNew (tLista& LISTA, tDatos nuevo) 
{
    LISTA.alumno[LISTA.contador] = nuevo;

    LISTA.contador++;

    return;
}