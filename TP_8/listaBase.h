#ifndef listaBase_h
#define listaBase_h

#include <iostream>
using namespace std;
#include "datosStruct.h"

//-------------Lista----------

const int Max=100;
typedef tDatos tArray[Max];

typedef struct 
{
    tArray alumno;
    int contador;    
} tLista;

//----FUNCIONES--------------

void sortList(tLista& LISTA);

void loadList(tLista& LISTA, const string path);

void saveList(tLista& LISTA, const string path);

void showList (tLista LISTA);

void showSpecific(tLista LISTA, int position);

int searchForID(tLista LISTA, int dni);

int searchForMatricula(tLista LISTA, int code);

void deleteOne(tLista& LISTA, int pos);

void addNew (tLista& LISTA, tDatos nuevo); 

#endif