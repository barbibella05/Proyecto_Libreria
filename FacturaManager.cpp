#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "FacturaManager.h"
using namespace std;

void FacturaManager::Menu() {
    int opcion;

    do {
        system("cls");
        cout << "===== VENTAS =====" << endl;
        cout << "1 - Nueva venta" << endl;
        cout << "2 - Listar ventas" << endl;
        cout << "3 - Buscar venta por numero" << endl;
        cout << "4 - Anular venta" << endl;
        cout << "5 - Detalles de venta" << endl;
        cout << "0 - Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            NuevaVenta();
            break;
        case 2:
            ListarTodas();
            break;
        case 3:
            ListarXventa();
            break;
        case 4:
            Anular();
            break;
        case 5:
            _detalleManager.Menu();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
        if (opcion != 0 && opcion != 5) {
            system("pause");
        }
    } while (opcion != 0);
}

int FacturaManager::ProximoId() {
    return _archivo.contarRegistros() + 1;
}

void FacturaManager::NuevaVenta() {
    int nroCliente;

    cout << "Numero de venta: " << ProximoId() << endl;

    cout << "Numero de cliente (0 = consumidor final): ";
    cin >> nroCliente;

    if (!ClienteValido(nroCliente)) {
        cout << "El cliente no existe o esta dado de baja." << endl;
        return;
    }

    int nroEmpleado;
    cout << "Numero de empleado: ";
    cin >> nroEmpleado;
    if (nroEmpleado <= 0) {
        cout << "Numero de empleado invalido." << endl;
        return;
    }

    Factura factura;
    factura.setVentaId(ProximoId());
    factura.setNroCliente(nroCliente);
    factura.setNroEmpleado(nroEmpleado);
    factura.setFecha(PedirFecha());

    int cantidadItems;
    cout << "Cantidad de libros distintos: ";
    cin >> cantidadItems;
    if (cantidadItems <= 0) {
        cout << "La venta necesita al menos un libro." << endl;
        return;
    }

    DetalleVenta *items = new DetalleVenta[cantidadItems];
    if (items == NULL) {
        return;
    }

    int primerDetalle = _detalleManager.ProximoId();
    float total = 0;

    for (int i = 0; i < cantidadItems; i++) {
        cout << endl << "Libro " << i + 1 << " de " << cantidadItems << endl;
        items[i] = _detalleManager.CargarDetalle(primerDetalle + i, factura.getVentaId());
        total += items[i].getCantidad() * items[i].getPrecioUnitario();
    }

    cout << endl << "Total de la venta: $" << total << endl;

    int confirma;
    cout << "Confirmar la venta? (1 = si, 0 = no): ";
    cin >> confirma;

    if (confirma != 1) {
        cout << "Venta cancelada." << endl;
        delete[] items;
        return;
    }

    bool ok = true;
    for (int i = 0; i < cantidadItems; i++) {
        if (!_detalleManager.Agregar(items[i])) {
            ok = false;
        }
    }
    if (!_archivo.guardar(factura)) {
        ok = false;
    }

    if (ok) {
        cout << "Venta guardada correctamente." << endl;
    }
    else {
        cout << "No se pudo guardar la venta." << endl;
    }

    delete[] items;
}

void FacturaManager::ListarTodas() {
    int cantidad = _archivo.contarRegistros();

    if (cantidad == 0) {
        cout << "No hay ventas cargadas." << endl;
        return;
    }

    Factura *vec = new Factura[cantidad];
    if (vec == NULL) {
        return;
    }

    _archivo.leer(cantidad, vec);

    MostrarEncabezado();
    for (int i = 0; i < cantidad; i++) {
        MostrarFactura(vec[i]);
    }

    cout << endl << "Cantidad de ventas: " << cantidad << endl;
    cout << "Cliente 0 = consumidor final." << endl;

    delete[] vec;
}

void FacturaManager::ListarXventa() {
    int ventaId;

    cout << "Numero de venta: ";
    cin >> ventaId;

    int pos = _archivo.buscar(ventaId);
    if (pos < 0) {
        cout << "No existe una venta con ese numero." << endl;
        return;
    }

    MostrarEncabezado();
    MostrarFactura(_archivo.leer(pos));

    cout << endl << "Libros de la venta:" << endl;
    _detalleManager.ListarXventa(ventaId);
}

void FacturaManager::Anular() {
    int ventaId;

    cout << "Numero de venta a anular: ";
    cin >> ventaId;

    int pos = _archivo.buscar(ventaId);
    if (pos < 0) {
        cout << "No existe una venta con ese numero." << endl;
        return;
    }

    Factura factura = _archivo.leer(pos);
    if (!factura.getEstadoVenta()) {
        cout << "La venta ya estaba anulada." << endl;
        return;
    }

    MostrarEncabezado();
    MostrarFactura(factura);

    int confirma;
    cout << endl << "Anular esta venta? (1 = si, 0 = no): ";
    cin >> confirma;

    if (confirma != 1) {
        cout << "No se anulo la venta." << endl;
        return;
    }

    if (_archivo.anular(pos)) {
        cout << "Venta anulada correctamente." << endl;
    }
    else {
        cout << "No se pudo anular la venta." << endl;
    }
}

Fecha FacturaManager::PedirFecha() {
    int dia, mes, anio;

    cout << "Fecha de la venta" << endl;
    do {
        cout << "  Dia: ";
        cin >> dia;
        cout << "  Mes: ";
        cin >> mes;
        cout << "  Anio: ";
        cin >> anio;

        if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 2000) {
            cout << "Fecha invalida, ingresarla de nuevo." << endl;
        }
    } while (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 2000);

    return Fecha(dia, mes, anio);
}

bool FacturaManager::ClienteValido(int nroCliente) {
    if (nroCliente == 0) {
        return true;
    }

    int pos = _archivoClientes.buscar(nroCliente);
    if (pos < 0) {
        return false;
    }

    Cliente cliente = _archivoClientes.leer(pos);
    return cliente.getEstado();
}

void FacturaManager::MostrarEncabezado() {
    cout << endl;
    cout << left
         << setw(8) << "Venta"
         << setw(13) << "Fecha"
         << setw(9) << "Cliente"
         << setw(10) << "Empleado"
         << setw(13) << "Total"
         << "Estado"
         << endl;

    cout << "------------------------------------------------------" << endl;
}

void FacturaManager::MostrarFactura(Factura factura) {
    cout << left
         << setw(8) << factura.getVentaId()
         << setw(13) << factura.getFecha().toString()
         << setw(9) << factura.getNroCliente()
         << setw(10) << factura.getNroEmpleado()
         << setw(13) << _detalleManager.ImporteDeVenta(factura.getVentaId())
         << (factura.getEstadoVenta() ? "Activa" : "Anulada")
         << endl;
}
