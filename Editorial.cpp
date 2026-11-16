#pragma once
#include <iostream>
#include <string>

Editorial::Editorial(){
    _idEditorial = 0;
    strcpy(_nombreEd,"");
    strcpy(_cuit, "");
    _estado = true;
}

//SETTERS - MAI
void Editorial::setIdEditorial(int idEditorial){
    _idEditorial = idEditorial;
}

void Editorial::setNombreEd(const char* nombreEd){
    strcpy(_nombreEd, nombreEd);
}

void Editorial::setCuit(const char* cuit){
    strcpy(_cuit, cuit);
}

void Editorial::setEstado(bool estado){
    _estado = estado;
}

//GETTERS - MAI
int Editorial::getIdEditorial(){
    return _idEditorial;
}

const char* Editorial::getNombreEd(){
    return _nombreEd;
}

const char* Editorial::getCuit(){
    return _cuit;
}

bool Editorial::getEstado{
    return _estado;
}
