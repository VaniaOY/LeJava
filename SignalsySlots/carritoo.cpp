#include "carritoo.h"

CarritoO::CarritoO()
{
    index=0;
}
void CarritoO::addProd(QString nom,int cant, int pre){

    nombre[index]=nom;
    cantidades[index]=cant;
    subtotales[index]=pre*cant;

    index++;
}
