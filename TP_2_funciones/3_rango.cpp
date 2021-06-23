#include <iostream>
using namespace std ;

int rango (double minRange, double maxRange, double num) ;

int main() {
	double minRange, maxRange, num ;

	minRange = maxRange = num = 0 ;

    cout << "ingrese el rango" << endl ;
	cin >> minRange ;
	cin >> maxRange ;

	cout << "ingrese un numero" << endl ;
	cin >> num ;


	if ( rango(minRange, maxRange, num) ) {
        cout << "el numero esta dentro del rango" ;
	}
	else cout << "el numero NO pertenece al rango" ;

	return 0;
}

int rango (double minRange, double maxRange, double num) {

	if (num <= maxRange) {
		if (num >= minRange){
			return true;
		}
		else return false ;
	}
	else return false;

}
