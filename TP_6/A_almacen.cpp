#include <iostream>
using namespace std;
#include <fstream> 

const int maxProducts= 100;
typedef struct 
{
    long int ID;
    double precio;
    int cant_units;
} tProduct;
typedef tProduct tVector[maxProducts];
typedef struct
{
    tVector allProducts;
   // tProduct allProducts[maxProducts];  ----Por motivos de abstraccion esto no se hace----
    int count;
} tList;

void loadList(const string path, tList& LISTA);
int chooseOption();
void showList(tList LISTA); 
int searchHigherValue(tList LISTA);
int searchProduct(tList LISTA, long int ID);
void deleteProduct(tList& LISTA, int position);
void addNewProduct(tList& LISTA);

int main() 
{
    tList productList;
    long int ID;
    int option, position;

    cout << "Cargando Lista..." << endl;

    loadList("productos_almacen.txt", productList);
    
    do
    {
        option = chooseOption();

        switch (option)
        {
            case 1:
            {
                showList(productList);
            } break;

            case 2:
            {
               position = searchHigherValue(productList);

               cout << "El producto con valor mas alto es:" << endl;
               cout << productList.allProducts[position].ID << "||" << productList.allProducts[position].precio << "||" << productList.allProducts[position].cant_units << endl;
            } break;

            case 3:
            {
                cout << "Ingrese la ID del producto: ";
                cin >> ID;

                position = searchProduct(productList, ID);

                if (position == -1)
                {
                    cout << "No se encontro coincidencia en la Lista" << endl;
                }
                else
                {
                    deleteProduct(productList, position);
                    cout << "Producto Eliminado con Exito" << endl;
                }
            }break;

            case 4:
            {
                addNewProduct(productList);
            }
        }

        cout << endl;


    } while ( option != 0);
    
    cout << "Good Bye!" << endl;


    return 0;
}

void loadList (const string path, tList& LISTA)
{
    ifstream archivoLista;
    int pos;

    LISTA.count = pos = 0;

    archivoLista.open(path);

    if (archivoLista.is_open())
    {
        while ( !archivoLista.eof() ){
           
                archivoLista >> LISTA.allProducts[pos].ID;
                archivoLista >> LISTA.allProducts[pos].precio;
                archivoLista >> LISTA.allProducts[pos].cant_units; 

                pos++;          
        }

        LISTA.count = pos;

    }
    else
    {
        cout << "Error al cargar archivo" << endl;
    }
    
    archivoLista.close();

    return; //puede no tener
}

int chooseOption()
{
    int option;

    do
    {
        cout << "Menu" << endl;
        cout << "1.- Mostrar Lista Completa" << endl;
        cout << "2.- Buscar Valor mas Alto" << endl;
        cout << "3.- Eliminar Producto" << endl;
        cout << "4.- Agregar Nuevo Producto" << endl;
      //  cout << "5.-" << endl;
        cout << "0.- Salir" << endl;
        cout << endl;

        cin >> option;
    } while ((option < 0) || (option > 4));
    
    return option;
}

void showList (tList LISTA) 
{
   cout << endl << "ID_producto" << "||" << "Precio" << "||" << "Unidades" << endl;

   for (int i=0; i < LISTA.count; i++)
   {
       cout << LISTA.allProducts[i].ID << "||" << LISTA.allProducts[i].precio << "||" << LISTA.allProducts[i].cant_units << endl;
   }

   cout << endl;
}

int searchHigherValue (tList LISTA)
{
    int pos;
    double value, valueAux; 

    value = 0;

    for (int i=0; i < LISTA.count; i++)
    {
        valueAux = LISTA.allProducts[i].precio * LISTA.allProducts[i].cant_units;

        if (valueAux > value)
        {
            value = valueAux;

            pos = i;
        }

    }

    return pos;
}

int searchProduct (tList LISTA, long int ID) // devuelve -1 si no encontro el ID
{
    int pos, i;

    i=-1;

    do
    {
        i++;
        
    } while ((ID != LISTA.allProducts[i].ID) && (i < LISTA.count));

    if (i<LISTA.count)
    {
        pos = i;
    }
    else 
    {
        pos = -1;
    }

    return pos;   
}

void deleteProduct (tList& LISTA, int position)
{
    for (int i = position; i < LISTA.count-1; i++)
    {
        LISTA.allProducts[i] = LISTA.allProducts[i+1];
    }

    LISTA.count--;
}

void addNewProduct (tList& LISTA)
{
    cout << "Nuevo Producto: " << endl;
    cout << "ID: ";
    cin >> LISTA.allProducts[LISTA.count].ID;
    cout << "Precio: ";
    cin >> LISTA.allProducts[LISTA.count].precio;
    cout << "Cantidad: ";
    cin >> LISTA.allProducts[LISTA.count].cant_units;
    cout << endl;

    LISTA.count++;
}




