#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int segundos, ss, mm, hh, restoss ;

	cout << "Ingrese la cantidad de segundos totales" << endl;
	cin >> segundos ;

	hh = segundos / 3600 ; 
	restoss = segundos % 3600 ;
	mm = restoss / 60 ;
	ss = restoss % 60 ;

	cout << segundos << " segundos son equivalentes a " << hh << ":" << mm << ":" << ss ;

	return 0;
}