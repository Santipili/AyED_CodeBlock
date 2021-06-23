#include <iostream>
using namespace std;
#include <string>

int main(){
    string name, fullname;

    cout << "nombre: ";
    getline(cin, name);

    cout << "Nombre: ";
    getline(cin, fullname);

    cout << name << endl;
    cout << fullname;


    return 0;
}
