#include <iostream>
#include <string>
#include "PersonaManager.h"

using namespace std;

Persona PersonaManager::CrearPersona() {

    string nombre, apellido, email, telefono;
    int dni;

    cout << "Nombre: ";
    cin >> nombre;

    cout << "Apellido: ";
    cin >> apellido;

    cout << "DNI: ";
    cin >> dni;

    cout << "Email: ";
    cin >> email;

    cout << "Telefono: ";
    cin >> telefono;

    Persona persona;

    persona.setNombre(nombre.c_str());
    persona.setApellido(apellido.c_str());
    persona.setDni(dni);
    persona.setEmail(email.c_str());
    persona.setTelefono(telefono.c_str());
    persona.setEstado(true);

    return persona;
}
