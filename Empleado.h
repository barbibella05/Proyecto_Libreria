#pragma once
#include "Persona.h"
#include "Fecha.h"

class Empleado : public Persona{
private:
      int _nroEmpleado;
      char _direccion[60];
      char _cuil[14];
      Fecha _fechaIngreso;
      Fecha _fechaEgreso;
      int _perfil;

public:
    Empleado();

    int getNroEmpleado();
    std::string getDireccion();
    std::string getCuil();
    Fecha getFechaIngreso();
    Fecha getFechaEgreso();
    int getPerfil();

    void setNroEmpleado(int);
    void setDireccion(std::string);
    void setCuil(std::string);
    Fecha setFechaIngreso(Fecha fechaIngreso);
    Fecha setFechaEgreso(Fecha fechaEgreso);
    void setPerfil(int);
};
