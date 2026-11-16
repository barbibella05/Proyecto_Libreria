#pragma once
#include <cstring>

class Editorial{
private:
    int  _idEditorial;
    char _nombreEd[30];
    char _cuit[15];
    bool _estado;


public:
    Editorial();
    Editorial(int idEditorial, char nombreEd[30], char cuit[15], bool estado);

//SETTERS - MAI
    void setIdEditorial(int idEditorial);
    void setNombreEd(const char* nombreEd);
    void setCuit(const char* cuit);
    void setEstado(bool estado);

//GETTERS - MAI
    int getIdEditorial()const;
    const char* getNombreEd();
    const char* getCuit();
    bool getEstado();
};
