#pragma once

class DetalleCompraStock{
private:
    int _idDetalle;
    int _compraId;
    char _ISBN[14];
    int _cantidad;
    float _precioUnitario;
    bool _estado;

public:
    DetalleCompraStock();

    int getIdDetalle();
    int getCompraId();
    const char* getISBN();
    int getCantidad();
    float getPrecioUnitario();
    bool getEstado();

    void setIdDetalle(int idDetalle);
    void setCompraId(int compraId);
    void setISBN(const char* ISBN);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
    void setEstado(bool estado);
};
