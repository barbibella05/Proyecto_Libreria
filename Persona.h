#pragma once
#include <string>

class Persona {
protected:
    char _nombre[30];
    char _apellido[30];
    char _dni[9];
    char _email[45];
    char _telefono[20];
    bool _estado;

public:
    Persona();

    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getEmail();
    const char* getTelefono();
    bool getEstado();

    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setDni(const char* dni);
    void setEmail(const char* email);
    void setTelefono(const char* telefono);
    void setEstado(bool estado);
};
