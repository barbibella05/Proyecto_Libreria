#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include "GeneroManager.h"
using namespace std;

void GeneroManager::Menu(){
    int opcion;

    do{
        system("cls");
        cout << "============================" << endl;
        cout << "      MENU DE GENERO      " << endl;
        cout << "============================" << endl;
        cout << "1. Nuevo genero" << endl;
        cout << "2. Modificar genero" << endl;
        cout << "3. Listar generos" << endl;
        cout << "4. Eliminar genero" << endl;
        cout << "0. Volver" << endl;
        cout << "============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
        case 1:NuevoGenero();
            system("pause");
            break;

        case 2:ModificarGenero();
            system("pause");
            break;

        case 3:ListarTodos();
            system("pause");
            break;

        case 4:Eliminar();
            system("pause");
            break;

        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;

        default:
            cout << "Opcion incorrecta." << endl;
            system("pause");
            break;
        }

    } while(opcion != 0);
}

void GeneroManager::NuevoGenero(){
   Genero genero = CargarGenero();

    if (_archivo.agregarGenero(genero)) {
        cout << "Numero de genero asignado: "
             << genero.getIdGenero() << endl;
        cout << "Genero guardado correctamente." << endl;
    }
    else {
        cout << "No se pudo guardar el genero." << endl;
    }
}

void GeneroManager::ModificarGenero(){
    int idGenero;
    string nombreNuevo;

    cout << "ID de genero del registro a editar: ";
    cin >> idGenero;

    int pos = _archivo.buscar(idGenero);

    if (pos < 0) {
        cout << "El registro no existe." << endl;
        return;
    }

    Genero reg = _archivo.leer(pos);

    if (!reg.getEstado()) {
        cout << "No se puede modificar un Genero inactivo." << endl;
        return;
    }

    cout << "\n========== DATOS DEL GENERO ==========" << endl;

    MostrarGenero(reg);

    cout << "\nIngrese el nuevo nombre: ";
    cin >> nombreNuevo;

    reg.setNombre(nombreNuevo.c_str());

    bool ok = _archivo.guardar(reg, pos);

    if (ok) {
        cout << "Genero modificado correctamente." << endl;
    }
    else {
        cout << "No se pudo modificar el genero." << endl;
    }
}

void GeneroManager::ListarTodos(){
   int cantidad = _archivo.contarRegistros();

    if (cantidad == 0) {
        cout << "No hay generos cargados." << endl;
        return;
    }

    Genero *vec = new Genero[cantidad];

    _archivo.leer(cantidad, vec);

    int activos = 0;
    int inactivos = 0;

    cout << "\n========== GENEROS ACTIVOS ==========" << endl;

    MostrarEncabezado();

    for (int i = 0; i < cantidad; i++) {

        if (vec[i].getEstado()) {
            MostrarGeneroListado(vec[i]);
            activos++;
        }
    }

    cout << endl;
    cout << "Cantidad de generos activos: " << activos << endl;


    cout << "\n========== GENEROS INACTIVOS ==========" << endl;

    MostrarEncabezadoInactivos();

    for (int i = 0; i < cantidad; i++) {

        if (!vec[i].getEstado()) {
            MostrarGeneroListado(vec[i]);
            inactivos++;
        }
    }

    cout << endl;
    cout << "Cantidad de generos inactivos: " << inactivos << endl;

    delete[] vec;
}

void GeneroManager::ListarXIDGenero(){
    int idGenero;

    cout << "Ingresar numero de generos: ";
    cin >> idGenero;

    int pos = _archivo.buscar(idGenero);

    if (pos >= 0){
        Genero genero = _archivo.leer(pos);
        MostrarGenero(genero);
    }
    else{
        cout << "No existe un genero con ese numero: " << idGenero << endl;
    }

}

void GeneroManager::Eliminar(){
    int idGenero;
    cout << "Numero de genero del registro a eliminar: ";
    cin >> idGenero;

    int pos = _archivo.buscar(idGenero);

    if (pos < 0){
        cout << "El registro no existe" << endl;
        return;
    }

    bool ok = _archivo.eliminar(pos);

    if (ok){
        cout << "Registro eliminado correctamente" << endl;
    }
    else{
        cout << "No se pudo eliminar el registro" << endl;
    }

    return;
}

Genero GeneroManager::CargarGenero() {
    Genero genero;
    int idGenero = GenerarIDGenero();
    string nombre, descripcion;

    cout << "Ingrese el nombre del genero: ";
    cin >> nombre;

    cout << "Ingrese la descripcion: ";
    cin.ignore();
    getline(cin, descripcion);

    genero.setIdGenero(idGenero);
    genero.setNombre(nombre.c_str());
    genero.setDescripcion(descripcion.c_str());
    genero.setEstado(true);


    return genero;
}

void GeneroManager::MostrarGenero(Genero genero) {
    cout << "----------------------------------------" << endl;
    cout << "ID del genero: " << genero.getIdGenero() << endl;
    cout << "Nombre: " << genero.getNombre() << endl;
    cout << "Descripcion: " << genero.getDescripcion() << endl;
    cout << "Estado: " << (genero.getEstado() ? "Activo" : "Inactivo") << endl;
    cout << "----------------------------------------" << endl;
}

bool GeneroManager::ExisteID(int idGenero) {

    return _archivo.buscar(idGenero) >= 0;
}

void GeneroManager::MostrarGeneroListado(Genero genero) {
    cout << left
         << setw(8) << genero.getIdGenero()
         << setw(13) << genero.getNombre()
         << setw(12) << genero.getDescripcion()
         << setw(16) << (genero.getEstado()? "Activo" : "Inactivo")
         << endl;
}

void GeneroManager::MostrarEncabezado(){
   cout << left
         << setw(8) << "ID"
         << setw(13) << "Nombre"
         << setw(12) << "Descripcion"
         << setw(16) << "Estado"
         << endl;

    cout << "--------------------------------------------------" << endl;
}

void GeneroManager::MostrarEncabezadoInactivos() {

    cout << left
         << setw(8) << "ID"
         << setw(13) << "Nombre"
         << setw(12) << "Descripcion"
         << setw(16) << "Estado"
         << endl;

    cout << "--------------------------------------------------" << endl;
}

int GeneroManager::GenerarIDGenero() {
    int cantidad = _archivo.contarRegistros();
    int mayor = 0;

    for (int i = 0; i < cantidad; i++) {
        Genero genero = _archivo.leer(i);

        if (genero.getIdGenero() > mayor) {
            mayor = genero.getIdGenero();
        }
    }

    return mayor + 1;
}
