#pragma once
#include "DetalleVenta.h"
#include "DetalleVentaArchivo.h"

class DetalleVentaManager {
private:
    DetalleVentaArchivo _archivo;

    void MostrarEncabezado();
    void MostrarDetalle(DetalleVenta detalle);

public:
    void Menu();
    int ProximoId();
    DetalleVenta CargarDetalle(int detalleId, int ventaId);
    bool Agregar(DetalleVenta detalle);
    void ListarTodos();
    void ListarXventa(int ventaId);
    float ImporteDeVenta(int ventaId);
};
