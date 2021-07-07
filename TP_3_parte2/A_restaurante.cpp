#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <iomanip>
#include <ctime>

typedef enum {Julia, Esteban, Wally, Maria} tMozo;
typedef enum {Champinones, Carpaccio, Empanadas } tEntrada;
typedef enum {Merluza, Muslitos, Paella, Cordero, SandwichTofu} tPrincipal;
typedef enum {MousseChoc, EnsaladaFrut, Flan} tPostre;

const string currentDateTime();

int chooseName();
int chooseStarter();
int chooseMain();
int chooseDessert();

string showName(tMozo nombre);
string showStarter(tEntrada entrada);
string showMain(tPrincipal principal);
string showDessert(tPostre postre);

int main() {
    int table, aux1, aux2, aux3, aux4;
    tMozo name;
    tEntrada starter;
    tPrincipal mainCourse;
    tPostre dessert;


    aux1 = chooseName();
    name = tMozo(aux1);

    cout << "numero de meza: ";
    cin >> table;
    cout << endl;

    aux2 = chooseStarter();
    starter = tEntrada(aux2);

    aux3 = chooseMain();
    mainCourse = tPrincipal(aux3);

    aux4 = chooseDessert();
    dessert = tPostre(aux4);

    cout << "Mozo: " << showName(name) << endl;
    cout << "fecha:           " << currentDateTime() << endl;
    cout << "mesa:            " << table << endl;
    cout << endl;
    cout << "Entrada:         " << showStarter(starter) << endl;
    cout << "Plato Principal: " << showMain(mainCourse) << endl;
    cout << "Postre:          " << showDessert(dessert) << endl;


    return 0;
}

string showName(tMozo nombre){
    string name;

    if (nombre == Julia){
        name = "Julia";
    }
    if (nombre == Esteban){
        name = "Esteban";
    }                           /* Esto lo podria resumir con un "SWITCH" */
    if (nombre == Wally){
        name = "Wally";
    }
    if (nombre == Maria){
        name = "Maria";
    }

    return name;
}

string showStarter(tEntrada entrada){
    string starter;

    if (entrada == Champinones){
        starter = "Champinones Rellenos";
    }                                       /* Esto lo podria resumir con un "SWITCH" */
    if (entrada == Carpaccio){
        starter = "Carpaccio de Salmon";
    }
    if (entrada == Empanadas){
        starter = "Empanadas Saltenas";
    }

    return starter;
}

string showMain(tPrincipal principal){
    string mainCourse;

    if (principal == Merluza){
        mainCourse = "Merluza en Salsa";
    }
    if (principal == Muslitos){
        mainCourse = "Muslitos de Pollo al Sesamo";
    }                                               /* Esto lo podria resumir con un "SWITCH" */
    if (principal == Paella){
        mainCourse = "Paella Valenciana";
    }
    if (principal == Cordero){
        mainCourse = "Pierna de Cordero";
    }
    if (principal == SandwichTofu) {
        mainCourse = "Sandwich de Tofu con salsa Satay";
    }

    return mainCourse;
}

string showDessert(tPostre postre){
    string dessert;

    if (postre == MousseChoc){
        dessert = "Mousse de Chocolate";
    }
    if (postre == EnsaladaFrut){
        dessert = "Ensalada de Fruta";
    }                                       /* Esto lo podria resumir con un "SWITCH" */
    if (postre == Flan){
        dessert = "Flan con ddl y crema";
    }

    return dessert;
}


int chooseName(){
    int opcion;

    do {
    cout << "Nombre: " << endl;
    cout << "1_ Julia" << endl;
    cout << "2_ Esteban" << endl;
    cout << "3_ Wally" << endl;
    cout << "4_ Maria" << endl;
    cin >> opcion;
    cout << endl;
    } while (opcion < 1 || opcion > 4);

    opcion = opcion -1;

    return opcion;
}

int chooseStarter() {
    int opcion;

    do {
    cout << "Entrada: " << endl;
    cout << "1_ Champinones Rellenos" << endl;
    cout << "2_ Carpaccio de Salmon" << endl;
    cout << "3_ Empanadas Saltenas" << endl;
    cin >> opcion;
    cout << endl;
    } while (opcion < 1 || opcion > 3);

    opcion = opcion -1;

    return opcion;
}

int chooseMain() {
    int opcion;

    do {
    cout << "Plato Principal:" << endl;
    cout << "1_ Merluza en Salsa" << endl;
    cout << "2_ Muslitos de Pollo al Sesamo" << endl;
    cout << "3_ Paella Valenciana" << endl;
    cout << "4_ Pierna de Cordero" << endl;
    cout << "5_ Sandwich de Tofu con Satay" << endl;
    cin >> opcion;
    cout << endl;
    } while (opcion < 1 || opcion > 5);

    opcion = opcion -1;

    return opcion;
}

int chooseDessert() {
    int opcion;

    do {
    cout << "Postre:" <<endl;
    cout << "1_ Mousse de Chocolate" <<endl;
    cout << "2_ Flan con ddl y crema" << endl;
    cout << "3_ Ensalada de Fruta" << endl;
    cin >> opcion;
    cout << endl;
    } while (opcion < 1 || opcion > 3);

    opcion = opcion -1;

    return opcion;
}


const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);

    return buf;
}












