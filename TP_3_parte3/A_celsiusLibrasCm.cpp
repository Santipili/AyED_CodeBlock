#include <iostream>
using namespace std;

int menu ();

int main() {
	int option;

      	option = menu();

      	while ( option != 0){

         	switch (option){
        		double temperature, weight, length, aux;
        			case 1: {
        				cout << "Ingrese la longitud en Centimetros:" << endl;
        				cin >> length;

        				aux = length / 2.54;

        				length = aux;

        				cout << endl << "Su equivalente en Pulgadas es: " << length << endl;

        			}
        			break;

        		case 2: {
        			cout << "Ingrese la temperatura en Celsius:" << endl;
        			cin >> temperature;

        			aux = (temperature * 9/5) + 32;

        			temperature = aux;

        			cout << endl << "Su equivalente en Farenheit es: " << temperature << endl;

        		}
        		break;

        		case 3:{
        			cout << "Ingrese el peso en Libras:" << endl;
        			cin >> weight;

        			aux = weight * 0.4535;

        			weight = aux;

        			cout << endl << "Su equivalente en Kilogramos es: " << weight << endl;

        		}
        		break;

        	}

        	cout << endl;
        	option = menu ();
        }

        cout << endl << "Gracias, hasta luego.";


	return 0;
}

int menu (){
	int op =-1;

	while ( (op < 0) || (op > 3) ){

		cout << "Elija opcion:" << endl;
        cout << setw(16)  << "1_ " << "Centimetros --> Inch"  << endl;
        cout << setw(16)  << "2_ " << "Celsius --> Farenheit" << endl;
        cout << setw(16)  << "3_ " << "Libras --> Kilogramos" <<  endl;
        cout << endl << setw(16)  << "0_ " << "Salir" <<  endl;
        cout << setw(13) << "= ";
        cin >> op;

        if ( (op < 0) || (op > 3) ){

        cout << endl << "Opcion no Valida";

        }

	}


	return op;
}
