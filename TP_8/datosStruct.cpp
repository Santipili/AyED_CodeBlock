#include <iostream>
using namespace std;

#include "datosStruct.h"

bool operator<(tDatos opIzq, tDatos opDer) 
{
   return (opIzq.datosPersona.DNI < opDer.datosPersona.DNI);
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