#include <iostream>
using namespace std;
#include <cctype>
#include <fstream>
#include <string>


int main() {
    int contador, aux, cantLetras, maxPalabras ;
    string palabra, frase;
    ifstream archivo;

    palabra = "a";
    maxPalabras = 0;


    archivo.open("frasesDeBjarme.txt");

    if ( archivo.is_open() ) {

        getline(archivo, frase);

        while (frase.size() != 0){
            contador = 0;
            
            for (int i=0; i < frase.size(); i++){

                if ( frase[i+1] == ' ' || frase[i+1] == '\0' ){
                    contador++;
                }
            }

            maxPalabras += contador;
           
            getline(archivo, frase);

        }
    
    }
    else {

        cout << "ERROR!!! No se pudo abrir el archivo" << endl;

    }

    archivo.close(); 

    archivo.open("frasesDeBjarme.txt");

    if ( archivo.is_open() ) {
        archivo >> frase ;

        for ( int i = 0; i <= maxPalabras; i++ ){ //agregar condicion de while

            if (frase.size() > palabra.size() ){

                palabra = frase;
            }

            archivo >> frase;

        }

        cantLetras = palabra.size();

        cout << "La palabra mas larga es: " <<palabra << endl;
        cout << "Y contiene " << cantLetras << " letras";

    }
    else {

        cout << "ERROR!!! No se pudo abrir el archivo" << endl;

    }

    archivo.close();

    return 0;
}

