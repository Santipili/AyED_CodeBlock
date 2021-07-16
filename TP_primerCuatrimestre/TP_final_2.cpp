#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

typedef struct
{
    string name;
    string surname;
    int ticket;
    string phone;
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

void loadList (const string path, tLista& LISTA);                   //Carga Lista de invitados a memoria
int chooseOption ();                                                // Menu principal
void showList(tLista LISTA);                                        // Muestra Lista Completa
string showConfirmation (bool confirmacion);                        // Muestra dato de confirmacion (booleano)
void addNew (tLista& LISTA);                                        // Agregar nuevo elemento a la lista
void saveList (tLista LISTA, const string path);                    // Guarda la lista en memoria en un archivo .txt
void showSpecific (tLista LISTA, int position);                     // Muestra los datos de un invitado especifico
void deleteGuest (tLista& LISTA, int position);                     // Eliminar invitado, tambien boora el ticker
void confirmGuests (tLista& LISTA);                                 // Lista para confirmar asistencia
int searchPosition (tLista LISTA, int numticket);                   // Funcion para buscar invitado por numero de ticket
void modifyGuest (tLista& LISTA, int position , int optionChange);  // Modifica datos de un invitado
int chooseWhat ();                                                  // menu de opciones a modificar

int main ()
{
    tLista list;
    int option;

    loadList ("lista_de_invitados.txt", list);

    do
    {
        option = chooseOption();

        switch (option)
        {
            case 1: //Mostrar lista completa
            {
                showList(list);
            } break;

            case 2: // agregar nuevo invitado
            {
                addNew (list);
            } break;

            case 3: // mostrar datos de un invitado
            {
                int numticket;
                int position;

                cout << endl << "ingrese numero de ticket: "; cin >> numticket;

                position = searchPosition (list, numticket);

                showSpecific (list, position);
            } break;

            case 4: // eliminar invitado
            {
                char continueDelete;

                cout << "ATENCION!!! Si elimina un invitado tambien eliminara el ticket, para asignarselo a otra persona modifique invitado (opcion 5)" << endl;

                cout << "Desea continuar? (Y/N): "; cin >> continueDelete;
                continueDelete = toupper(continueDelete);

                if (continueDelete == 'Y')
                {
                    int numticket;
                    int position;

                    cout << endl << "ingrese numero de ticket: "; cin >> numticket;

                    position = searchPosition (list, numticket);

                    deleteGuest (list, position);
                    cout << endl;
                }
                else
                {
                    cout << endl;
                }

            } break;

            case 5: // modificar datos de un invitado
            {   int numticket;
                int position;
                int optionChange;

                cout << endl << "ingrese numero de ticket: "; cin >> numticket;

                position = searchPosition (list, numticket);

               // modifyGuest (list, position);

                optionChange = chooseWhat();

                modifyGuest(list, position, optionChange);

            } break;

            case 6: // confirmar asistencias
            {
                confirmGuests (list);
            }
        }

    } while (option < 7);

    if (option == 7)
    {
        saveList (list, "lista_de_invitados.txt");
    }

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

            getline(archivoLista, LISTA.guest[pos].surname);

            getline(archivoLista, LISTA.guest[pos].phone);

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
        cout << "3.- Ver datos de un invitado" << endl;
        cout << "4.- Eliminar invitado" << endl;
        cout << "5.- Modificar datos" << endl; // y agregar confirmacion
        cout << "6.- Confirmar Invitados" << endl;
        cout << "7.- Guardar y Salir" << endl;
        cout << "8.- Salir" << endl;
        cin >> op;
    } while ( op < 1 || op > 8);

    return op;
}

void showList(tLista LISTA)
{
    cout << endl;
    cout << "Lista de de Invitados ("<< LISTA.contador <<" invitados)" << endl;

    cout << "CONFIRMACION" << " | " << setw(15) << "APELLIDO" << " | " << setw(18) << "NOMBRE";
    cout << " | " << setw(12) << "NRO. TICKET"<< endl;

    cout << endl;

    for (int i=0; i < LISTA.contador; i++)
    {
        cout << setw(12) << showConfirmation( LISTA.guest[i].confirmation ) << " | ";
        cout << setw(15) << LISTA.guest[i].surname << " | " << setw(18) << LISTA.guest[i].name << " | ";
        cout << setw(12) << LISTA.guest[i].ticket<< endl;
    }

    cout << endl;

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

    char enter;

    cin.ignore();

    cout << endl;
    cout << "Nuevo Invitado.-" << endl;
    cout << "Nombre/s: "; getline( cin, LISTA.guest[LISTA.contador].name );
    cout << "Apellido: "; getline ( cin, LISTA.guest[LISTA.contador].surname);
    cout << "Telefono: "; getline ( cin, LISTA.guest[LISTA.contador].phone);
  //  cin.ignore();
    cout << "Direccion" << endl;
    cout << "Calle: "; getline ( cin, LISTA.guest[LISTA.contador].address.street);
    cout << "Numero: "; cin >> LISTA.guest[LISTA.contador].address.number;
    cout << endl;

    LISTA.guest[LISTA.contador].confirmation = 0;

    if (LISTA.contador == 0)
    {
        LISTA.guest[LISTA.contador].ticket =  1675000;
    }
    else
    {
        LISTA.guest[LISTA.contador].ticket =  LISTA.guest[LISTA.contador - 1].ticket +1;
    }

    LISTA.contador++;

    return;
}

