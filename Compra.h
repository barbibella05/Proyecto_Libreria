#pragma once
#include "Fecha.h"

class Compra{
private:
    int _idcompra;
    char _ISBN[14];
    int _cantComprar;
    Fecha _fechaCompra;
    bool _estado;
public:
    Compra();

    int getIdcompra();
    const char* getISBN();
    int getCantComprar();
    Fecha getFechaCompra());
    bool getEstado();


    void setIdcompra(int idcompra);
    void setISBN(const char* ISBN);
    void setCantComprar(int cantComprar);
    void setFechaCompra(Fecha fechaCompra);
    void setEstado(bool estado();
};

