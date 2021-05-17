#include <iostream>
using namespace std;

int main ()
{
    float a, b, valor;
    int operacion;

    cout << " Bienvenido a la Calculadora de Santiago" << endl;

    cout << " ingrese un primer valor " << endl;
    cout << " A = " ;
    cin >> a;

    cout << " Seleccione una operacion " << endl;
    cout << " 1._ Suma " << endl ;
    cout << " 2._ Resta " << endl ;
    cout << " 3._ Multiplicacion " << endl ;
    cout << " 4._ Division " << endl ;
    cin >> operacion;

    cout << " ingrese el segundo valor " << endl;
    cout << " B = " ;
    cin >> b;

   if (operacion == 1) {
        valor = a + b;
        cout << "el resultado es " << valor;
        }

    if (operacion == 2) {
        valor = a - b;
        cout << "el resultado es " << valor;
        }

    if (operacion == 3) {
        valor = a * b;
        cout << "el resultado es " << valor;
        }

    if (operacion == 4) {
        valor = a / b;
        cout << "el resultado es " << valor;
        }


    return 0;
}
