#pragma once
#include <string>
#include "Empleado.h"

class EmpleadoArchivo{
private:
    std::string _nombre;
public:
    EmpleadoArchivo(std::string nombre = "empleado.dat");
    bool agregarEmpleado(Empleado reg);
    bool agregarEmpleado(Empleado reg, int pos);

    int buscar(int nroEmpleado);

    Empleado leer(int pos);
    bool leer(int cantidadRegistros, Empleado *vec);

    bool guardar(Empleado reg, int pos);
    bool eliminar(int pos);

    int contarRegistros();

};
