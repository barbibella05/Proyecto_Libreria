#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "PersonaManager.h"

class ClienteManager {

private:
    ClienteArchivo _archivo;
    PersonaManager _personaManager;

    Cliente CargarCliente();
    int GenerarNroCliente();
    bool ExisteNro(int nroCliente);
    Fecha PedirFecha();

    void MostrarEncabezado();
    void MostrarEncabezadoInactivos();
    void MostrarCliente(Cliente cliente);
    void MostrarClienteListado(Cliente cliente);

public:
    void Menu();
    void NuevoCliente();
    void ModificarCliente();
    void ListarTodos();
    void ListarXnroCliente();
    void Eliminar();
};
