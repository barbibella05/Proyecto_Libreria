#include <iostream>
#include <cstring>
#include "Genero.h"

Genero::Genero() {
    _idGenero = 0;
    strcpy(_nombre, "");
    strcpy(_descripcion, "");
    _estado = true;
}

int Genero::getIdGenero() {
    return _idGenero;
}

const char* Genero::getNombre() {
    return _nombre;
}

const char* Genero::getDescripcion() {
    return _descripcion;
}

bool Genero::getEstado() {
    return _estado;
}

void Genero::setIdGenero(int idGenero) {
    _idGenero = idGenero;
}

void Genero::setNombre(const char* nombre) {
    strcpy(_nombre, nombre);
}

void Genero::setDescripcion(const char* descripcion) {
    strcpy(_descripcion, descripcion);
}

void Genero::setEstado(bool estado) {
    _estado = estado;
}
