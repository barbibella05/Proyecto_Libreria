#pragma once

class DetalleVenta {
private:
    int _detalleId;
    int _ventaId;
    char _ISBN[14];
    int _cantidad;
    float _precioUnitario;
    bool _estado;

public:
    DetalleVenta();
    DetalleVenta(int detalleId, int ventaId, const char *isbn, int cantidad, float precioUnitario);

    int getDetalleId();
    int getVentaId();
    const char *getISBN();
    int getCantidad();
    float getPrecioUnitario();
    bool getEstado();

    void setDetalleId(int detalleId);
    void setVentaId(int ventaId);
    void setISBN(const char *isbn);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
    void setEstado(bool estado);
};
