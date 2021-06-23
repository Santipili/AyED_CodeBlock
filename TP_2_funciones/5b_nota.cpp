#include <iostream>
#include <cmath>
using namespace std;

double notafinal (double nota1, double nota2, double nota3);

int main() {
	double nota1, nota2, nota3, notatotal;

	notatotal =10 ;

	cout << "ingrese las notas" << endl;
	cin >> nota1 ;
	cin >> nota2 ;
	cin >> nota3 ;

	notatotal = notafinal(nota1, nota2, nota3);


	cout << "La nota final es: " << notatotal;

	return 0;
}

double notafinal (double nota1, double nota2, double nota3) {
    double promedio;

    promedio = (3*nota1)/10 + (3*nota2)/5 + nota3/10 ;

    return promedio;
}
