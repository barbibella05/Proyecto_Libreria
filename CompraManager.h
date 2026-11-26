#pragma once
#include <string>
#include "Compra.h"
#include "CompraArchivo.h"

class Compra{
private:
    CompraArchivo _archivo;

    Compra Compra();
    int GenerarIDCompra();

    bool ExisteID(int IDCompra);
    Fecha PedirFecha();

    void MostrarEncabezado();
    void MostrarCompra(Compra compra);
    void MostrarEncabezadoActivos();
    void MostrarEncabezadoInactivos();


public:
    void Menu();
    void NuevoCompra();
    void ModificarCompra();
    void ListarTodos();
    void BuscarXIDCompra();
    void Eliminar();
};
