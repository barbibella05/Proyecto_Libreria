#include <iostream>
#include <iomanip>
#include "EmpleadoManager.h"
using namespace std;

///SEGUIR CON NUEVO EMPLEADO

/**
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
   int nroEmpleado;

   cout << "Numero del empleado: ";
   cin >> nroCliente;

   if (ExisteNro(nroEmpleado)) {
        cout << "Ya existe un empleado con ese numero." << endl;
        return;
    }

    cout<< "Ingrese el CUIL: ";
    cin>>cuil;

    cout >> "Ingrese la direccion: ";
    cin>>direccion;

    cout << "Ingrese la fecha de ingreso: ";
    cin >> Fecha;


   Empleado empleado = CargarEmpleado(nroEmpleado);

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
    MostrarEncabezado();
    MostrarEmpleado(reg);

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

void EmpleadoManager::ListarTodos(){
   int cantidadRegistros = _archivo.contarRegistros();

   if(cantidadRegistros == 0){
      cout << "No hay cliente cargados." << endl;
      return;
   }

   Empleado *vec = new Empleado[cantidadRegistros];
   if (vec == NULL){
    return;
   }

   MostrarEncabezado();

   _archivo.leer(cantidadRegistros, vec);

   for(int i = 0; i < cantidadRegistros; i++){
      Empleado reg = vec[i];
      if (!reg.getEstado()) {
//            cout << colors::bright_red;
        }
        else {
 //           cout << colors::bright_green;
        }

        MostrarEmpleado(reg);
    }
  //  cout << colors::reset;

    cout << endl << "Cantidad de empleado: " << cantidadRegistros << endl;

    cout << "Los registros inactivos se muestran en "
  //       << colors::bright_red << "rojo"
  //       << colors::reset
         << endl;

    delete[] vec;
}

void EmpleadoManager::ListarXnroEmpelado(){
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
    cin >> nroCliente;

    int pos = _archivo.buscar(nroEmpleado);

    if (pos < 0){
        cout << "El registro no existe" << endl;
        return;
    }
    Empleado reg = _archivo.leer(pos);
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

Empleado EmpleadoManager::CargarEmpleado(int nroEmpleado) {
    Persona persona = _personaManager.CrearPersona();
    Fecha fechaRegistro = PedirFecha();

    Empleado empleado(nroEmpleado, fechaRegistro);

    empleado.setNombre(persona.getNombre());
    empleado.setApellido(persona.getApellido());
    empleado.setDni(persona.getDni());
    empleado.setEmail(persona.getEmail());
    empleado.setTelefono(persona.getTelefono());
    empleado.setEstado(true);

    return empleado;
}

bool EmpleadoManager::ExisteNro(int nroCEmpleado) {

    return _archivo.buscar(nroEmpleado) >= 0;
}

Fecha EmpleadoManager::PedirFecha(){
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
   cout << left
         << setw(10) << empleado.getNroCliente()
         << setw(15) << empleado.getFechaRegistro().toString()
         << setw(12) << (empleado.getEstado() ? "Activo" : "Inactivo")
         << endl;
}
*/
