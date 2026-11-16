#pragma once
#include "Factura.h"
#include "FacturaArchivo.h"
#include "DetalleVentaManager.h"
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"

class FacturaManager {
private:
    FacturaArchivo _archivo;
    DetalleVentaManager _detalleManager;
    ClienteArchivo _archivoClientes;
    EmpleadoArchivo _archivoEmpleados;

    int ProximoId();
    Fecha PedirFecha();
    bool ClienteValido(int nroCliente);
    bool EmpleadoValido(int nroEmpleado);

    void MostrarEncabezado();
    void MostrarFactura(Factura factura);

public:
    void Menu();
    void NuevaVenta();
    void ListarTodas();
    void ListarXventa();
    void Anular();
};
