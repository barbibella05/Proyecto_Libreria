#include <iostream>
#include <cstdio>
#include "GeneroArchivo.h"
using namespace std;

GeneroArchivo::GeneroArchivo(string nombreArchivo) {
    _nombre = nombreArchivo;
}

bool GeneroArchivo::agregarGenero(Genero reg){
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    bool ok = fwrite(&reg, sizeof(Genero),1, p);

    fclose(p);
    return ok;
}
bool GeneroArchivo::agregarGenero(Genero reg, int pos){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p,sizeof(Genero) * pos, SEEK_SET);

    bool ok = fwrite(&reg, sizeof(Genero), 1, p);

    fclose(p);
    return ok;
}

int GeneroArchivo::buscar(int idGenero){
    int cantidad = contarRegistros();
    Genero aux;

    for(int i = 0; i < cantidad; i++){
        aux = leer(i);
        if(aux.getIdGenero() == idGenero){
            return i;
        }
    }
    return -1;
}


Genero GeneroArchivo::leer(int pos){
    FILE *p;
    Genero reg;

    p = fopen(_nombre.c_str(), "rb");

    if(p== NULL){
        reg.setIdGenero(-1);
        return reg;
    }

    fseek(p, sizeof(Genero) * pos, SEEK_SET);

    if(fread(&reg, sizeof(Genero), 1, p) !=1){
        reg.setIdGenero(-1);
    }

    fclose(p);
    return reg;
}
bool GeneroArchivo::leer(int cantidadRegistros, Genero *vec){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");

    if (p == NULL) {
        return false;
    }

    bool ok = fread(vec, sizeof(Genero), cantidadRegistros, p) == cantidadRegistros;

    fclose(p);
    return ok;
}

bool GeneroArchivo::guardar(Genero reg, int pos){
    return agregarGenero(reg, pos);
}
bool GeneroArchivo::eliminar(int pos){
    Genero aux = leer(pos);

    if (aux.getIdGenero() == -1) {
        return false;
    }

    aux.setEstado(false);

    return agregarGenero(aux, pos);
}

int GeneroArchivo::contarRegistros(){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");

    if (p == NULL) {
        return 0;
    }

    fseek(p, 0, SEEK_END);

    int bytes = ftell(p);

    fclose(p);

    return bytes / sizeof(Genero);
}

