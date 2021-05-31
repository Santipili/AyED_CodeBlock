#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
    double radio = 14.5, alto = 26.79, volumen;

    cout << "Calcularemos el volumen de una forma conica" << endl;
    cout << "con radio de la base de 14.5cm y de altura 26.79cm" << endl;
     
    cin.get() ;

    volumen = pow(radio , 2) * 3.141592 * alto / 3;


    cout << "el volumen calculado es " << volumen << setprecision(2) ;

    
    return 0;
}
