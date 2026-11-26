#pragma once
#include <string>
#include "DetalleCompraStock.h"

class DetalleCompraStockArchivo{
private:
    std::string _nombre;
public:
    DetalleCompraStockArchivo(std::string nombre = "detalleCompraStock.dat");
    bool agregarDetalleCompraStock(DetalleCompraStock reg);
    bool agregarDetalleCompraStock(DetalleCompraStock reg, int pos);

    int buscar(int idcompra);

    DetalleCompraStock leer(int pos);
    bool leer(int cantidadRegistros, DetalleCompraStock *vec);

    bool guardar(DetalleCompraStock reg, int pos);
    bool eliminar(int pos);

    int contarRegistros();
};
