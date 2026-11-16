#pragma once
#include <string>
#include "Autor.h"

class AutorArchivo{
private:
    std::string _nombre;
public:
    AutorArchivo(std::string nombre = "autor.dat");
    bool agregarAutor(Autor reg);
    bool agregarAutor(Autor reg, int pos);//sobrescribe

    int buscar(int idAutor);

    Autor leer(int pos);
    bool leer(int cantidadRegistros, Autor *vec);

    bool guardar(Autor reg, int pos);
    bool eliminar(int pos);

    int contarRegistros();
};
