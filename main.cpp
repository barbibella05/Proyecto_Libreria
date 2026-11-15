#include <iostream>
#include "ClienteManager.h"
#include "Empleado.h"

using namespace std;

int main()
{
    /// AVISO - AUN TIENE FALLAS EL CARGAR CLIENTE
    ClienteManager clienteManager;
    Empleado empleado;

    clienteManager.Menu();
    empleado.getApellido();

    return 0;
}
