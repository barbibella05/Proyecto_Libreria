#pragma once
#include <string>
#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include "PersonaManager.h"

class EmpleadoManager{
private:
    EmpleadoArchivo _archivo;
    PersonaManager _personaManager;

    Empleado CargarEmpleado();
    int GenerarNroEmpleado();

    bool ExisteNro(int nroEmpleado);
    Fecha PedirFecha();

    void MostrarEncabezado();
    void MostrarEmpleado(Empleado empleado);
    void MostrarEncabezadoActivos();
    void MostrarEncabezadoInactivos();
    std::string MostrarPerfil(int perfil);


public:
    void Menu();
    void NuevoEmpleado();
    void ModificarEmpleado();
    void ListarTodos();
    void BuscarXNnroEmpleado();
    void Eliminar();
};
