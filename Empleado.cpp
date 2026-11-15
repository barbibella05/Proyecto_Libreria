#include <iostream>
#include <cstring>
#include "Empleado.h"
#include "Fecha.h"
using namespace std;


Empleado::Empleado(){
      _nroEmpleado= 0;
      strcpy(_direccion, "");
      _fechaIngreso = Fecha();
      _fechaEgreso = Fecha();
      _perfil = 0;
}

int Empleado::getNroEmpleado(){
    return _nroEmpleado;
}
const char* Empleado::getDireccion(){
    return _direccion;
}
Fecha Empleado::getFechaIngreso(){
    return _fechaIngreso;
}
Fecha Empleado::getFechaEgreso(){
    return _fechaEgreso;
}
int Empleado::getPerfil(){
    return _perfil;
}

void Empleado::setNroEmpleado(int nroEmpleado){
    _nroEmpleado = nroEmpleado;
}
void Empleado::setDireccion(const char* direccion){
    strcpy(_direccion, direccion);
}
void Empleado::setFechaIngreso(Fecha fechaIngreso){
    _fechaIngreso = fechaIngreso;
}
void Empleado::setFechaEgreso(Fecha fechaEgreso){
    _fechaEgreso = fechaEgreso;
}
void Empleado::setPerfil(int perfil){
    _perfil = perfil;
}

