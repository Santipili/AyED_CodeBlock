#include <iostream>
using namespace std;


int main (){
	double n1, n2, n3, promedio;


	cout << "Ingrese 3 numeros para calcular su promedio" << endl;
	cin >> n1 ;
	cin >> n2 ;
	cin >> n3 ;

	promedio = (n1 + n2 + n3) / 3 ;

	cout << "el promedio es " << promedio ;

	return 0;

}
