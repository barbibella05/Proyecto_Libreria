#include <iostream>
#include "Persona.h"
using namespace std;

Persona::Persona() {
    _dni = 0;
    _estado = true;
}

string Persona::getNombre() {
    return _nombre;
}

string Persona::getApellido() {
    return _apellido;
}

int Persona::getDni() {
    return _dni;
}

string Persona::getEmail() {
    return _email;
}

string Persona::getTelefono() {
    return _telefono;
}

bool Persona::getEstado() {
    return _estado;
}

void Persona::setNombre(string nombre) {
    _nombre = nombre;
}

void Persona::setApellido(string apellido) {
    _apellido = apellido;
}

void Persona::setDni(int dni) {
    _dni = dni;
}

void Persona::setEmail(string email) {
    _email = email;
}

void Persona::setTelefono(string telefono) {
    _telefono = telefono;
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}
