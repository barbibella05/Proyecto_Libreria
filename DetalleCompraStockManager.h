#pragma once
#include <string>
#include "DetalleCompraStock.h"
#include "DetalleCompraStockArchivo.h"

class DetalleCompraStockManager{
private:
    DetalleCompraStockArchivo _archivo;

    DetalleCompraStock CargarDetalleCompraStock();
    int GenerarIDDetalleCompraStock();

    bool ExisteID(int IDDetalleCompraStock);
    Fecha PedirFecha();

    void MostrarEncabezado();
    void MostrarDetalleCompraStock(DetalleCompraStock detalleCompraStock);
    void MostrarEncabezadoActivos();
    void MostrarEncabezadoInactivos();


public:
    void Menu();
    void NuevoDetalleCompraStock();
    void ModificarDetalleCompraStock();
    void ListarTodos();
    void BuscarXIDDetalleCompraStock();
    void Eliminar();
};
