#include <iostream>
using namespace std;

int main () {
	double n1, n2, n3, n4, producto;

	cout << "Ingrese 4 numeros que se multiplicaran entre si" << endl ;
	cin >> n1 ;
	cin >> n2 ;
	cin >> n3 ;
	cin >> n4 ;

	producto = n1*n2*n3*n4 ;

	cout << "El producto total es " << producto ;

	return 0;
}