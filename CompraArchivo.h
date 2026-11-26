#pragma once
#include <string>
#include "Compra.h"

class CompraArchivo{
private:
    std::string _nombre;
public:
    CompraArchivo(std::string nombre = "compra.dat");
    bool agregarCompra(Compra reg);
    bool agregarCompra(Compra reg, int pos);

    int buscar(int _idCompra);

    Compra leer(int pos);
    bool leer(int cantidadRegistros, Compra *vec);

    bool guardar(Compra reg, int pos);
    bool eliminar(int pos);

    int contarRegistros();
};
