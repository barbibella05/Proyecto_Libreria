#include <iostream>
#include "EmpleadoArchivo.h"
using namespace std;

/**

EmpleadoArchivo::EmpleadoArchivo(string nombreArchivo){
    _nombre = nombreArchivo;
}

bool EmpleadoArchivo::agregarEmpleado(Empleado reg){
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if(p == NULL){
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

bool EmpleadoArchivo::agregarEmpleado(Empleado reg, int pos){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Empleado) * pos, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

int EmpleadoArchivo::buscar(int nroEmpleado){
    int cant = contarRegistros();
    Empleado aux;

    for(int i=0; i<cant; i++){
        aux = leer(i);
        if (aux.getNroEmpleado() == nroEmpleado){
            return i;
        }
    }
    return -1;
}

void EmpleadoArchivo::modificarEmpleado(int nroEmpleado){


}
void EmpleadoArchivo::listarEmpleado(){

}

Empleado EmpleadoArchivo::leer(int pos){
    FILE *p;
    Empleado reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        reg.setNroEmpleado(-1);
        return reg;
    }
    fseek(p, sizeof(Empleado) * pos, SEEK_SET);
    fread(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return reg;
}

bool EmpleadoArchivo::leer(int cantidadRegistros, Empleado *vec){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        return true;
    }

    fread(vec, sizeof(Empleado), cantidadRegistros, p);
    fclose(p);
    return true;
}

bool EmpleadoArchivo::eliminar(int pos){
    Empleado aux = leer(pos);
    aux.setEstado(false);
    bool ok = agregarEmpleado(aux, pos);
    return ok;
}

int EmpleadoArchivo::contarRegistros(){
    FILE *p;
    Empleado reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        return 0;
    }
    int cantidad;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    cantidad = bytes / sizeof(Empleado);
    return cantidad;
}
*/
