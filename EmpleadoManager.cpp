#include <iostream>
#include <iomanip>
#include <string>
#include "EmpleadoManager.h"
using namespace std;


void EmpleadoManager::Menu(){
    int opcion;

    do{
        system("cls");
        cout << "============================" << endl;
        cout << "      MENU DE EMPLEADO      " << endl;
        cout << "============================" << endl;
        cout << "1. Nuevo empleado" << endl;
        cout << "2. Modificar empleado" << endl;
        cout << "3. Listar empleado" << endl;
        cout << "4. Eliminar empleado" << endl;
        cout << "0. Volver" << endl;
        cout << "============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
        case 1:NuevoEmpleado();
            system("pause");
            break;

        case 2:ModificarEmpleado();
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

void EmpleadoManager::NuevoEmpleado(){
    Empleado empleado = CargarEmpleado();

   if(_archivo.agregarEmpleado(empleado)){
      cout << "Empleado guardado correctamente." << endl;
   }
   else{
      cout << "No se pudo guardar el empleado." << endl;
   }
}

void EmpleadoManager::ModificarEmpleado(){
    int nroEmpleado;
    string apellidoNuevo;

    cout << "Numero de empleado del registro a editar: ";
    cin >> nroEmpleado;

    int pos = _archivo.buscar(nroEmpleado);

    if (pos < 0){
        cout << "El registro no existe" << endl;
        return;
    }

    Empleado reg = _archivo.leer(pos);
    cout << "\n========== DATOS DEL EMPLEADO ==========" << endl;
    MostrarEmpleado(reg);

    cout << endl << "Ingrese el nuevo apellido: ";
    cin >> apellidoNuevo;

    reg.setApellido(apellidoNuevo.c_str());

    bool ok = _archivo.guardar(reg, pos);

    if (ok){
        cout << "Registro editado correctamente" << endl;
    }
    else{
        cout << "No se pudo editar el registro" << endl;
    }

    return;
}

void EmpleadoManager::ListarTodos(){
    int cantidad = _archivo.contarRegistros();

    if (cantidad == 0) {
        cout << "No hay empleados cargados." << endl;
        return;
    }

    Empleado *vec = new Empleado[cantidad];

    _archivo.leer(cantidad, vec);

    int activos = 0;
    int inactivos = 0;

    cout << "========== EMPLEADOS ACTIVOS ==========" << endl;

    MostrarEncabezadoActivos();

    for (int i = 0; i < cantidad; i++) {

        if (vec[i].getEstado()) {

            cout << left
                 << setw(8) << vec[i].getNroEmpleado()
                 << setw(13) << vec[i].getApellido()
                 << setw(10) << vec[i].getDni()
                 << setw(15) << vec[i].getFechaIngreso().toString()
                 << setw(15) << MostrarPerfil(vec[i].getPerfil())
                 << endl;

            activos++;
        }
    }

    cout << endl;
    cout << "Cantidad de empleados activos: " << activos << endl;


    cout << "\n========== EMPLEADOS INACTIVOS ==========" << endl;

    MostrarEncabezadoInactivos();

    for (int i = 0; i < cantidad; i++) {

        if (!vec[i].getEstado()) {

            cout << left
                 << setw(8) << vec[i].getNroEmpleado()
                 << setw(13) << vec[i].getApellido()
                 << setw(10) << vec[i].getDni()
                 << setw(15) << vec[i].getFechaIngreso().toString()
                 << setw(15) << vec[i].getFechaEgreso().toString()
                 << setw(15) << MostrarPerfil(vec[i].getPerfil())
                 << endl;

            inactivos++;
        }
    }

    cout << endl;
    cout << "Cantidad de empleados inactivos: " << inactivos << endl;

    delete[] vec;
}

void EmpleadoManager::BuscarXNnroEmpleado(){
    int nroEmpleado;

    cout << "Ingresar numero de empleado: ";
    cin >> nroEmpleado;

    int pos = _archivo.buscar(nroEmpleado);

    if (pos >= 0){
        MostrarEncabezado();
        MostrarEmpleado(_archivo.leer(pos));
    }
    else{
        cout << "No existe un empleado con ese numero; " << nroEmpleado << endl;
    }

}

void EmpleadoManager::Eliminar(){
    int nroEmpleado;
    cout << "Numero de empleado del registro a eliminar: ";
    cin >> nroEmpleado;

    int pos = _archivo.buscar(nroEmpleado);

    if (pos < 0){
        cout << "El registro no existe" << endl;
        return;
    }

    Empleado reg = _archivo.leer(pos);

    cout << "Ingrese la fecha de egreso:" << endl;
    Fecha fechaEgreso = PedirFecha();

    reg.setFechaEgreso(fechaEgreso);
    reg.setEstado(false);

    bool ok = _archivo.guardar(reg,pos);

    if (ok){
        cout << "Registro eliminado correctamente" << endl;
    }
    else{
        cout << "No se pudo eliminar el registro" << endl;
    }

    return;
}

Empleado EmpleadoManager::CargarEmpleado(){
    int nroEmpleado = GenerarNroEmpleado();

    cout << "Numero de empleado asignado: " << nroEmpleado << endl;

    Persona persona = _personaManager.CrearPersona();

    Fecha fechaIngreso = PedirFecha();

    string direccion;
    int perfil;

    cout << "Ingrese la direccion: ";
    cin.ignore();
    getline(cin, direccion);

    cout << endl;
    cout << "Seleccione el perfil:" << endl;
    cout << "1. Vendedor" << endl;
    cout << "2. Cajero" << endl;
    cout << "3. Supervisor" << endl;
    cout << "4. Gerente" << endl;
    cout << "Opcion: ";
    cin >> perfil;

    while(perfil < 1 || perfil > 4) {
        cout << "Perfil incorrecto. Ingrese nuevamente: ";
        cin >> perfil;
    }

    Empleado empleado;

    empleado.setNroEmpleado(nroEmpleado);
    empleado.setFechaIngreso(fechaIngreso);

    empleado.setNombre(persona.getNombre());
    empleado.setApellido(persona.getApellido());
    empleado.setDni(persona.getDni());
    empleado.setEmail(persona.getEmail());
    empleado.setTelefono(persona.getTelefono());

    empleado.setDireccion(direccion.c_str());
    empleado.setPerfil(perfil);
    empleado.setEstado(true);

    return empleado;
}

bool EmpleadoManager::ExisteNro(int nroEmpleado) {

    return _archivo.buscar(nroEmpleado) >= 0;
}

Fecha EmpleadoManager::PedirFecha(){
   int dia, mes, anio;

    while (true) {
        cout << "Fecha de ingreso" << endl;

        cout << "  Dia: ";
        cin >> dia;

        cout << "  Mes: ";
        cin >> mes;

        cout << "  Anio: ";
        cin >> anio;

        bool valida = true;

        if (anio < 1900 || mes < 1 || mes > 12 || dia < 1) {
            valida = false;
        }
        else {
            int diasMes;

            if (mes == 2) {
                if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
                    diasMes = 29;
                }
                else {
                    diasMes = 28;
                }
            }
            else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                diasMes = 30;
            }
            else {
                diasMes = 31;
            }

            if (dia > diasMes) {
                valida = false;
            }
        }

        if (valida) {
            return Fecha(dia, mes, anio);
        }

        cout << "\nFecha incorrecta. Ingrese nuevamente.\n\n";
    }
}


