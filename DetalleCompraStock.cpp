
#include <iostream>
#include <cstring>
#include "DetalleCompraStock.h"

using namespace std;

DetalleCompraStock::DetalleCompraStock(){
    _idDetalle = 0;
    _compraId = 0;
    strcpy(_ISBN, "00000");
    _cantidad = 0;
    _precioUnitario = 0.0f;
}

int DetalleCompraStock::getIdDetalle(){
    return _idDetalle;
}

int DetalleCompraStock::getCompraId(){
    return _compraId;
}

const char* DetalleCompraStock::getISBN(){
    return _ISBN;
}

int DetalleCompraStock::getCantidad(){
    return _cantidad;
}

float DetalleCompraStock::getPrecioUnitario(){
    return _precioUnitario;
}
bool DetalleCompraStock::getEstado(){
    return _estado;
}

void DetalleCompraStock::setIdDetalle(int idDetalle){
    _idDetalle = idDetalle;
}

void DetalleCompraStock::setCompraId(int compraId){
    _compraId = compraId;
}

void DetalleCompraStock::setISBN(const char* ISBN){
    strcpy(_ISBN, ISBN);
}

void DetalleCompraStock::setCantidad(int cantidad){
    _cantidad = cantidad;
}
void DetalleCompraStock::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}
void DetalleCompraStock::setEstado(bool estado){
    _estado = estado;
}
