#pragma once
#include <string>

class Persona {
private:
    std::string _nombre;
    std::string _apellido;
    int _dni;
    std::string _email;
    std::string _telefono;
    bool _estado;

public:
    Persona();

    std::string getNombre();
    std::string getApellido();
    int getDni();
    std::string getEmail();
    std::string getTelefono();
    bool getEstadoPersona();

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setDni(int dni);
    void setEmail(std::string email);
    void setTelefono(std::string telefono);
    void setEstadoPersona(bool estado);
};
