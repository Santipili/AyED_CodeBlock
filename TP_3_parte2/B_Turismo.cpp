#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <iomanip>
#include <ctime>

typedef enum {BHI, AEP, EPA, EZE, BRC, CTC, CRD} tAirport;
typedef enum {Primera, Bussines, Economica} tFlyClass;

string showConfort(tFlyClass tipo);
string showFly(tAirport vuelo);

int menuClase();
int menuFly();

const string currentDateTime() ;

int main() {
    string fullname;
    int id, aux1, aux2, aux3;
    tFlyClass confort;
    tAirport flyfrom, flyto;

    cout << "Ingrese sus datos" << endl;

    cout << "DNI: ";
    cin >> id;
    cin.get(); // lo debo colocar porq sino me guarda el 'enter' en la otra variable, puesto que es un getline lo saltea directamente

    cout << "Nombre Completo: ";
    getline(cin, fullname);

    cout << "Elija la categoria del vuelo." << endl;

    aux1 = menuClase();
    confort = tFlyClass(aux1);

    cout << "Elija aeropuerto de origen: " << endl;

    aux2 = menuFly();
    flyfrom = tAirport(aux2);

    cout << "Elija aeropuerto de destino: " << endl;

    aux3 = menuFly();
    flyto = tAirport(aux3);


    cout << "Su reserva:" << endl;
    cout << currentDateTime() << endl;
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

int menuClase() {
    int opcion;

    do {
        cout << "1_ Primera" << endl;
        cout << "2_ Bussines" << endl;
        cout << "3_ Economica" << endl;
        cin >> opcion;

    } while (opcion < 1 || opcion > 3);

    opcion = opcion -1;

    return opcion;
}

int menuFly() {
    int opcion;

    do {
        cout << "1_ Bahia Blanca - BHI" << endl;
        cout << "2_ Buenos Aires, Aeroparque - AEP" << endl;
        cout << "3_ Buenos Aires, El Palomar - EPA" << endl;
        cout << "4_ Buenos Aires, Ezeiza - EZE" << endl;
        cout << "5_ San Carlos de Bariloche - BRC" << endl;
        cout << "6_ San Fernando del  Valle de Catamarca - CTC" << endl;
        cout << "7_ Colmodoro Rivadavia - CRD" << endl;
        cin >> opcion;

    } while (opcion < 1 || opcion > 7);

    opcion = opcion -1;

    return opcion;
}

const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}

