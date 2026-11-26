#include <iostream>
#include <cstring>
#include "Compra.h"
#include "Fecha.h"
using namespace std;

Compra::Compra(){
    _idCompra = 00;
    _fechaCompra = Fecha();
    _estado = true;
}

int Compra::getIdCompra(){
    return _idCompra;
}
Fecha Compra::getFechaCompra(){
    return _fechaCompra;
}
bool Compra::getEstado(){
    return _estado;
}


void Compra::setIdCompra(int idCompra){
    _idCompra = idCompra;
}
void Compra::setFechaCompra(Fecha fechaCompra){
    _fechaCompra = fechaCompra;
}
void Compra::setEstado(bool estado){
    _estado = estado;
}
