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

    persona.setNombre(nombre);
    persona.setApellido(apellido);
    persona.setDni(dni);
    persona.setEmail(email);
    persona.setTelefono(telefono);
    persona.setEstado(true);

    return persona;
}
