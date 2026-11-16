#pragma once
#include <cstring>

class Genero{
private:
    int _idGenero;
    char _nombre[30];
    char _descripcion[100];
    bool _estado;

public:
    Genero();

    int getIdGenero();
    const char* getNombre();
    const char* getDescripcion();
    bool getEstado();

    void setIdGenero(int idGenero);
    void setNombre(const char* nombre);
    void setDescripcion(const char* descripcion);
    void setEstado(bool estado);
};
