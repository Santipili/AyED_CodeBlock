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