void EmpleadoManager::MostrarEncabezado(){
   cout << endl;
   cout << left
         << setw(10) << "Numero"
         << setw(15) << "Fecha registro"
         << setw(12) << "Estado"
         << endl;

    cout << "-------------------------------------" << endl;
}

void EmpleadoManager::MostrarEmpleado(Empleado empleado){
       cout << "----------------------------------------" << endl;
    cout << "Numero de empleado: " << empleado.getNroEmpleado() << endl;
    cout << "Nombre: " << empleado.getNombre() << endl;
    cout << "Apellido: " << empleado.getApellido() << endl;
    cout << "DNI: " << empleado.getDni() << endl;
    cout << "Email: " << empleado.getEmail() << endl;
    cout << "Telefono: " << empleado.getTelefono() << endl;
    cout << "Direccion: " << empleado.getDireccion() << endl;
    cout << "Fecha de ingreso: " << empleado.getFechaIngreso().toString() << endl;
    cout << "Fecha de egreso: " << empleado.getFechaEgreso().toString() << endl;

    cout << "Perfil: ";

    switch (empleado.getPerfil()) {
        case 1: cout << "Vendedor"; break;
        case 2: cout << "Cajero"; break;
        case 3: cout << "Supervisor"; break;
        case 4: cout << "Gerente"; break;
        default: cout << "Sin perfil"; break;
    }

    cout << endl;

    cout << "Estado: " << (empleado.getEstado() ? "Activo" : "Inactivo") << endl;
    cout << "----------------------------------------" << endl;
}

void EmpleadoManager::MostrarEncabezadoActivos() {
    cout << left
         << setw(8) << "Numero"
         << setw(13) << "Apellido"
         << setw(10) << "DNI"
         << setw(15) << "Fecha ingreso"
         << setw(15) << "Perfil"
         << endl;

    cout << "-------------------------------------------------------" << endl;
}

void EmpleadoManager::MostrarEncabezadoInactivos() {
    cout << left
         << setw(8) << "Numero"
         << setw(13) << "Apellido"
         << setw(10) << "DNI"
         << setw(15) << "Fecha ingreso"
         << setw(15) << "Fecha egreso"
         << setw(15) << "Perfil"
         << endl;

    cout << "--------------------------------------------------------------------" << endl;
}

string EmpleadoManager::MostrarPerfil(int perfil) {

    switch (perfil) {
        case 1: return "Vendedor";
        case 2: return "Cajero";
        case 3: return "Supervisor";
        case 4: return "Gerente";
        default: return "Sin perfil";
    }
}

int EmpleadoManager::GenerarNroEmpleado(){
    int cantidad = _archivo.contarRegistros();
    int mayor = 999;

    for(int i = 0; i < cantidad; i++){
        Empleado empleado = _archivo.leer(i);

        if(empleado.getNroEmpleado() > mayor){
            mayor = empleado.getNroEmpleado();
        }
    }

    return mayor + 1;
}
