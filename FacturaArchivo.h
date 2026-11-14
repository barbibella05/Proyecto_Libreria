#pragma once
#include <string>
#include "Factura.h"

class FacturaArchivo {
private:
    std::string _nombre;
public:
    FacturaArchivo(std::string nombre = "factura.dat");
    bool guardar(Factura reg);
    bool guardar(Factura reg, int pos);
    Factura leer(int pos);
    bool leer(int cantidadRegistros, Factura *vec);
    int buscar(int ventaId);
    bool anular(int pos);
    int contarRegistros();
    bool exportarCSV(std::string nombreCSV);
};
