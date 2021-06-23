#include <iostream>
using namespace std;
#include <fstream>
#include <cctype>



int main() {
    int contador, palabras =0;
    double promedio, cantfrases =0;
    string frase;
    ifstream archivo;

    archivo.open("frasesDeBjarme.txt");

    if (archivo.is_open()){

        getline(archivo, frase);

        while (frase.size() != 0){
            contador = 0;
            cantfrases++;

            for (int i=0; i < frase.size(); i++){

                if ( frase[i+1] == ' ' || frase[i+1] == '\0' ){
                    contador++;
                }
            }

            palabras += contador;

            cout << frase << " (" << contador << ")" << endl;
            getline(archivo, frase);
        }

    }
    else {
        cout << "ERROR!!! No se pudo abrir el archivo" << endl;
    }

    archivo.close();

    promedio = palabras / cantfrases ;

    cout << "el archivo tiene " << palabras << " palabras" << endl;

    cout << "en promedio cada linea tiene " << promedio << " palabras";

    return 0;
}
