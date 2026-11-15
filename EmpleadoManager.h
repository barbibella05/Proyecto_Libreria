#pragma once
#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include "PersonaManager.h"

class EmpleadoManager{
private:
    EmpleadoArchivo _archivo;
    PersonaManager _personaManager;

    Empleado CargarEmpleado(int nroEmpleado);
    bool ExisteNro(int nroEmpleado);
    Fecha PedirFecha();

    void MostrarEncabezado();
    void MostrarEmpleado(Empleado empleado);

public:
    void Menu();
    void NuevoEmpleado();
    void ModificarEmpleado();
    void ListarTodos();
    void BuscarPorNroEmpleado();
    void Eliminar();
};
