#include <iostream>
#include <cstdio>
#include "FacturaArchivo.h"
using namespace std;

FacturaArchivo::FacturaArchivo(string nombre) {
    _nombre = nombre;
}

bool FacturaArchivo::guardar(Factura reg) {
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if (p == NULL) {
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Factura), 1, p);
    fclose(p);
    return ok;
}

bool FacturaArchivo::guardar(Factura reg, int pos) {
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, sizeof(Factura) * pos, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Factura), 1, p);
    fclose(p);
    return ok;
}

Factura FacturaArchivo::leer(int pos) {
    FILE *p;
    Factura reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL) {
        reg.setVentaId(-1);
        return reg;
    }
    fseek(p, sizeof(Factura) * pos, SEEK_SET);
    fread(&reg, sizeof(Factura), 1, p);
    fclose(p);
    return reg;
}

bool FacturaArchivo::leer(int cantidadRegistros, Factura *vec) {
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL) {
        return false;
    }
    fread(vec, sizeof(Factura), cantidadRegistros, p);
    fclose(p);
    return true;
}

int FacturaArchivo::buscar(int ventaId) {
    int cant = contarRegistros();
    Factura aux;

    for (int i = 0; i < cant; i++) {
        aux = leer(i);
        if (aux.getVentaId() == ventaId) {
            return i;
        }
    }
    return -1;
}

bool FacturaArchivo::anular(int pos) {
    Factura aux = leer(pos);
    aux.setEstadoVenta(false);
    return guardar(aux, pos);
}

int FacturaArchivo::contarRegistros() {
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Factura);
}

bool FacturaArchivo::exportarCSV(string nombreCSV) {
    int cantidad = contarRegistros();
    if (cantidad == 0) {
        return false;
    }

    Factura *vec = new Factura[cantidad];
    if (vec == NULL) {
        return false;
    }
    leer(cantidad, vec);

    FILE *p;
    p = fopen(nombreCSV.c_str(), "w");
    if (p == NULL) {
        delete[] vec;
        return false;
    }

    string linea = "VentaId,Fecha,NroCliente,NroEmpleado,EstadoVenta\n";
    fwrite(linea.c_str(), 1, linea.size(), p);

    for (int i = 0; i < cantidad; i++) {
        linea = to_string(vec[i].getVentaId()) + ","
              + vec[i].getFecha().toString() + ","
              + to_string(vec[i].getNroCliente()) + ","
              + to_string(vec[i].getNroEmpleado()) + ","
              + (vec[i].getEstadoVenta() ? "1" : "0") + "\n";
        fwrite(linea.c_str(), 1, linea.size(), p);
    }

    fclose(p);
    delete[] vec;
    return true;
}
