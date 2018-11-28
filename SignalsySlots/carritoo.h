#ifndef CARRITOO_H
#define CARRITOO_H
#include "QString"


class CarritoO
{
public:
    CarritoO();
    void newProducto();
    void addProd(QString,int, int);
    QString nombre[10];
    int cantidades[10];
    int subtotales[10];
    int index;
};

#endif // CARRITOO_H
