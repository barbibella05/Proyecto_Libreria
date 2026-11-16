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

//GETTERS - MAI
