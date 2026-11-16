#include <iostream>
#include <cstdio>
#include "DetalleVentaArchivo.h"
using namespace std;

DetalleVentaArchivo::DetalleVentaArchivo(string nombre) {
    _nombre = nombre;
}

bool DetalleVentaArchivo::guardar(DetalleVenta reg) {
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if (p == NULL) {
        return false;
    }
    bool ok = fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

bool DetalleVentaArchivo::guardar(DetalleVenta reg, int pos) {
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, sizeof(DetalleVenta) * pos, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

DetalleVenta DetalleVentaArchivo::leer(int pos) {
    FILE *p;
    DetalleVenta reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL) {
        reg.setDetalleId(-1);
        return reg;
    }
    fseek(p, sizeof(DetalleVenta) * pos, SEEK_SET);
    fread(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return reg;
}

bool DetalleVentaArchivo::leer(int cantidadRegistros, DetalleVenta *vec) {
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL) {
        return false;
    }
    fread(vec, sizeof(DetalleVenta), cantidadRegistros, p);
    fclose(p);
    return true;
}

int DetalleVentaArchivo::buscar(int detalleId) {
    int cant = contarRegistros();
    DetalleVenta aux;

    for (int i = 0; i < cant; i++) {
        aux = leer(i);
        if (aux.getDetalleId() == detalleId) {
            return i;
        }
    }
    return -1;
}

bool DetalleVentaArchivo::anular(int pos) {
    DetalleVenta aux = leer(pos);
    aux.setEstado(false);
    return guardar(aux, pos);
}

int DetalleVentaArchivo::contarRegistros() {
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(DetalleVenta);
}

static string FormatoImporte(float importe) {
    int pesos = (int)importe;
    int centavos = (int)((importe - pesos) * 100 + 0.5);
    string texto = to_string(pesos) + ".";
    if (centavos < 10) {
        texto += "0";
    }
    return texto + to_string(centavos);
}

bool DetalleVentaArchivo::exportarCSV(string nombreCSV) {
    int cantidad = contarRegistros();
    if (cantidad == 0) {
        return false;
    }

    DetalleVenta *vec = new DetalleVenta[cantidad];
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

    string linea = "DetalleId,VentaId,ISBN,Cantidad,PrecioUnitario,Estado\n";
    fwrite(linea.c_str(), 1, linea.size(), p);

    for (int i = 0; i < cantidad; i++) {
        linea = to_string(vec[i].getDetalleId()) + ","
              + to_string(vec[i].getVentaId()) + ","
              + vec[i].getISBN() + ","
              + to_string(vec[i].getCantidad()) + ","
              + FormatoImporte(vec[i].getPrecioUnitario()) + ","
              + (vec[i].getEstado() ? "1" : "0") + "\n";
        fwrite(linea.c_str(), 1, linea.size(), p);
    }

    fclose(p);
    delete[] vec;
    return true;
}
