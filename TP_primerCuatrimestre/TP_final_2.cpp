#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <iomanip> //lo utilizare cuando tenga q ordenar los datos en pantalla

typedef struct 
{
    string name;
    string surname;
    int ticket;
    int long phone;
    bool confirmation;
    struct 
    {
       string street;
       int number;
    } address;    

} tEstructura;

const int Dim = 1000; // de 0 a 999
typedef tEstructura tVector[Dim];

typedef struct 
{
    tVector guest;
    int contador;
} tLista;

void loadList (const string path, tLista& LISTA);
int chooseOption ();
void showList(tLista LISTA); 
string showConfirmation (bool confirmacion);
void addNew (tLista& LISTA);
void saveList (tLista LISTA);

int main () 
{
    tLista lista;
    int op;

    loadList ("lista_de_invitados.txt", lista);

    do
    {
        op = chooseOption();

        switch (op)
        {
            case 1:
            {
                showList(lista);
            } break;

            case 2:
            {
                addNew (lista);

            } break;

            case 3:
            {

            } break;

            case 4:
            {

            } break;

            case 5:
            {

            }
        }

    } while (op < 6); 

    saveList (lista);

    cout << "Hasta Luego";

    return 0;
}

void loadList (const string path, tLista& LISTA) 
{
    ifstream archivoLista;
    char aux;
    int pos;

    LISTA.contador = pos = 0;

    archivoLista.open(path); 

    if (archivoLista.is_open()) 
    {        
        do 
        {  
            archivoLista >> LISTA.guest[pos].ticket;

            archivoLista.get(aux);
            getline(archivoLista, LISTA.guest[pos].name);

          //  archivoLista.get(aux);
            getline(archivoLista, LISTA.guest[pos].surname);

            archivoLista >> LISTA.guest[pos].phone;

            archivoLista.get(aux);
            getline(archivoLista, LISTA.guest[pos].address.street);

            archivoLista >> LISTA.guest[pos].address.number >> LISTA.guest[pos].confirmation;

                    
            pos++;  

        } while ( !archivoLista.eof() ); 

        LISTA.contador = pos ;

    }

    archivoLista.close();

    return;
}

int chooseOption () 
{
    int op;
    
    do 
    {
        cout << "Que desea hacer?" << endl;
        cout << "1.- Ver Lista Completa de Invitados" << endl;
        cout << "2.- Agregar Nuevo Invitado" << endl;
        cout << "3.- Ver datos de un invitado especifico" << endl;
        cout << "4.- Eliminar invitado" << endl;
        cout << "5.- Modificar datos" << endl;
        cout << "6.- Salir" << endl;
        cin >> op;
    } while ( op < 1 || op > 6);

    return op;
}

void showList(tLista LISTA) 
{
    cout << "Lista de de Invitados ("<< LISTA.contador <<")" << endl;

    for (int i=0; i < LISTA.contador; i++) 
    {
        cout << setw(10) << showConfirmation( LISTA.guest[i].confirmation ) << " - "<<LISTA.guest[i].surname << ", " << LISTA.guest[i].name << " - Nro. Ticket: " << LISTA.guest[i].ticket<< endl;
    }

    return;
}

string showConfirmation (bool confirmacion)
{
    string respuesta;

    if (confirmacion)
    {
        respuesta = "Confirmado";
    }
    else
    {
        respuesta = "";
    }

    return respuesta;
}

void addNew (tLista& LISTA) 
{
    int aux;
    char enter;

    cout << "Nuevo Invitado.-" << endl;
    cin.get(enter);
    cout << "Nombre/s: "; getline( cin, LISTA.guest[LISTA.contador].name );
    cout << "Apellido: "; getline ( cin, LISTA.guest[LISTA.contador].surname);
    cout << "Telefono: "; cin >> LISTA.guest[LISTA.contador].phone;
    cin.get(enter);
    cout << "Calle: "; getline ( cin, LISTA.guest[LISTA.contador].address.street);
    cout << "numero: "; cin >> LISTA.guest[LISTA.contador].address.number;

   // cout << "Confirmado: "

    aux = LISTA.contador + 1675000;

    LISTA.guest[LISTA.contador].ticket = aux;

    LISTA.contador++;

    return;
}

void saveList (tLista LISTA)
{
    ofstream archivoLista;

    archivoLista.open("lista_de_invitados.txt");

    for (int i=0; i < LISTA.contador; i++)
    { 
    archivoLista << endl; 
    archivoLista << LISTA.guest[i].ticket << endl;
    archivoLista << LISTA.guest[i].name << endl;
    archivoLista << LISTA.guest[i].surname << endl;
    archivoLista << LISTA.guest[i].phone << endl;
    archivoLista << LISTA.guest[i].address.street << endl;
    archivoLista << LISTA.guest[i].address.number << endl;
    archivoLista << LISTA.guest[i].confirmation;
    }

    return; 
}

        