void saveList (tLista LISTA, const string path)
{
    ofstream archivoLista;

    archivoLista.open(path);

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

void showSpecific (tLista LISTA, int position)
{

    cout << endl;
    cout << "Nombre Completo...: " << LISTA.guest[position].surname << ", " << LISTA.guest[position].name << endl;
    cout << "Nro. Telefono.....: " << LISTA.guest[position].phone << endl;
    cout << "Direccion.........: " << LISTA.guest[position].address.street << " " << LISTA.guest[position].address.number << endl;
    cout << setw(10) << showConfirmation( LISTA.guest[position].confirmation ) << endl;


    return;
}

void deleteGuest (tLista& LISTA, int position)
{
    for (int i = position; i < LISTA.contador - 1; i++)
    {
        LISTA.guest[i].ticket = LISTA.guest[i+1].ticket;
        LISTA.guest[i].surname = LISTA.guest[i+1].surname;
        LISTA.guest[i].name = LISTA.guest[i+1].name;
        LISTA.guest[i].phone = LISTA.guest[i+1].phone;
        LISTA.guest[i].address.street = LISTA.guest[i+1].address.street;
        LISTA.guest[i].address.number = LISTA.guest[i+1].address.number;
        LISTA.guest[i].confirmation = LISTA.guest[i+1].confirmation;
    }

    LISTA.contador = LISTA.contador -1;

    return;
}

void confirmGuests (tLista& LISTA)
{
    char aux;

    cout << endl;
    cout << "NRO. TICKET"  << " | " << setw(15) << "APELLIDO" << " | " << setw(18) << "NOMBRE";
    cout << " | " << "CONFIRMACION" << endl;

    for (int i=0; i < LISTA.contador; i++)
    {
        if (LISTA.guest[i].confirmation)
        {
            cout << setw(11) << LISTA.guest[i].ticket << " | ";
            cout << setw(15) << LISTA.guest[i].surname << " | " << setw(18) << LISTA.guest[i].name << " | ";
            cout << "Confirmado" << endl;
        }
        else
        {
            cout << setw(11) << LISTA.guest[i].ticket << " | ";
            cout << setw(15) << LISTA.guest[i].surname << " | " << setw(18) << LISTA.guest[i].name << " | ";
            cout << " ---> Confirmar? (y/n): ";
            cin >> aux;

            aux = toupper(aux);

            if (aux == 'Y' )
            {
                LISTA.guest[i].confirmation = true;
            }
            else
            {
                LISTA.guest[i].confirmation = false;
            }
        }
    }

    cout << endl;

    return;
}

int searchPosition (tLista LISTA, int numticket)
{
    int position = -1;

    do
    {
        position++;
    } while (LISTA.guest[position].ticket != numticket);

    return position;
}

void modifyGuest (tLista& LISTA, int position , int optionChange)
{
    char aux;

    cin.ignore();

    switch (optionChange)
    {
        case 1:
        {
            cout << "Nombre/s..........: ";
            getline(cin,LISTA.guest[position].name);
        } break;

        case 2:
        {
            cout << "Apellido..........: "; getline(cin,LISTA.guest[position].surname);
        } break;

        case 3:
        {
            cout << "Nro. Telefono.....: "; getline ( cin, LISTA.guest[LISTA.contador].phone);
        } break;

        case 4:
        {
            cout << "Direccion" << endl;
            cout << "Calle.............: "; getline(cin,LISTA.guest[position].address.street);
            cout << "Numero............: "; cin >> LISTA.guest[position].address.number;

        } break;

        case 5:
        {
            cout << "¿Confirmado? (Y/N): "; cin >> aux;
            aux = toupper(aux);

            if (aux == 'Y')
            {
                LISTA.guest[position].confirmation = true;
            }
            else
            {
                LISTA.guest[position].confirmation = false;
            }
        } break;

        case 6:
        {
            cout << "Nuevos Datos" << endl;
            cout << "Nombre/s..........: "; getline(cin,LISTA.guest[position].name);
            cout << "Apellido..........: "; getline(cin,LISTA.guest[position].surname);
            cout << "Nro. Telefono.....: "; getline ( cin, LISTA.guest[LISTA.contador].phone);
            cout << "Direccion" << endl;
            cout << "Calle.............: "; getline(cin,LISTA.guest[position].address.street);
            cout << "Numero............: "; cin >> LISTA.guest[position].address.number;
            cout << "¿Confirmado? (Y/N): "; cin >> aux;
            aux = toupper(aux);

            if (aux == 'Y')
            {
            LISTA.guest[position].confirmation = true;
            }
            else
            {
                LISTA.guest[position].confirmation = false;
            }
        }
    }

    cout << endl;

    return;
}

int chooseWhat ()
{
    int op;

    do
    {
        cout << "Que desea cambiar?" << endl;
        cout << "1.- Nombre/s" << endl;
        cout << "2.- Apellido" << endl;         //Elegir que
        cout << "3.- Nro. Telefono" << endl;
        cout << "4.- Direccion" << endl;
        cout << "5.- Confirmacion" << endl;
        cout << "6.- Todo" << endl;
        cin >> op;

    } while (op<1 || op>6);

    return op;
}

