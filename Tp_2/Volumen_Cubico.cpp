#include <iostream>
using namespace std;

int main ()
{   float largo, ancho, alto, volumen, vIntermedio;

    cout << " Calcularemos el volumen de una habitacion de forma cubica" << endl;
    cout << " Por favor ingrese los valores precisados en m" << endl;

    cout << " Largo = " ;
    cin >> largo ;
    cout << " Ancho = ";
    cin >> ancho ;
    cout << " Alto = ";
    cin >> alto ;

    volumen = largo * ancho * alto;

    cout << "el volumen calculado es " << volumen;

    cin.ignore(); 
    cin.get(); 

    return 0;
}
