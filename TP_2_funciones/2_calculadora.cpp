#include <iostream>
#include <cstdlib>
using namespace std;

double calculadora(int o, double a, double b) ;

int main ()
{
    double A , B ;
    int operacion ;

    cout << " Ingrese un primer valor " << endl;
    cout << " A = " ;
    cin >> A;

    cout << " Seleccione una operacion " << endl;
    cout << " 1._ Suma " << endl ;
    cout << " 2._ Resta " << endl ;
    cout << " 3._ Multiplicacion " << endl ;
    cout << " 4._ Division " << endl ;
    cin >> operacion;

    cout << " Ingrese un segundo valor " << endl;
    cout << " B = " ;
    cin >> B;

    cout << " El resultado es " << calculadora(operacion,A,B) ;
    
    return 0;
}

double calculadora (int o, double a, double b ) {
    double valor ; 

/*  operacion
    " 1._ Suma " 
    " 2._ Resta "
    " 3._ Multiplicacion " 
    " 4._ Division "    */

    if (o == 1) {
        valor = a + b;
        }

    if (o == 2) {
        valor = a - b; 
        }

    if (o == 3) {
        valor = a * b;     
        }

    if (o == 4) {
        valor = a / b;       
        }

    return valor;
}