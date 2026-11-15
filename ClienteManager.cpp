#include <iostream>
#include <iomanip>
#include "ClienteManager.h"
//#include "colors.hpp"
using namespace std;

void ClienteManager::Menu(){
    int opcion;

    do{
        system("cls");
        cout << "============================" << endl;
        cout << "      MENU DE CLIENTES      " << endl;
        cout << "============================" << endl;
        cout << "1. Nuevo cliente" << endl;
        cout << "2. Modificar cliente" << endl;
        cout << "3. Listar clientes" << endl;
        cout << "4. Eliminar cliente" << endl;
        cout << "0. Volver" << endl;
        cout << "============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
        case 1:NuevoCliente();
            system("pause");
            break;

        case 2:ModificarCliente();
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

void ClienteManager::NuevoCliente(){
   Cliente cliente = CargarCliente();

    cout << "Numero de cliente asignado: "
         << cliente.getNroCliente() << endl;

    if (_archivo.agregarCliente(cliente)) {
        cout << "Cliente guardado correctamente." << endl;
    }
    else {
        cout << "No se pudo guardar el cliente." << endl;
    }
}

void ClienteManager::ModificarCliente(){
    int nroCliente;
    string apellidoNuevo;

    cout << "Numero de cliente del registro a editar: ";
    cin >> nroCliente;

    int pos = _archivo.buscar(nroCliente);

    if (pos < 0) {
        cout << "El registro no existe." << endl;
        return;
    }

    Cliente reg = _archivo.leer(pos);

    if (!reg.getEstado()) {
        cout << "No se puede modificar un cliente inactivo." << endl;
        return;
    }

    cout << "\n========== DATOS DEL CLIENTE ==========" << endl;

    MostrarCliente(reg);

    cout << "\nIngrese el nuevo apellido: ";
    cin >> apellidoNuevo;

    reg.setApellido(apellidoNuevo.c_str());

    bool ok = _archivo.guardar(reg, pos);

    if (ok) {
        cout << "Cliente modificado correctamente." << endl;
    }
    else {
        cout << "No se pudo modificar el cliente." << endl;
    }
}

void ClienteManager::ListarTodos(){
   int cantidad = _archivo.contarRegistros();

    if (cantidad == 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    Cliente *vec = new Cliente[cantidad];

    _archivo.leer(cantidad, vec);

    int activos = 0;
    int inactivos = 0;

    cout << "\n========== CLIENTES ACTIVOS ==========" << endl;

    MostrarEncabezado();

    for (int i = 0; i < cantidad; i++) {

        if (vec[i].getEstado()) {
            MostrarClienteListado(vec[i]);
            activos++;
        }
    }

    cout << endl;
    cout << "Cantidad de clientes activos: " << activos << endl;


    cout << "\n========== CLIENTES INACTIVOS ==========" << endl;

    MostrarEncabezadoInactivos();

    for (int i = 0; i < cantidad; i++) {

        if (!vec[i].getEstado()) {
            MostrarClienteListado(vec[i]);
            inactivos++;
        }
    }

    cout << endl;
    cout << "Cantidad de clientes inactivos: " << inactivos << endl;

    delete[] vec;
}

void ClienteManager::ListarXnroCliente(){
    int nroCliente;

    cout << "Ingresar numero de cliente: ";
    cin >> nroCliente;

    int pos = _archivo.buscar(nroCliente);

    if (pos >= 0){
        Cliente cliente = _archivo.leer(pos);
        MostrarCliente(cliente);
    }
    else{
        cout << "No existe un cliente con ese numero: " << nroCliente << endl;
    }

}

void ClienteManager::Eliminar(){
    int nroCliente;
    cout << "Numero de cliente del registro a eliminar: ";
    cin >> nroCliente;

    int pos = _archivo.buscar(nroCliente);

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

Cliente ClienteManager::CargarCliente() {
    int nroCliente = GenerarNroCliente();

    Persona persona = _personaManager.CrearPersona();

    Fecha fechaRegistro = PedirFecha();

    Cliente cliente(nroCliente, fechaRegistro);

    cliente.setNombre(persona.getNombre());
    cliente.setApellido(persona.getApellido());
    cliente.setDni(persona.getDni());
    cliente.setEmail(persona.getEmail());
    cliente.setTelefono(persona.getTelefono());
    cliente.setEstado(true);

    return cliente;
}

void ClienteManager::MostrarCliente(Cliente cliente) {
    cout << "----------------------------------------" << endl;
    cout << "Numero de cliente: " << cliente.getNroCliente() << endl;
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Apellido: " << cliente.getApellido() << endl;
    cout << "DNI: " << cliente.getDni() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Fecha de registro: " << cliente.getFechaRegistro().toString() << endl;
    cout << "Estado: " << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;
    cout << "----------------------------------------" << endl;
}

bool ClienteManager::ExisteNro(int nroCliente) {

    return _archivo.buscar(nroCliente) >= 0;
}

Fecha ClienteManager::PedirFecha(){
   int dia, mes, anio;

   while (true) {

        cout << "\nFecha de registro" << endl;

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

        cout << "\nFecha incorrecta. Ingrese nuevamente.\n";
    }
}

void ClienteManager::MostrarClienteListado(Cliente cliente) {
    cout << left
         << setw(8) << cliente.getNroCliente()
         << setw(13) << cliente.getApellido()
         << setw(12) << cliente.getDni()
         << setw(16) << cliente.getFechaRegistro().toString()
         << endl;
}

void ClienteManager::MostrarEncabezado(){
   cout << left
         << setw(8) << "Numero"
         << setw(13) << "Apellido"
         << setw(12) << "DNI"
         << setw(16) << "Fecha registro"
         << endl;

    cout << "--------------------------------------------------" << endl;
}

void ClienteManager::MostrarEncabezadoInactivos() {

    cout << left
         << setw(8) << "Numero"
         << setw(13) << "Apellido"
         << setw(12) << "DNI"
         << setw(16) << "Fecha registro"
         << endl;

    cout << "--------------------------------------------------" << endl;
}

int ClienteManager::GenerarNroCliente() {
    int cantidad = _archivo.contarRegistros();
    int mayor = 999;

    for (int i = 0; i < cantidad; i++) {
    Cliente cliente = _archivo.leer(i);

    cout << "Registro " << i
         << " - Numero: " << cliente.getNroCliente() << endl;
}

    cout << "Cantidad de registros: " << cantidad << endl;
cout << "Numero mayor encontrado: " << mayor << endl;
    return mayor + 1;
}
