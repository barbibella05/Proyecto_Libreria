#include <iostream>
#include <string>
#include <cstdio>
#include "ClienteArchivo.h"
using namespace std;

ClienteArchivo::ClienteArchivo(string nombreArchivo){
    _nombre = nombreArchivo;
}

bool ClienteArchivo::agregarCliente(Cliente reg){
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if(p == NULL){
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool ClienteArchivo::agregarCliente(Cliente reg, int pos){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Cliente) * pos, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

int ClienteArchivo::buscar(int nroCliente){
    int cant = contarRegistros();
    Cliente aux;

    for(int i=0; i<cant; i++){
        aux = leer(i);
        if (aux.getNroCliente() == nroCliente){
            return i;
        }
    }
    return -1;
}

void ClienteArchivo::modificarCliente(int nroCliente){

}
void ClienteArchivo::listarCliente(){

}

Cliente ClienteArchivo::leer(int pos){
    FILE *p;
    Cliente reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        reg.setNroCliente(-1);
        return reg;
    }
    fseek(p, sizeof(Cliente) * pos, SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}

bool ClienteArchivo::leer(int cantidadRegistros, Cliente *vec){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        return true;
    }

    fread(vec, sizeof(Cliente), cantidadRegistros, p);
    fclose(p);
    return true;
}

bool ClienteArchivo::eliminar(int pos){
    Cliente aux = leer(pos);
    aux.setEstadoPersona(false);
    bool ok = agregarCliente(aux, pos);
    return ok;
}

int ClienteArchivo::contarRegistros(){
    FILE *p;
    Cliente reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        return 0;
    }
    int cantidad;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    cantidad = bytes / sizeof(Cliente);
    return cantidad;
}

/**

bool MovimientoArchivo::guardar(Movimiento reg){
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if (p == NULL){
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return ok;
}

bool MovimientoArchivo::guardar(Movimiento reg, int pos){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, sizeof(Movimiento) * pos, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return ok;
}

bool MovimientoArchivo::eliminar(int pos){
    Movimiento aux = leer(pos);
    aux.setActivo(false);
    bool ok = guardar(aux, pos);
    return ok;
}

Movimiento MovimientoArchivo::leer(int pos){
    FILE *p;
    Movimiento reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        reg.setIdMovimiento(-1);
        return reg;
    }
    fseek(p, sizeof(Movimiento) * pos, SEEK_SET);
    fread(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return reg;
}

bool MovimientoArchivo::leer(int cantidadRegistros, Movimiento *vec){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        return true;
    }

    fread(vec, sizeof(Movimiento), cantidadRegistros, p);
    fclose(p);
    return true;
}

int MovimientoArchivo::buscar(int idMovimiento){
    int cant = contarRegistros();
    Movimiento aux;

    for(int i=0; i<cant; i++){
        aux = leer(i);
        if (aux.getIdMovimiento() == idMovimiento){
            return i;
        }
    }
    return -1;
}


int MovimientoArchivo::contarRegistros(){
    FILE *p;
    Movimiento reg;

    p = fopen(_nombre.c_str(), "rb");

    if (p == NULL){
        return 0;
    }

    int cantidad;
    fseek(p, 0, SEEK_END); // Se desplaza 0 bytes desde el final
    int bytes = ftell(p); // Devuelve la cantidad de bytes desplazados
    fclose(p);
    cantidad = bytes / sizeof(Movimiento);
    return cantidad;
}

*/
