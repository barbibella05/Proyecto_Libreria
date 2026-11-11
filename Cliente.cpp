#include <iostream>
#include "Cliente.h"
using namespace std;

Cliente::Cliente(){
    _nroCliente = 0;
    _fechaRegistro = Fecha();
}

int Cliente::getNroCliente(){
    return _nroCliente;
}
Fecha Cliente::getFechaRegistro(){
    return _fechaRegistro;
}

void Cliente::setNroCliente(int nroCliente){
    _nroCliente = nroCliente;
}
void Cliente::setFechaRegistro(Fecha fechaRegistro){
    _fechaRegistro = fechaRegistro;
}
