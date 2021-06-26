#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <iomanip>
#include <time.h>

typedef enum{ Manzana, Kiwi, Pera, Banana, Naranja, Mandarina} tFruit;

const string currentDateTime();

string showFruit (tFruit fruta);

int main() {

    typedef int tProvedor;
    typedef int tfechaEntrega;

    tProvedor codigo;
    tfechaEntrega dia, mes, anio;
    tFruit fruta;
    string razonsocial;
    int aux;


    cout << "ingrese el codigo del provedor: ";
    cin >> codigo;
    cin.get();

    cout << "ingrese razon social: ";
    getline(cin, razonsocial);

    cout << "ingrese fecha de entrega"<< endl;
    cout << setw(8) << "dia: ";
    cin >> dia;

    cout << setw(8) << "mes: ";
    cin >> mes;

    cout << setw(8) << "ano: ";
    cin >> anio;


        cout << endl << "Elija Frutas:" << endl;
        cout << setw(16)  << "1_ " << "Manzana"  << endl;
        cout << setw(16)  << "2_ " << "Kiwi" << endl;
        cout << setw(16)  << "3_ " << "Pera" <<  endl;
        cout << setw(16)  << "4_ " << "Banana"  <<  endl;
        cout << setw(16)  << "5_ " << "Naranja"  <<  endl;
        cout << setw(16)  << "6_ " << "Mandarina" <<  endl;
        cout << setw(13) << "= ";
        cin >> aux;

        fruta = tFruit(aux-1);



    cout << endl << "fecha" << setw(13) << ": ";
    cout << currentDateTime() << endl;
    cout << "codigo provedor" << setw(3) << ": " << codigo << endl;
    cout << "razon social" << setw(6) << ": " << razonsocial << endl;
    cout << "pedido" << setw(12) << ": " << showFruit(fruta) << endl;
    cout << "fecha de entrega: " << setw(2) << dia << "-" << setw(2) << mes << "-" << anio << endl;

    return 0;
}

string showFruit (tFruit fruta){
    string eleccion;

    if (fruta == Manzana) {
        eleccion = "Manzanana";
    }
    if (fruta == Kiwi){
        eleccion = "Kiwi";
    }
    if (fruta == Pera){
        eleccion = "Pera";
    }
    if (fruta == Banana){
        eleccion = "Banana";
    }
    if (fruta == Naranja){
        eleccion = Naranja;
    }
    if (fruta == Mandarina){
        eleccion = "Mandarina";
    }

   return eleccion;
}

const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}
