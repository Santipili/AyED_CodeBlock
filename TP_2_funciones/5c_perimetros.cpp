#include <iostream>
#include <cmath>
using namespace std;

double calculateSquare (double ladoA);
double calculateRectangulo(double ladoA, double ladoB);
double calculateTriangulo(double ladoA, double ladoB, double ladoC);
int menu();

int main() {
	int opcion;
	double perimetro, ladoA, ladoB, ladoC;

    opcion = menu();

    switch (opcion){

        case 1:{

        cout << "Ingrese el valor de un lado" << endl;
        cin >> ladoA ;

        perimetro = calculateSquare(ladoA);

        } break;

        case 2:{
            cout << "Ingrese el valor de la base y de la altura" << endl;
            cin >> ladoA ;
            cin >> ladoB ;

            perimetro = calculateRectangulo(ladoA, ladoB);

		} break;

        case 3:{
            cout << "Ingrese el valor de los tres lados" << endl;
            cin >> ladoA ;
            cin >> ladoB ;
            cin >> ladoC ;

            perimetro = calculateTriangulo(ladoA, ladoB, ladoC);
        } break;

    }

	cout << "El perimetro es: " << perimetro;

	return 0;
}


double calculateSquare (double ladoA){
    double perimetro;

    perimetro = 4 * ladoA;

    return perimetro;
}

double calculateRectangulo (double ladoA, double ladoB){
    double perimetro;

    perimetro = 2*ladoA + 2*ladoB;

    return perimetro;
}

double calculateTriangulo ( double ladoA, double ladoB, double ladoC) {
    double perimetro;

    perimetro= ladoA + ladoB + ladoC;

	return perimetro;
}

int menu(){
    int opcion;

   do {
        cout << "1_Cuadrado" << endl ;
        cout << "2_Rectangulo" << endl ;
        cout << "3_Triangulo" << endl ;
        cin >> opcion;
	} while (opcion < 1 or opcion > 3);

    return opcion;
}
