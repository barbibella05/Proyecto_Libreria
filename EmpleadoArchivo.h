#pragma once

class EmpleadoArchivo{
private:
    char nombreArchivo[30];
public:
    void EmpleadoManager();
    void AgregarEmpleado();
    void ListarEmpleados();
    void BuscarEmpleado(int nroEmpleado);
    void ModificarEmpleado(int nroEmpleado);
    void DarDeBajaEmpleado(int nroEmpleado);
};

