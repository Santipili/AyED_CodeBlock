#include <iostream>
using namespace std;

double specializeX( double x );

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;

    cout << "Especializaremos 4 valores de x en la recta Y=2*X+1 " << endl;

    cout << "Ingrese un valor para x1: "; cin >> x1;
    cout << "Ingrese un valor para x2: "; cin >> x2;
    cout << "Ingrese un valor para x3: "; cin >> x3;
    cout << "Ingrese un valor para x4: "; cin >> x4;

    y1 = specializeX(x1);
    y2 = specializeX(x2);
    y3 = specializeX(x3);
    y4 = specializeX(x4);

    cout << "Para x=" << x1 << " --> y=" << y1 << endl;
    cout << "Para x=" << x2 << " --> y=" << y2 << endl;
    cout << "Para x=" << x3 << " --> y=" << y3 << endl;
    cout << "Para x=" << x4 << " --> y=" << y4 << endl;

	return 0;
}

double specializeX( double x ){
    double y;
    y = 2*x + 1;
    return y;
}
