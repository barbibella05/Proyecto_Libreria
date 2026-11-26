#pragma once
#include "Fecha.h"

class Compra{
private:
    int _idCompra;
    Fecha _fechaCompra;
    bool _estado;

public:
    Compra();

    int getIdCompra();
    Fecha getFechaCompra();
    bool getEstado();

    void setIdCompra(int idCompra);
    void setFechaCompra(Fecha fechaCompra);
    void setEstado(bool estado);
};

