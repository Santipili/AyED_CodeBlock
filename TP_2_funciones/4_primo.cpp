#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std ;

bool primo(int num);

int main() {
	int num ;

	cout << " Ingrese un numero entero" << endl ;
	cin >> num ;

	if (primo(num)) {
		cout << " El numero es Primo" << endl;
	}
	else {
		cout << " El numero NO es Primo" << endl;
	}

	return 0;
}

bool primo(int num) {

	int resto, c;
	bool numprimo;

	c = 1;
	resto = 1;


	while (resto != 0 and c < num/2) {
		c += 1 ;
		resto = num % c ;
	}

	if (resto != 0) {
		numprimo = true ;
	}
	else {
		numprimo = false ;
	}

	return numprimo;
}
