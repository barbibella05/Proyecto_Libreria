#pragma once
#include "Cliente.h"

class ClienteArchivo{
private:
    std::string _nombre;
public:
      ClienteArchivo(std::string nombre = "cliente.dat");
    bool agregarCliente(Cliente reg); // Añade al final
    bool agregarCliente(Cliente reg, int pos); // Sobreescribe uno existente
    int buscar(int nroCliente);
    bool guardar(Cliente cliente, int pos);
    void modificarCliente(int nroCliente);
    void listarCliente();
    Cliente leer(int pos);
    bool leer(int cantidadRegistros, Cliente *vec);
    bool eliminar(int pos);
    int contarRegistros();
};
