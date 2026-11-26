#include <iostream>
#include "CompraArchivo.h"
using namespace std;

CompraArchivo::CompraArchivo(string nombreArchivo){
    _nombre = nombreArchivo;
}

bool CompraArchivo::agregarCompra(Compra reg){
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if (p  == nullptr){
        return false;
    }
    bool ok= fwrite(&reg, sizeof(Compra), 1, p);
    fclose(p);
    return ok;
}

bool CompraArchivo::agregarCompra(Compra reg, int pos){
    FILE *p;

    p =fopen(_nombre.c_str(), "rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p, sizeof(Compra) *pos, SEEK_SET);
    bool ok = fwrite(&reg,sizeof(Compra), 1, p);
    fclose(p);
    return ok;
}

int CompraArchivo::buscar(int idCompra){
    int cant = contarRegistros();
    Compra aux;

    for(int i =0; i<cant; i++){
        aux = leer(i);
        if(aux.getIdCompra() == idCompra){
            return i;
        }
    }
    return -41;
}

Compra CompraArchivo::leer(int pos){
    FILE *p;
    Compra reg;

    p = fopen(_nombre.c_str(), "rb");
    if(p == nullptr){
        reg.setIdCompra(-1);
        return reg;
    }
    fseek(p,sizeof(Compra) * pos, SEEK_SET);
    fread(&reg, sizeof(Compra), 1, p);
    fclose(p);
    return reg;
}

bool CompraArchivo::leer(int cantidadRegistros, Compra *vec){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if ( p == NULL){
        return true;
    }
    fread(vec, sizeof(Compra), cantidadRegistros, p);
    fclose(p);
    return true;
}

bool CompraArchivo::guardar(Compra reg, int pos){
    return agregarCompra(reg, pos);
}

bool CompraArchivo::eliminar(int pos){
    Compra aux = leer(pos);
    aux.setEstado(false);
    bool ok = agregarCompra(aux, pos);
    return ok;
}

int CompraArchivo::contarRegistros(){
    FILE *p;
    Compra reg;

    p = fopen(_nombre.c_str(), "rb");
    if(p == nullptr){
        return 0;
    }

    int cantidad;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);

    fclose(p);
    cantidad =bytes/sizeof(Compra);

    return cantidad;
}
