#include <iostream>
using namespace std;

int main ()
{
    float radio, alto, volumen, vIntermedio;

    cout << " Calcularemos el volumen de una forma conica" << endl;
    cout << " Por favor ingrese los valores precisados en cm" << endl;

    cout << " radio de la base = " ;
    cin >> radio ;
    cout << " altura = ";
    cin >> alto;

    vIntermedio = radio * radio * 3.14159 * alto ;

    volumen = vIntermedio / 3 ;

    cout << "el volumen calculado es " << volumen;

    cin.ignore(); 
    cin.get(); 
    
    return 0;
}
