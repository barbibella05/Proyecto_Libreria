#include <iostream>
#include <cstring>
#include "Persona.h"
using namespace std;

Persona::Persona(){
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _dni = 0;
    strcpy(_email, "");
    strcpy(_telefono, "");
    _estado = true;
}

const char* Persona::getNombre(){
    return _nombre;
}

const char* Persona::getApellido(){
    return _apellido;
}

int Persona::getDni(){
    return _dni;
}

const char* Persona::getEmail(){
    return _email;
}

const char* Persona::getTelefono(){
    return _telefono;
}

bool Persona::getEstado(){
    return _estado;
}

void Persona::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
}

void Persona::setApellido(const char* apellido){
    strcpy(_apellido, apellido);
}

void Persona::setDni(int dni){
    _dni = dni;
}

void Persona::setEmail(const char* email){
    strcpy(_email, email);
}

void Persona::setTelefono(const char* telefono){
    strcpy(_telefono, telefono);
}

void Persona::setEstado(bool estado){
    _estado = estado;
}
