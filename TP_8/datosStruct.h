#ifndef datosStruct_h
#define datosStruct_h

#include <iostream>
using namespace std;

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

bool operator<(tDatos opIzq, tDatos opDer);

tDatos recieveNew();

#endif