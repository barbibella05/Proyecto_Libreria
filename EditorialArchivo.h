#pragma once
#include <string>
#include "Editorial.h"

class EditorialArchivo{
private:
    std::string _nombre;
public:
    EditorialArchivo(std::string nombre = "editorial.dat");
    bool agregarEditorial(Editorial reg);
    bool agregarEditorial(Editorial reg, int pos);//sobrescribe

    int buscar(int idEditorial);

    Editorial leer(int pos);
    bool leer(int cantidadRegistros, Editorial *vec);

    bool guardar(Editorial reg, int pos);
    bool eliminar(int pos);

    int contarRegistros();
};
