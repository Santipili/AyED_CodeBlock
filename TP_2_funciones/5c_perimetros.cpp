#include <iostream>
#include <cmath>
using namespace std;

double calculatePerimeter ( int opcion , double ladoA, double ladoB, double ladoC);

int main() {
	int opcion;
	double perimetro, ladoA, ladoB, ladoC;

	cout << "1_Cuadrado" << endl ;
	cout << "2_Rectangulo" << endl ;
	cout << "3_Triangulo" << endl ;
	cin >> opcion ;

    while (opcion < 1 or opcion > 3){
		cout << "Ingrese una opcion valida" <<endl;
		cin >> opcion ;
	}


	if (opcion == 1) {
		cout << "Ingrese el valor de un lado" << endl;
		cin >> ladoA ;
		perimetro = calculatePerimeter (opcion, ladoA, 0, 0);
	}

	if (opcion == 2) {
		cout << "Ingrese el valor de la base y de la altura" << endl;
		cin >> ladoA ;
		cin >> ladoB ;
		perimetro = calculatePerimeter (opcion, ladoA, ladoB, 0);
	}

	if (opcion == 3) {
		cout << "Ingrese el valor de los tres lados" << endl;
		cin >> ladoA ;
		cin >> ladoB ;
		cin >> ladoC ;
		perimetro = calculatePerimeter (opcion, ladoA, ladoB, ladoC);
	}

	cout << "El perimetro es: " << perimetro;

	return 0;
}

double calculatePerimeter ( int opcion , double ladoA, double ladoB, double ladoC) {
    double perimeter;

    if (opcion == 1) {
		perimeter= 4 * ladoA;}

	if (opcion == 2)
		perimeter= 2*ladoA + 2*ladoB;

	if (opcion == 3)
		perimeter= ladoA + ladoB + ladoC;


	return perimeter;
}
