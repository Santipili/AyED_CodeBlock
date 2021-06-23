#include <iostream>
using namespace std;
#include <cctype>
#include <fstream>

int main(){
    int contador;
    ifstream archivo;
    string frases;
    char c;

    archivo.open("frasesDeBjarme.txt");

    if (archivo.is_open()){
        getline(archivo, frases);

        while (frases.size() != 0){
            cout << frases << endl;
            getline(archivo, frases);
        }
    }
    else {
        cout << "ERROR!!! No se pudo abrir el archivo" << endl;
    }

    archivo.close();

    return 0;
}
