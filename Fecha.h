#pragma once
#include <string>

class Fecha {
private:
    int _dia, _mes, _anio;

    void establecerFechaPorDefecto();
    bool esBisiesto();
    void agregarDia();

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    void Cargar();

    // Getters
    int getDia();
    int getMes();
    int getAnio();

    // Setters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    // Otros métodos
    void agregarDias(int cantidadDias);
    std::string toString(std::string formatoFecha = "DD/MM/YYYY");
};
