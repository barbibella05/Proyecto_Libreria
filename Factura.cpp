#include <iostream>
#include "Factura.h"
using namespace std;

Factura::Factura() {
    _ventaId = 0;
    _fecha = Fecha();
    _nroCliente = 0;
    _nroEmpleado = 0;
    _estadoVenta = true;
}

Factura::Factura(int ventaId, Fecha fecha, int nroCliente, int nroEmpleado) {
    _ventaId = ventaId;
    _fecha = fecha;
    _nroCliente = nroCliente;
    _nroEmpleado = nroEmpleado;
    _estadoVenta = true;
}

int Factura::getVentaId() {
    return _ventaId;
}

Fecha Factura::getFecha() {
    return _fecha;
}

int Factura::getNroCliente() {
    return _nroCliente;
}

int Factura::getNroEmpleado() {
    return _nroEmpleado;
}

bool Factura::getEstadoVenta() {
    return _estadoVenta;
}

void Factura::setVentaId(int ventaId) {
    _ventaId = ventaId;
}

void Factura::setFecha(Fecha fecha) {
    _fecha = fecha;
}

void Factura::setNroCliente(int nroCliente) {
    _nroCliente = nroCliente;
}

void Factura::setNroEmpleado(int nroEmpleado) {
    _nroEmpleado = nroEmpleado;
}

void Factura::setEstadoVenta(bool estadoVenta) {
    _estadoVenta = estadoVenta;
}
