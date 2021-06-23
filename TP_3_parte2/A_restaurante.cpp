#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <iomanip>

typedef enum {Julia, Esteban, Wally, Maria} tMozo;
typedef enum {Champinones, Carpaccio, Empanadas } tEntrada;
typedef enum {Merluza, Muslitos, Paella, Cordero, SandwichTofu} tPrincipal;
typedef enum {MousseChoc, EnsaladaFrut, Flan} tPostre;


string showName(tMozo nombre);
string showStarter(tEntrada entrada);
string showMain(tPrincipal principal);
string showDessert(tPostre postre);

int main() {
    int table, hour, day, month, aux;
    string comentario;
    tMozo name;
    tEntrada starter;
    tPrincipal mainCourse;
    tPostre dessert;

    cout << "nombre: " << endl;
    cout << "1_ Julia" << endl;
    cout << "2_ Esteban" << endl;
    cout << "3_ Wally" << endl;
    cout << "4_ Maria" << endl;
    cin >> aux;
    name = tMozo(aux-1);

    cout << "numero de meza: " << endl;
    cin >> table;

    cout << "Entrada: " << endl;
    cout << "1_ Champinones Rellenos" << endl;
    cout << "2_ Carpaccio de Salmon" << endl;
    cout << "3_ Empanadas Saltenas" << endl;
    cin >> aux;
    starter = tEntrada(aux-1);

    cout << "Plato Principal:" << endl;
    cout << "1_ Merluza en Salsa" << endl;
    cout << "2_ Muslitos de Pollo al Sesamo" << endl;
    cout << "3_ Paella Valenciana" << endl;
    cout << "4_ Pierna de Cordero" << endl;
    cout << "5_ Sandwich de Tofu con Satay" << endl;
    cin >> aux;
    mainCourse = tPrincipal(aux-1);

    cout << "Postre:" <<endl;
    cout << "1_ Mousse de Chocolate" <<endl;
    cout << "2_ Flan con ddl y crema" << endl;
    cout << "3_ Ensalada de Fruta" << endl;
    cin >> aux;
    dessert = tPostre(aux-1);

    cout << "Mozo: " << showName(name) << endl;
    cout << "el dia de hoy --- mesa: " << table << endl; /* debo agregar la fecha y hora */
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
    }
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
    }
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
    }
    if (postre == Flan){
        dessert = "Flan con ddl y crema";
    }

    return dessert;
}




















