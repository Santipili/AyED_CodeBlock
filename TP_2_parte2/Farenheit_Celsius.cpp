#include <iostream>
using namespace std;

int main() {
	double gradosF, gradosC ;

	cout << "Ingrese la temperatura en Farenheit" << endl ;
	cin >> gradosF ;

	gradosC= (gradosF - 32) * 5/9 ; 

	cout << "la temperatura equivalente en Celsius es " << gradosC ;

	return 0;
}