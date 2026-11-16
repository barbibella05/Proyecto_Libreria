#pragma once
#include "Genero.h"
#include "GeneroArchivo.h"

class GeneroManager{
private:
    GeneroArchivo _archivo;

    Genero CargarGenero();
    int GenerarIDGenero();

    bool ExisteID(int idGenero);

    void MostrarGenero(Genero genero);
    void MostrarGeneroListado(Genero genero);
    void MostrarEncabezado();
    void MostrarEncabezadoInactivos();

public:
    void Menu();
    void NuevoGenero();
    void ModificarGenero();
    void ListarTodos();
    void ListarXIDGenero();
    void Eliminar();
};
