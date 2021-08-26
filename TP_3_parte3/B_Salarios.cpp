#include <iostream>
using namespace std;

double getSalary (double x) ;

int main() {
	double x, nuevo_x;

    cout << "Ingrese el sueldo a incrementar:" << endl;
    cin >> x;

    nuevo_x = getSalary(x);

    cout << endl;
    cout << "$" << x << " -----> nuevo suelod: $" << nuevo_x;

    cout << endl << "Good Bye!!";

	return 0;
}

double getSalary (double x) { // como uso switch aqui??
    double salary;
    int aumento;

    if (0 < x && x <= 9000) aumento = 20;

    if (9000 < x && x <= 15000) aumento = 10;

    if (15000 < x && x <= 20000) aumento = 5;

    if (x > 20000) aumento = 3;

    salary = x*aumento/100 + x;

    return salary;
}