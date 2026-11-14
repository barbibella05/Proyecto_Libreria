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
    const char* getDireccion();
    const char* getCuil();
    Fecha getFechaIngreso();
    Fecha getFechaEgreso();
    int getPerfil();

    void setNroEmpleado(int nroEmpleado);
    void setDireccion(const char* direccion);
    void setCuil(const char* cuil);
    void setFechaIngreso(Fecha fechaIngreso);
    void setFechaEgreso(Fecha fechaEgreso);
    void setPerfil(int perfil);
};
