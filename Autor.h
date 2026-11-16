#pragma once
#include "Persona.h"
#include "Fecha.h"

class Autor {
private:
    int  _idAutor;
    char _nombreApeAutor[30];
    int  _idGenero;

public:
    Autor();
    Autor(int idAutor, char nombreApeAutor[30], int idGenero);


//SETTERS - MAI
    void setIdAutor(int idAutor);
    void setNombreApeAutor(const char* nombreApeAutor);
    void setIdGenero(int idGenero);


//GETTERS - MAI
    int getIdAutor()const;
    const char* getNombreApeAutor() ;
    int getIdGenero() const;
};
