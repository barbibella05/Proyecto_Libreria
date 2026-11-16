#include <iostream>
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "GeneroManager.h"

using namespace std;

int main()
{
    ClienteManager clienteManager;
    EmpleadoManager empleadoManager;
    GeneroManager generoManager;

    int opcion;

    do {
        system("cls");

        cout << "============================" << endl;
        cout << "       MENU PRINCIPAL       " << endl;
        cout << "============================" << endl;
        cout << "1. Gestionar clientes" << endl;
        cout << "2. Gestionar empleados" << endl;
        cout << "3. Gestionar genero" << endl;
        cout << "0. Salir" << endl;
        cout << "============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion) {
        case 1:
            clienteManager.Menu();
            break;

        case 2:
            empleadoManager.Menu();
            break;
        case 3:
            generoManager.Menu();
            break;

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion incorrecta." << endl;
            system("pause");
            break;
        }

    } while (opcion != 0);

    return 0;
}
