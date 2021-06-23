#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <iomanip>


typedef enum {BHI, AEP, EPA, EZE, BRC, CTC, CRD} tAirport;
typedef enum {Primera, Bussines, Economica} tFlyClass;

string showConfort(tFlyClass tipo);
string showFly(tAirport vuelo);


int main() {
    string name, surname, fullname;
    int id, aux;
    tFlyClass confort;
    tAirport flyfrom, flyto;

    cout << "Ingrese sus datos" << endl;
    cout << "DNI: ";
    cin >> id;
    cin.get(); // lo debo colocar porq sino me guarda el 'enter' en la otra variable, puesto que es un getline lo saltea directamente
    cout << "Nombre: ";
    getline(cin, fullname);

    cout << "Que clase de aereo desea?" << endl;
    cout << "1_ Primera" << endl;
    cout << "2_ Bussines" << endl;
    cout << "3_ Economica" << endl;
    cin >> aux;
    confort = tFlyClass(aux-1);

    cout << "Elija aeropuerto de origen: " << endl;
    cout << "1_ Bahia Blanca - BHI" << endl;
    cout << "2_ Buenos Aires, Aeroparque - AEP" << endl;
    cout << "3_ Buenos Aires, El Palomar - EPA" << endl;
    cout << "4_ Buenos Aires, Ezeiza - EZE" << endl;
    cout << "5_ San Carlos de Bariloche - BRC" << endl;
    cout << "6_ San Fernando del  Valle de Catamarca - CTC" << endl;
    cout << "7_ Colmodoro Rivadavia - CRD" << endl;
    cin >> aux;
    flyfrom = tAirport(aux-1);

    cout << "Elija aeropuerto de destino: " << endl;
    cout << "1_ Bahia Blanca - BHI" << endl;
    cout << "2_ Buenos Aires, Aeroparque - AEP" << endl;
    cout << "3_ Buenos Aires, El Palomar - EPA" << endl;
    cout << "4_ Buenos Aires, Ezeiza - EZE" << endl;
    cout << "5_ San Carlos de Bariloche - BRC" << endl;
    cout << "6_ San Fernando del  Valle de Catamarca - CTC" << endl;
    cout << "7_ Colmodoro Rivadavia - CRD" << endl;
    cin >> aux;
    flyto = tAirport(aux-1);


    cout << "Su reserva es:" << endl;
    cout << fullname << ", " << id <<endl;
    cout << "Clase de vuelo: " << showConfort(confort) << endl;
    cout << "Origen: " << showFly(flyfrom) << endl;
    cout << "Destino: " << showFly(flyto) << endl;


    return 0;
}


string showConfort(tFlyClass tipo){
    string clase;

    if (tipo == Primera){
        clase = "Primera";
    }
    if (tipo == Bussines){
        clase = "Bussines";
    }
    if (tipo == Economica){
        clase = "Economica";
    }

    return clase;
}

string showFly(tAirport vuelo){
    string aeropuerto;

    if (vuelo == BHI ){
        aeropuerto = "Bahia Blanca - BHI";
    }
    if (vuelo == AEP){
        aeropuerto = "Buenos Aires, Aeroparque - AEP";
    }
    if (vuelo == EPA){
        aeropuerto = "Buenos Aires, El Palomar - EPA";
    }
    if (vuelo == EZE){
        aeropuerto = "Buenos Aires, Ezeiza - EZE";
    }
    if (vuelo == BRC){
        aeropuerto = "San Carlos de Bariloche - BRC";
    }
    if (vuelo == CTC){
        aeropuerto = "San Fernando del Valle de Catamarca - CTC";
    }
    if (vuelo == CRD){
        aeropuerto = "Comodoro Rivadavia - CRD";
    }

    return aeropuerto;
}
