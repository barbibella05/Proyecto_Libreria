#include <iostream>
#include <string>
#include <cctype>
#include "PersonaManager.h"

using namespace std;

Persona PersonaManager::CrearPersona() {

    string nombre, apellido, dni, email, telefono;
    bool dniValido, telefonoValido;

    cout << "Nombre: ";
    cin >> nombre;

    cout << "Apellido: ";
    cin >> apellido;

    do{
        cout << "DNI: ";
        cin >> dni;

        dniValido = true;

        if(dni.length() != 7 && dni.length() != 8){
            dniValido = false;
        }

        for(int i = 0; i < dni.length(); i++){
            if (!isdigit((unsigned char)dni[i])){
                dniValido = false;
            }
        }

        if (!dniValido){
            cout << "DNI incorrecto. Debe tener 7 u 8 digitos." << endl;
        }

    } while (!dniValido);

    do {
    cout << "Email: ";
    cin >> email;

    if (email.find('@') == string::npos) {
        cout << "Email incorrecto. Debe contener un @.";
    }

} while (email.find('@') == string::npos);

    do {
        cout << "Telefono: ";
        cin >> telefono;

        telefonoValido = true;

        if(telefono.length() < 8 || telefono.length() > 12){
            telefonoValido = false;
        }

        for(int i = 0; i < telefono.length(); i++){
            if(!isdigit((unsigned char)telefono[i])){
                telefonoValido = false;
            }
        }

        if(!telefonoValido){
            cout << "Telefono incorrecto. Debe tener entre 8 y 12 numeros." << endl;
        }

    }while(!telefonoValido);

    Persona persona;

    persona.setNombre(nombre.c_str());
    persona.setApellido(apellido.c_str());
    persona.setDni(dni.c_str());
    persona.setEmail(email.c_str());
    persona.setTelefono(telefono.c_str());
    persona.setEstado(true);

    return persona;
}
