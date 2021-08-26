#include <iostream>
#include <iomanip>
using namespace std;

/*
typedef enum {Simple, Medio, Calidad, Premium} tProduct;
typedef enum {Normal, Express, FastDelivery} tShipping;
*/

int chooseProduct();
int chooseShipping();
string showProduct( int product );
string showShipping( int shipping );


int main()
{
    int product;
    int shipping;

    product = chooseProduct();

    shipping = chooseShipping();

    cout << endl << setw(17) << "Producto: " << showProduct( product ) << endl;
    cout << "Metodo de Envio: " << showShipping( shipping );

    return 0;
}

int chooseProduct()
{
    int option ;

    do
    {    
    cout << "Elija un producto" << endl;
    cout << "1.- Simple" << endl;
    cout << "2.- Medio" << endl;
    cout << "3.- Calidad" << endl;
    cout << "4.- Premium" << endl;

    cin >> option;
    }
    while (option < 1 || option >4);

    return option;    
} 

int chooseShipping()
{
    int option ;

    do
    {    
    cout << "Elija metodo de envio" << endl;
    cout << "1.- Normal" << endl;
    cout << "2.- Express" << endl;
    cout << "3.- FastDelivery" << endl;

    cin >> option;
    }
    while (option < 1 || option >3);

    return option;    
} 

string showProduct( int product )
{
    string salidaEnum;

    switch (product)
    {
        case 1: 
        {
            salidaEnum = "Simple";
        }break;

        case 2:
        {
            salidaEnum = "Medio";
        }break;

        case 3:
        {
            salidaEnum = "Calidad";
        }break;

        case 4:
        {
            salidaEnum = "Premium";
        }
    }

    return salidaEnum;
}

string showShipping( int shipping )
{
    string salidaEnum;

    switch (shipping)
    {
        case 1: 
        {
            salidaEnum = "Normal";
        }break;

        case 2:
        {
            salidaEnum = "Express";
        }break;

        case 3:
        {
            salidaEnum = "FastDelivery";
        }

    }

    return salidaEnum;
}
