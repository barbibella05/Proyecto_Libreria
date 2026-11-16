#pragma once
#include "Genero.h"

class GeneroArchivo{
private:
    std::string _nombre;
public:
    GeneroArchivo(std::string nombre = "genero.dat");
    bool agregarGenero(Genero reg);
    bool agregarGenero(Genero reg, int pos);

    int buscar(int nroGenero);

    Genero leer(int pos);
    bool leer(int cantidadRegistros, Genero *vec);

    bool guardar(Genero reg, int pos);
    bool eliminar(int pos);

    int contarRegistros()
};
