#include <iostream>
using namespace std;

int main (){
    int dd, mm, aaaa, dd2, mm2, aaaa2, edad;

    cout << "Ingrese la fecha actual (dd/mm/aaaa)" << endl ;
    cin >> dd ;
    cin >> mm ;
    cin >> aaaa;

    cout << "Ingrese la fecha de su nacimiento (dd/mm/aaaa)" << endl ;
    cin >> dd2 ;
    cin >> mm2 ;
    cin >> aaaa2 ;

    edad = aaaa - aaaa2 ;

    if (mm < mm2) {
         edad -= 1;
     }

     if (mm == mm2) {
         if (dd < dd2) {
            edad -=1 ;
         }
     }

    cout << "Usted tiene " << edad << " anios!!" ;


    return 0;
}
