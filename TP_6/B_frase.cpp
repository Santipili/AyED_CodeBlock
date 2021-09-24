#include <iostream>
using namespace std;
#include <string>

int main()
{
    string frase;
    int i=0, cant=0;

    cout << "Ingrese una frase:" << endl;
    getline(cin, frase);

    do
    {
        if ((frase[i] != ' '))
        {
            cout << frase[i];
            cant++;
        }
        else 
        {
            cout << " --> tiene " << cant << " letras" << endl;
            cant = 0;
        }

        i++;

    } while (i < frase.size());

    cout << " --> tiene " << cant << " letras" << endl;

    return 0;
}

void 