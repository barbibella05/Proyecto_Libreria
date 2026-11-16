#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "InformeManager.h"
using namespace std;

void InformeManager::Menu() {
    int opcion;

    do {
        system("cls");
        cout << "===== INFORMES =====" << endl;
        cout << "1 - Recaudacion por cliente" << endl;
        cout << "2 - Libros sin ventas" << endl;
        cout << "3 - Genero mas vendido" << endl;
        cout << "" << endl;
        cout << "0 - Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            RecaudacionPorCliente();
            break;
        case 2:
            LibrosSinVentas();
            break;
        case 3:
            GeneroMasVendido();
            break;
        case 4:
            VentasPorEmpleado();
            break;

        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
        if (opcion != 0) {
            system("pause");
        }
    } while (opcion != 0);
}

void InformeManager::RecaudacionPorCliente(){}

void InformeManager::LibrosSinVentas(){}

void InformeManager::GeneroMasVendido(){
    GeneroArchivo arcGenero;
    LibroArchivo arcLibro;
    DetalleVentaArchivo arcDetalle;

    int cantidadGeneros = arcGenero.contarRegistros();
    int cantidadDetalles = arcDetalle.contarRegistros();

    if(cantidadGeneros == 0 || cantidadDetalles == 0){
        cout << "No hay generos o ventas registradas" << endl;
        return;
    }

    int *idsGeneros = new int[cantidadGeneros];
    int *cantidadesVendidas = new int[cantidadGeneros]={0};

    for(int i = 0; i < cantidadGeneros; i++){
        Genero obj = arcGenero.leer(i);
        idsGeneros[i] = obj.getIdGenero();
    }
    for(int i = 0; i < cantidadDetalles; i++){
        DetalleVenta detalle = arcDetalle.leer(i);
        int posLibro = arcLibro.buscar(detalle.getISBN());

        if (posLibro >= 0) {
            Libro libro = arcLibro.leer(posLibro);
            int idGenero = libro.getIdGenero();
            for(int j = 0; j < cantidadGeneros; j++){
                if(idsGeneros[j] == idGenero){
                    cantidadesVendidas[j] += detalle.getCantidad();
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantidadGeneros - 1; i++){
        for(int j = i + 1; j < cantidadGeneros; j++){
            if(cantidadesVendidas[i] < cantidadesVendidas[j]){
                int auxCantidad = cantidadesVendidas[i];
                cantidadesVendidas[i] = cantidadesVendidas[j];
                cantidadesVendidas[j] = auxCantidad;

                int auxID = idsGeneros[i];
                idsGeneros[i] = idsGeneros[j];
                idsGeneros[j] = auxID;
            }
        }
    }

    cout << "========================================" << endl;
    cout << "       TOP 5 GENEROS MAS VENDIDOS       " << endl;
    cout << "========================================" << endl;
    int limite = cantidadGeneros;

    if(limite > 5){
        limite = 5;
    }

    Genero genero;

    for(int i = 0; i < limite; i++){

        int pos = arcGenero.buscar(idsGeneros[i]);

        if(pos >= 0){

            genero = arcGenero.leer(pos);

            cout << i + 1 << ". "<< genero.getNombre()<< " - " << cantidadesVendidas[i] << " unidades vendidas" << endl;
        }
    }

    delete[] idsGeneros;
    delete[] cantidadesVendidas;
}

void InformeManager::VentasPorEmpleado() {

    EmpleadoArchivo arcEmpleado;
    VentaArchivo arcVenta;
    DetalleVentaArchivo arcDetalle;

    int cantidadEmpleados = arcEmpleado.contarRegistros();
    int cantidadVentasReg = arcVenta.contarRegistros();
    int cantidadDetalles = arcDetalle.contarRegistros();

    if (cantidadEmpleados == 0 || cantidadVentasReg == 0) {
        cout << "No hay empleados o ventas registradas." << endl;
        return;
    }

    // Crear los vectores dinamicos
    int *idsEmpleados = new int[cantidadEmpleados];
    int *cantidadVentas = new int[cantidadEmpleados]{0};
    float *importesTotales = new float[cantidadEmpleados]{0};

    // 1. Cargar los numeros de empleados
    for (int i = 0; i < cantidadEmpleados; i++) {

        Empleado empleado = arcEmpleado.leer(i);

        idsEmpleados[i] = empleado.getNroEmpleado();
    }

    // 2. Recorrer todas las ventas
    for (int i = 0; i < cantidadVentasReg; i++) {

        Venta venta = arcVenta.leer(i);

        // Excluir ventas canceladas
        if (venta.getEstado()) {

            int nroEmpleado = venta.getNroEmpleado();

            // Buscar la posicion del empleado
            for (int j = 0; j < cantidadEmpleados; j++) {

                if (idsEmpleados[j] == nroEmpleado) {

                    // Contar una venta para el empleado
                    cantidadVentas[j]++;

                    // 3. Recorrer los detalles de esa venta
                    for (int k = 0; k < cantidadDetalles; k++) {

                        DetalleVenta detalle = arcDetalle.leer(k);

                        if (detalle.getVentaId() == venta.getVentaId()) {

                            float importe = detalle.getCantidad()
                                            * detalle.getPrecioUnitario();

                            importesTotales[j] += importe;
                        }
                    }

                    break;
                }
            }
        }
    }

    // 4. Ordenar de mayor a menor cantidad de ventas
    for (int i = 0; i < cantidadEmpleados - 1; i++) {

        for (int j = i + 1; j < cantidadEmpleados; j++) {

            if (cantidadVentas[i] < cantidadVentas[j]) {

                int auxCantidad = cantidadVentas[i];
                cantidadVentas[i] = cantidadVentas[j];
                cantidadVentas[j] = auxCantidad;

                int auxID = idsEmpleados[i];
                idsEmpleados[i] = idsEmpleados[j];
                idsEmpleados[j] = auxID;

                float auxImporte = importesTotales[i];
                importesTotales[i] = importesTotales[j];
                importesTotales[j] = auxImporte;
            }
        }
    }

    // 5. Mostrar el Top 5
    cout << "==========================================================" << endl;
    cout << "              TOP 5 VENTAS POR EMPLEADO                  " << endl;
    cout << "==========================================================" << endl;

    cout << left
         << setw(8) << "Puesto"
         << setw(15) << "Nro.Empleado"
         << setw(15) << "Ventas"
         << setw(15) << "Importe total"
         << endl;

    cout << "----------------------------------------------------------" << endl;

    int limite = cantidadEmpleados;

    if (limite > 5) {
        limite = 5;
    }

    for (int i = 0; i < limite; i++) {

        int pos = arcEmpleado.buscar(idsEmpleados[i]);

        if (pos >= 0) {

            Empleado empleado = arcEmpleado.leer(pos);

            cout << left
                 << setw(8) << i + 1
                 << setw(15) << empleado.getNroEmpleado()
                 << setw(15) << cantidadVentas[i]
                 << "$" << fixed << setprecision(2)
                 << importesTotales[i]
                 << endl;
        }
    }

    // Liberar memoria
    delete[] idsEmpleados;
    delete[] cantidadVentas;
    delete[] importesTotales;
}
