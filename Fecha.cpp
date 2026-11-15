#include <iostream>
#include <string>
#include <limits>
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

// Comprueba si una fecha es valida
bool Fecha::esFechaValida(int dia, int mes, int anio) {

    if (anio < 1900 || anio > 2100 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    int dias[12] = {31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31};

    bool bisiesto = ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);

    if (bisiesto) {
        dias[1] = 29;
    }

    if (dia > dias[mes - 1]) {
        return false;
    }

    return true;
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
    if (esFechaValida(dia, mes, anio)) {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
    else {
        establecerFechaPorDefecto();
    }
}

void Fecha::Cargar() {

    int dia, mes, anio;
    bool fechaValida = false;

    while (!fechaValida) {

        cout << "Dia: ";
        cout << endl;
        cout << "Mes: ";
        cout << endl;
        cout << "Anio: ";

        if (!(cin >> dia >> mes >> anio)) {

            cout << "Debe ingresar solamente numeros." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        else if (!esFechaValida(dia, mes, anio)) {

            cout << "Fecha incorrecta. Ingrese una fecha valida." << endl;

        }
        else {
            fechaValida = true;
        }
    }

    _dia = dia;
    _mes = mes;
    _anio = anio;
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

void Fecha::setDia(int dia) {
    if (esFechaValida(dia, _mes, _anio)) {
        _dia = dia;
    }
}

void Fecha::setMes(int mes) {
    if (esFechaValida(_dia, mes, _anio)) {
        _mes = mes;
    }
}

void Fecha::setAnio(int anio) {
    if (esFechaValida(_dia, _mes, anio)) {
        _anio = anio;
    }
}

// Agrega una cantidad de dias
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

    if (_anio < 1000) {
        YYYY = "0" + YYYY;
    }

    if (formatoFecha == "YYYY/MM/DD") {
        return YYYY + "/" + MM + "/" + DD;
    }

    return DD + "/" + MM + "/" + YYYY;
}
