#include <iostream>
#include <cstring>
#include "DetalleVenta.h"
using namespace std;

DetalleVenta::DetalleVenta() {
    _detalleId = 0;
    _ventaId = 0;
    strcpy(_ISBN, "");
    _cantidad = 0;
    _precioUnitario = 0;
    _estado = true;
}

DetalleVenta::DetalleVenta(int detalleId, int ventaId, const char *isbn, int cantidad, float precioUnitario) {
    _detalleId = detalleId;
    _ventaId = ventaId;
    strcpy(_ISBN, isbn);
    _cantidad = cantidad;
    _precioUnitario = precioUnitario;
    _estado = true;
}

int DetalleVenta::getDetalleId() {
    return _detalleId;
}

int DetalleVenta::getVentaId() {
    return _ventaId;
}

const char *DetalleVenta::getISBN() {
    return _ISBN;
}

int DetalleVenta::getCantidad() {
    return _cantidad;
}

float DetalleVenta::getPrecioUnitario() {
    return _precioUnitario;
}

bool DetalleVenta::getEstado() {
    return _estado;
}

void DetalleVenta::setDetalleId(int detalleId) {
    _detalleId = detalleId;
}

void DetalleVenta::setVentaId(int ventaId) {
    _ventaId = ventaId;
}

void DetalleVenta::setISBN(const char *isbn) {
    strcpy(_ISBN, isbn);
}

void DetalleVenta::setCantidad(int cantidad) {
    _cantidad = cantidad;
}

void DetalleVenta::setPrecioUnitario(float precioUnitario) {
    _precioUnitario = precioUnitario;
}

void DetalleVenta::setEstado(bool estado) {
    _estado = estado;
}
