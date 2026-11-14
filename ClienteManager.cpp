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
   int nroCliente;

   cout << "Numero del cliente: ";
   cin >> nroCliente;

   if (ExisteNro(nroCliente)) {
        cout << "Ya existe un cliente con ese numero." << endl;
        return;
    }

   Cliente cliente = CargarCliente(nroCliente);

   if(_archivo.agregarCliente(cliente)){
      cout << "Cliente guardado correctamente." << endl;
   }
   else{
      cout << "No se pudo guardar el cliente." << endl;
   }
}

void ClienteManager::ModificarCliente(){
    int nroCliente;
    string apellidoNuevo;

    cout << "Numero de cliente del registro a editar: ";
    cin >> nroCliente;

    int pos = _archivo.buscar(nroCliente);

    if (pos < 0){
        cout << "El registro no existe" << endl;
        return;
    }

    Cliente reg = _archivo.leer(pos);
    MostrarEncabezado();
    MostrarCliente(reg);

    cout << endl << "Nuevo apellido";
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

void ClienteManager::ListarTodos(){
   int cantidadRegistros = _archivo.contarRegistros();

   if(cantidadRegistros == 0){
      cout << "No hay cliente cargados." << endl;
      return;
   }

   Cliente *vec = new Cliente[cantidadRegistros];
   if (vec == NULL){
    return;
   }

   MostrarEncabezado();

   _archivo.leer(cantidadRegistros, vec);

   for(int i = 0; i < cantidadRegistros; i++){
      Cliente reg = vec[i];
      if (!reg.getEstado()) {
//            cout << colors::bright_red;
        }
        else {
 //           cout << colors::bright_green;
        }

        MostrarCliente(reg);
    }
  //  cout << colors::reset;

    cout << endl << "Cantidad de clientes: " << cantidadRegistros << endl;

    cout << "Los registros inactivos se muestran en "
  //       << colors::bright_red << "rojo"
  //       << colors::reset
         << endl;

    delete[] vec;
}

void ClienteManager::ListarXnroCliente(){
    int nroCliente;

    cout << "Ingresar numero de cliente: ";
    cin >> nroCliente;

    int pos = _archivo.buscar(nroCliente);

    if (pos >= 0){
        MostrarEncabezado();
        MostrarCliente(_archivo.leer(pos));
    }
    else{
        cout << "No existe un cliente con ese numero; " << nroCliente << endl;
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
    Cliente reg = _archivo.leer(pos);
    reg.setEstado(false);

    bool ok = _archivo.eliminar(pos);

    if (ok){
        cout << "Registro eliminado correctamente" << endl;
    }
    else{
        cout << "No se pudo eliminar el registro" << endl;
    }

    return;
}

Cliente ClienteManager::CargarCliente(int nroCliente) {
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

bool ClienteManager::ExisteNro(int nroCliente) {

    return _archivo.buscar(nroCliente) >= 0;
}

Fecha ClienteManager::PedirFecha(){
   int dia, mes, anio;

   cout << "Fecha de registro" << endl;
   cout << "  Dia: ";
   cin >> dia;
   cout << "  Mes: ";
   cin >> mes;
   cout << "  Anio: ";
   cin >> anio;

   return Fecha(dia, mes, anio);
}


void ClienteManager::MostrarEncabezado(){
   cout << endl;
   cout << left
         << setw(10) << "Numero"
         << setw(15) << "Fecha registro"
         << setw(12) << "Estado"
         << endl;

    cout << "-------------------------------------" << endl;
}

void ClienteManager::MostrarCliente(Cliente cliente){
   cout << left
         << setw(10) << cliente.getNroCliente()
         << setw(15) << cliente.getFechaRegistro().toString()
         << setw(12) << (cliente.getEstado() ? "Activo" : "Inactivo")
         << endl;
}
