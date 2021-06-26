#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <iomanip>
#include <time.h>

int menu ();

int main() {
	int option;

      	option = menu();

      	while ( option != 0){

         	switch (option){
        		

        			case 1: {
        				
        			} 
        			break;

        		case 2: {
        			
        		}
        		break;

        		case 3:{
        			
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
        cout << setw(16)  << "1_ " << ""  << endl;
        cout << setw(16)  << "2_ " << "" << endl;
        cout << setw(16)  << "3_ " << "" <<  endl;
        cout << setw(16)  << "4_ " << ""  << endl;
        cout << setw(16)  << "5_ " << "" << endl;
        cout << setw(16)  << "6_ " << "" <<  endl;

        cout << endl << setw(16)  << "0_ " << "Salir" <<  endl;
        cout << setw(13) << "= ";
        cin >> op;

        if ( (op < 0) || (op > 3) ){

        cout << endl << "Opcion no Valida";

        }

	}


	return op;
}