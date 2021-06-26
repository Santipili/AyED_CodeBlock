#include <iostream>
using namespace std;
#include <fstream>
#include <string>

int main() {
    ofstream archivo;
    string frase;
    int contador=1;

    archivo.open("frasesDeBjarme.txt");   //creee el archivo de txt, el ofstream me deja crear el ifstream lee

    cout << "ingrese la frase " << contador << " (X(mayuscula) para terminar):" << endl;
    getline(cin, frase);

    while (frase != "X") {
        contador++;
        archivo << frase << endl;
        cout << "ingrese la frase " << contador << " (X (mayuscula) para terminar):" << endl;
        getline(cin, frase);
    }

    archivo.close(); // cierro el archivo de texto

    return 0;
}
