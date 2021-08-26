#include <iostream>
using namespace std;

//funciones factorizar!!!!

int main()
{
    int x, y, longRange;

    cout << "Ingrese el valor de x (primer elemento del intervalo): ";
    cin >> x;

    cout << endl << "Ingrese el valor de y (segundo elemnto del intervalo): ";
    cin >> y;
    cout << endl;

    longRange = x - y;

    if ( (abs(longRange) <= 10) )
    {
        if ( x < y )
        {
            do{
                cout << y-1 <<endl;
                y -= 1; 
            }
            while (y != x+1);

        }
        else 
        {
            do{
                cout << y+1 <<endl;
                y += 1; 
            }
            while (y != x-1);
        }

        cout << endl;
    } 
    else
    {
        cout << "El Intervalo es muy grande!!" << endl;
    }

    return 0;
}