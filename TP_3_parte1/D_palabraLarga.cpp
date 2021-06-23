#include <iostream>
using namespace std;
#include <cctype>
#include <fstream>
#include <string>

int main() {
    int contador, aux, cantLetras ;
    string palabra, frase;
    ifstream archivo;

    archivo.open("frasesDeBjarme.txt");



    if (archivo.is_open()){

        getline(archivo, frase);


        cantLetras = 0;
        contador = 0;

        while (frase.size() != 0){



            for (int i=0; i <= frase.size(); i++){

                if (frase[i] != ' ' && frase[i] != '\0'){
                    contador++;
                }
                else {

                    if (contador >> cantLetras){

                        cantLetras = contador;

                        palabra = frase.substr(i-contador, contador);
                    }

                    contador = 0;

                }

            }

           // cout << frase << endl;
            getline(archivo, frase);

        }

    }
    else {
        cout << "ERROR!!! No se pudo abrir el archivo" << endl;
    }


    cout << palabra << " " << cantLetras;

    return 0;
}
