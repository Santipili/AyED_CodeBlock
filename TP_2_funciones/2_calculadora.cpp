#include <iostream>

using namespace std;

double calculadora(int o, double a, double b) ;
int menu();

int main ()
{
    double A , B ;
    int operacion ;

    cout << " Ingrese un primer valor " << endl;
    cout << " A = " ;
    cin >> A;

   operacion = menu();

    cout << " Ingrese un segundo valor " << endl;
    cout << " B = " ;
    cin >> B;

    cout << " El resultado es " << calculadora(operacion,A,B) ;

    return 0;
}

int menu() {
    int opcion;

    do {
    cout << " Seleccione una operacion " << endl;
    cout << " 1._ Suma " << endl ;
    cout << " 2._ Resta " << endl ;
    cout << " 3._ Multiplicacion " << endl ;
    cout << " 4._ Division " << endl ;
    cin >> opcion;
    }
     while ( (opcion < 1) || (opcion > 4) ) ;

    return opcion;
}

double calculadora (int op, double x, double y ) {
    double resultado;

    switch (op)  {

        case 1:{
            resultado = x +y;

        } break;

        case 2:{
            resultado = x - y;

        } break;

        case 3:{
            resultado = x*y;

        } break;

        case 4:{
            resultado = x/y;

        } break;
    }

    return resultado;
}


