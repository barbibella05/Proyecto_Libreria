#pragma once
#include "Fecha.h"

class Factura {
private:
    int _ventaId;
    Fecha _fecha;
    int _nroCliente;
    int _nroEmpleado;
    bool _estadoVenta;

public:
    Factura();
    Factura(int ventaId, Fecha fecha, int nroCliente, int nroEmpleado);

    int getVentaId();
    Fecha getFecha();
    int getNroCliente();
    int getNroEmpleado();
    bool getEstadoVenta();

    void setVentaId(int ventaId);
    void setFecha(Fecha fecha);
    void setNroCliente(int nroCliente);
    void setNroEmpleado(int nroEmpleado);
    void setEstadoVenta(bool estadoVenta);
};
