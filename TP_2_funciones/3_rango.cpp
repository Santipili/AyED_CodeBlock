#include <iostream>

using namespace std ;

bool chekRange(double minR, double maxR, double num) ;

int main() {
	double minRange, maxRange, num ;

	minRange = maxRange = num = 0 ;

    cout << "ingrese el rango separado por un espacio" << endl ;
	cin >> minRange ;
	cin >> maxRange ;

	cout << "ingrese un numero a controlar" << endl ;
	cin >> num ;



     if ( chekRange(minRange, maxRange, num) ) {
        cout << "el numero esta dentro del rango" ;
	}
	else cout << "el numero NO pertenece al rango" ;


	return 0;
}

bool chekRange(double minR, double maxR, double num) {
    bool opcion;

    if ( (num < maxR) && (num > minR) ){
        opcion = true;
    }
    else {
        opcion = false;
    }

    return opcion;
}





