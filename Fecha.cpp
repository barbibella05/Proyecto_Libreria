#include <iostream>
#include <string>
#include "Fecha.h"
using namespace std;

// Establece una fecha por defecto
void Fecha::establecerFechaPorDefecto() {
    _dia = 1;
    _mes = 1;
    _anio = 1900;
}

// Comprueba si el año es bisiesto
bool Fecha::esBisiesto() {
    if ((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0) {
        return true;
    }

    return false;
}

// Agrega un día a la fecha
void Fecha::agregarDia() {
    int dias[12] = {31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31};

    if (esBisiesto()) {
        dias[1]++;
    }

    _dia++;

    if (_dia > dias[_mes - 1]) {
        _dia = 1;
        _mes++;

        if (_mes > 12) {
            _mes = 1;
            _anio++;
        }
    }
}

// Constructor por defecto
Fecha::Fecha() {
    establecerFechaPorDefecto();
}

// Constructor con parámetros
Fecha::Fecha(int dia, int mes, int anio) {
    _dia = dia;
    _mes = mes;
    _anio = anio;

    if (_dia <= 0 || _mes <= 0 || _anio <= 0 || _mes > 12) {
        establecerFechaPorDefecto();
    }
    else {
        int dias[12] = {31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31};

        if (esBisiesto()) {
            dias[1]++;
        }

        if (_dia > dias[_mes - 1]) {
            establecerFechaPorDefecto();
        }
    }
}

// Carga una fecha por teclado
void Fecha::Cargar() {
    int dia, mes, anio;

    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

    Fecha aux(dia, mes, anio);

    while (aux.getAnio() == 1900 && (dia != 1 || mes != 1 || anio != 1900)) {
        cout << "Fecha incorrecta. Ingrese nuevamente." << endl;

        cout << "Dia: ";
        cin >> dia;

        cout << "Mes: ";
        cin >> mes;

        cout << "Anio: ";
        cin >> anio;

        aux = Fecha(dia, mes, anio);
    }

    _dia = aux.getDia();
    _mes = aux.getMes();
    _anio = aux.getAnio();
}

// Getters
int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

// Setters
void Fecha::setDia(int dia) {
    Fecha aux(dia, _mes, _anio);

    _dia = aux.getDia();
    _mes = aux.getMes();
    _anio = aux.getAnio();
}

void Fecha::setMes(int mes) {
    Fecha aux(_dia, mes, _anio);

    _dia = aux.getDia();
    _mes = aux.getMes();
    _anio = aux.getAnio();
}

void Fecha::setAnio(int anio) {
    Fecha aux(_dia, _mes, anio);

    _dia = aux.getDia();
    _mes = aux.getMes();
    _anio = aux.getAnio();
}

// Agrega una cantidad de días
void Fecha::agregarDias(int cantidadDias) {
    if (cantidadDias > 0) {
        for (int i = 0; i < cantidadDias; i++) {
            agregarDia();
        }
    }
}

// Devuelve la fecha en el formato solicitado
string Fecha::toString(string formatoFecha) {
    string DD = to_string(_dia);
    string MM = to_string(_mes);
    string YYYY = to_string(_anio);

    if (_dia < 10) {
        DD = "0" + DD;
    }

    if (_mes < 10) {
        MM = "0" + MM;
    }

    if (formatoFecha == "YYYY/MM/DD") {
        return YYYY + "/" + MM + "/" + DD;
    }

    return DD + "/" + MM + "/" + YYYY;
}

