#pragma once
#include <string>
#include "DetalleVenta.h"

class DetalleVentaArchivo {
private:
    std::string _nombre;
public:
    DetalleVentaArchivo(std::string nombre = "detalle_venta.dat");
    bool guardar(DetalleVenta reg);
    bool guardar(DetalleVenta reg, int pos);
    DetalleVenta leer(int pos);
    bool leer(int cantidadRegistros, DetalleVenta *vec);
    int buscar(int detalleId);
    bool anular(int pos);
    int contarRegistros();
    bool exportarCSV(std::string nombreCSV);
};
