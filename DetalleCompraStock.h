#pragma once

class DetalleCompraStock{
private:
       int _idDetalle;
       int _ventaId;
       char _ISBN[14];
       int _cantidad;
       float _precioUnitario;
public:
    DetalleCompraStock();

    int getIdDetalle();
    int getVentaId();
    const char* getISBN();
    int getCantidad();
    float getPrecioUnitario();

    void setIdDetalle(int idDetalle);
    void setVentaId(int ventaId);
    void setISBN(const char* ISBN);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
};
