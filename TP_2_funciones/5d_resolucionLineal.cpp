#include <iostream>
#include <cmath>
using namespace std;

double pendiente (double x1, double y1, double x2, double y2) ;
double ordenada (double x, double y, double m) ;

int main() {
    int x1, y1, x2, y2 ;
    double m, b ;

    cout << "ingrese las coordenadas de un punto ";
    cin >> x1 ;
    cin >> y1 ;

    cout << "ingrese las coordenadas de otro punto " ;
    cin >> x2 ;
    cin >> y2 ;

    m = pendiente(x1,y1,x2,y2) ;

    b = ordenada(x1,y1,m) ;

    if (b < 0){
         cout << "La ecuacion de la recta es : Y = " << m << "X " << b << endl ;
    }
    else {
        cout << "La ecuacion de la recta es : Y = " << m << "X + " << b << endl ;
    }

    return 0 ;
}

double pendiente (double x1, double y1, double x2, double y2) {
    double m ;

    m = (y2 - y1) / (x2 - x1) ;

    return m;
}

double ordenada (double x, double y, double m) {
    double b ;

    b = y - x*m ;

    return b ;
}
