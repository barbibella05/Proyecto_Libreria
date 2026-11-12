#pragma once
#include "Persona.h"
#include "Fecha.h"

class Cliente: public Persona{
private:
    int _nroCliente;
    Fecha _fechaRegistro;
public:
    Cliente();
    Cliente(int nroCliente, Fecha fechaRegistro);

    int getNroCliente();
    Fecha getFechaRegistro();

    void setNroCliente(int nroCliente);
    void setFechaRegistro(Fecha fechaRegistro);

};
