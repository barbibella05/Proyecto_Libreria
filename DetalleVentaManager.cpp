#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "DetalleVentaManager.h"
using namespace std;

void DetalleVentaManager::Menu() {
    int opcion;

    do {
        system("cls");
        cout << "===== DETALLES DE VENTA =====" << endl;
        cout << "1 - Listar todos" << endl;
        cout << "2 - Listar por numero de venta" << endl;
        cout << "0 - Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            ListarTodos();
            break;
        case 2: {
            int ventaId;
            cout << "Numero de venta: ";
            cin >> ventaId;
            ListarXventa(ventaId);
            break;
        }
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

int DetalleVentaManager::ProximoId() {
    return _archivo.contarRegistros() + 1;
}

DetalleVenta DetalleVentaManager::CargarDetalle(int detalleId, int ventaId) {
    string isbn;
    int cantidad;
    float precio;

    cout << "ISBN (13 digitos): ";
    cin >> isbn;
    while (isbn.size() != 13) {
        cout << "El ISBN debe tener 13 digitos. Ingresar de nuevo: ";
        cin >> isbn;
    }

    cout << "Cantidad: ";
    cin >> cantidad;
    while (cantidad <= 0) {
        cout << "La cantidad debe ser mayor que 0. Ingresar de nuevo: ";
        cin >> cantidad;
    }

    cout << "Precio unitario: ";
    cin >> precio;

    return DetalleVenta(detalleId, ventaId, isbn.c_str(), cantidad, precio);
}

bool DetalleVentaManager::Agregar(DetalleVenta detalle) {
    return _archivo.guardar(detalle);
}

void DetalleVentaManager::ListarTodos() {
    int cantidad = _archivo.contarRegistros();

    if (cantidad == 0) {
        cout << "No hay detalles cargados." << endl;
        return;
    }

    DetalleVenta *vec = new DetalleVenta[cantidad];
    if (vec == NULL) {
        return;
    }

    _archivo.leer(cantidad, vec);

    MostrarEncabezado();
    for (int i = 0; i < cantidad; i++) {
        MostrarDetalle(vec[i]);
    }
    cout << endl << "Cantidad de detalles: " << cantidad << endl;

    delete[] vec;
}

void DetalleVentaManager::ListarXventa(int ventaId) {
    int cantidad = _archivo.contarRegistros();

    if (cantidad == 0) {
        cout << "No hay detalles cargados." << endl;
        return;
    }

    DetalleVenta *vec = new DetalleVenta[cantidad];
    if (vec == NULL) {
        return;
    }

    _archivo.leer(cantidad, vec);

    MostrarEncabezado();
    int encontrados = 0;
    for (int i = 0; i < cantidad; i++) {
        if (vec[i].getVentaId() == ventaId) {
            MostrarDetalle(vec[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "Esa venta no tiene detalles." << endl;
    }

    delete[] vec;
}

float DetalleVentaManager::ImporteDeVenta(int ventaId) {
    int cantidad = _archivo.contarRegistros();

    if (cantidad == 0) {
        return 0;
    }

    DetalleVenta *vec = new DetalleVenta[cantidad];
    if (vec == NULL) {
        return 0;
    }

    _archivo.leer(cantidad, vec);

    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        if (vec[i].getVentaId() == ventaId && vec[i].getEstado()) {
            total += vec[i].getCantidad() * vec[i].getPrecioUnitario();
        }
    }

    delete[] vec;
    return total;
}

void DetalleVentaManager::MostrarEncabezado() {
    cout << endl;
    cout << left
         << setw(9) << "Detalle"
         << setw(7) << "Venta"
         << setw(16) << "ISBN"
         << setw(6) << "Cant"
         << setw(12) << "Precio"
         << setw(12) << "Subtotal"
         << "Estado"
         << endl;

    cout << "----------------------------------------------------------------" << endl;
}

void DetalleVentaManager::MostrarDetalle(DetalleVenta detalle) {
    cout << left
         << setw(9) << detalle.getDetalleId()
         << setw(7) << detalle.getVentaId()
         << setw(16) << detalle.getISBN()
         << setw(6) << detalle.getCantidad()
         << setw(12) << detalle.getPrecioUnitario()
         << setw(12) << detalle.getCantidad() * detalle.getPrecioUnitario()
         << (detalle.getEstado() ? "Activo" : "Anulado")
         << endl;
}
