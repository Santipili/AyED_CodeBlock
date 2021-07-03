#include <iostream>

using namespace std ;

void showDatos (int edad, string sexo, double altura) ;

int main() {
	int edad;
	string sexo;
	double altura;

	cout << "ingrese su Edad : " ;
	cin >> edad ;

	cout << "Ingrese su sexo (Masculino/Femenino/Otro) : " ;
	cin >> sexo ;

	cout << "Ingrese su altura (en mts) : " ;
	cin >> altura ;

	showDatos(edad, sexo, altura) ;

	return 0;
}

void showDatos (int edad, string sexo, double altura){

	cout << "Sus datos son " << endl ;
	cout << "         Edad: " << edad << endl;
	cout << "         Sexo: " << sexo << endl;
	cout << "       Altura: " << altura ;

	return;
}
