#include <iostream>
using namespace std;

double conversion(int a, double grados) ; //La funcion se la ingresa con 1 o 2, con 1 de F° a C° y con 2 de C° a F°

int main() {
	int opcion ;
	double grados ;

	cout << "Para convertir de Celsius a Farenheit presione '1' " << endl;
	cout << "Para convertir de Farenheit a Celsius presione '2' " << endl;
	cin >> opcion ;

	cout << "Ingrese los grados" << endl;
	cin >> grados ;


	cout << "La conversion es: " << conversion(opcion, grados) ;

	return 0;
}

double conversion(int a, double grados){

	double gradosNuevos ;

	if (a==1){
		gradosNuevos = grados * 9/5 + 32 ;
	} 
	else {
		gradosNuevos = (grados - 32) * 5/9 ; 
	}

	return gradosNuevos;

} 