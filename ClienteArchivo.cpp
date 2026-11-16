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
    if (fread(&reg, sizeof(Cliente), 1, p) != 1){
        reg.setNroCliente(-1);
    }
    fclose(p);
    return reg;
}

bool ClienteArchivo::leer(int cantidadRegistros, Cliente *vec){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        return true;
    }

     bool ok = fread(vec, sizeof(Cliente), cantidadRegistros, p) == cantidadRegistros;

    fclose(p);
    return true;
}

bool ClienteArchivo::guardar(Cliente cliente, int pos){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if (p == NULL){
        return false;
    }

    fseek(p, sizeof(Cliente) * pos, SEEK_SET);

    bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);

    fclose(p);
    return ok;
}

bool ClienteArchivo::eliminar(int pos){
    Cliente aux = leer(pos);
    aux.setEstado(false);
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


