#pragma once
#include "Genero.h"
#include "GeneroArchivo.h"

class GeneroManager{
private:
    GeneroArchivo _archivo;

    Genero CargarGenero();
    int GenerarIDGenero();

    bool ExisteID(int idGenero);

public:
    void Menu();
    void NuevoGenero();
    void ModificarGenero();
    void ListarTodos();
    void BuscarXIDGenero();
    void Eliminar();
};
