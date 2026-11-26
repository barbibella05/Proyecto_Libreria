#include <iostream>
#include "DetalleCompraStockArchivo.h"
using namespace std;

DetalleCompraStockArchivo::DetalleCompraStockArchivo(string nombreArchivo){
    _nombre = nombreArchivo;
}

bool DetalleCompraStockArchivo::agregarDetalleCompraStock(DetalleCompraStock reg){
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if(p == nullptr){
        return false;
    }
    bool ok =fwrite(&reg, sizeof(DetalleCompraStock), 1 ,p);
    fclose(p);
    return ok;
}

bool DetalleCompraStockArchivo::agregarDetalleCompraStock(DetalleCompraStock reg, int pos){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if(p == nullptr){
        return false;
    }

    fseek(p, sizeof(DetalleCompraStock) *pos, SEEK_SET);
    bool ok = fwrite(&reg,sizeof(DetalleCompraStock), 1, p);
    fclose(p);
    return ok;
}

int DetalleCompraStockArchivo::buscar(int idCompra){
    int cant = contarRegistros();
    DetalleCompraStock aux;

    for(int i=0;i<cant; i++){
        aux = leer(i);
        if(aux.getCompraId() == idCompra){
           return i;
        }
    }
    return -1;
}

DetalleCompraStock DetalleCompraStockArchivo::leer(int pos){
    FILE *p;
    DetalleCompraStock reg;

    p = fopen(_nombre.c_str(), "rb");
    if(p == nullptr){
        reg.setCompraId(-1);
        return reg;
    }

    fseek(p, sizeof(DetalleCompraStock) * pos, SEEK_SET);
    fread(&reg, sizeof(DetalleCompraStock), 1, p);
    fclose(p);
    return reg;
}

bool DetalleCompraStockArchivo::leer(int cantidadRegistros, DetalleCompraStock *vec){
    FILE *p;

    p = fopen(_nombre.c_str(),"rb");
    if(p == nullptr){
        return true;
    }
    fread(vec, sizeof(DetalleCompraStock), cantidadRegistros, p);
    fclose(p);
    return true;
}

bool DetalleCompraStockArchivo::guardar(DetalleCompraStock reg, int pos){
    return agregarDetalleCompraStock(reg, pos);
}

bool DetalleCompraStockArchivo::eliminar(int pos){
    DetalleCompraStock aux =leer(pos);
    aux.setEstado(false);
    bool ok = agregarDetalleCompraStock(aux, pos);
    return ok;
}

int DetalleCompraStockArchivo::contarRegistros(){
    FILE *p;
    DetalleCompraStock reg;

    p = fopen(_nombre.c_str(), "rb");
    if(p == nullptr){
        return 0;
    }

    int cantidad;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);

    fclose(p);
    cantidad =bytes/sizeof(DetalleCompraStock);

    return cantidad;
}
