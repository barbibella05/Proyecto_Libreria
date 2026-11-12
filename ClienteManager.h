#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "PersonaManager.h"

class ClienteManager {

private:
    ClienteArchivo _archivo;
    PersonaManager _personaManager;

    Cliente CargarCliente(int nroCliente);
    bool ExisteNro(int nroCliente);
    Fecha PedirFecha();

    void MostrarEncabezado();
    void MostrarCliente(Cliente cliente);

public:
    void Menu();
    void NuevoCliente();
    void ModificarCliente();
    void ListarTodos();
    void ListarXnroCliente();
    void Eliminar();
};
