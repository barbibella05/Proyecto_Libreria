#pragma once
#include "Empleado.h"

class EmpleadoArchivo{
private:
    std::string _nombre;
public:
    EmpleadoArchivo(std::string nombre = "empleado.dat");
    bool agregarEmpleado(Empleado reg); // Añade al final
    bool agregarEmpleado(Empleado reg, int pos); // Sobreescribe uno existente
    int buscar(int nroCliente);
    void modificarEmpleado(int nroEmpleado);
    void listarEmpleado();
    Empleado leer(int pos);
    bool leer(int cantidadRegistros, Empleado *vec);
    bool eliminar(int pos);
    int contarRegistros();

};

/**
    void EmpleadoManager();
    void AgregarEmpleado();
    void ListarEmpleados();
    void BuscarEmpleado(int nroEmpleado);
    void ModificarEmpleado(int nroEmpleado);
    void DarDeBajaEmpleado(int nroEmpleado);


*/
