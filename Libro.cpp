#pragma once
#include <iostream>
#include <string>
#include "Libro.h"

Libro::Libro(){
    strcpy(_ISBN,"");
    strcpy(_titulo,"");
    _idAutor =0;
    strcpy(_editorial,"");
    _idEditorial = 0;
    _fechaPublicacion = Fecha();
    _idGenero = 0;
    _stock = 0;
    _precio = 0;
    _estado = true;

}

//SETTERS - MAI
void Libro::setISBN(const char* ISBN){
    strcpy(_ISBN, ISBN);
};

void Libro::setTitulo(const char* titulo){
    strcpy(_titulo,titulo);
};

void Libro::setIdAutor(int idAutor){
    _idAutor = idAutor;
};

void Libro::setEditorial(const char* editorial){
    strcpy(_editorial, editorial);
};

void Libro::setIdEditorial(int idEditorial){
    _idEditorial = idEditorial;
};
void Libro::setFechaPublicacion(Fecha fechaPublicacion){
    _fechaPublicacion = fechaPublicacion;
};
void Libro::setIdGenero(int idGenero){
    _idGenero = idGenero;
};
void Libro::setStock(int stock){
    _stock = stock;
};
void Libro::setPrecio(float precio){
    _precio = precio;
};
void Libro::setEstado(bool estado){
    _estado = estado;
};

//GETTERS - MAI
