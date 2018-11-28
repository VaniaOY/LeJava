#include "productos.h"
#include "ui_productos.h"
#include "bisquets.h"
#include "cuernitos.h"
#include "pasteles.h"
#include <QMessageBox>

Productos::Productos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Productos)
{
    ui->setupUi(this);

}

Productos::~Productos()
{
    delete ui;
}



void Productos::on_pushButton_clicked()
{
    panfra = new PanFrances(this);
    panfra->show();
}

void Productos::on_pushButton_2_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
        bisquet= new Bisquets(this);
        bisquet->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_3_clicked()
{

    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
        paste = new Pasteles(this);
        paste->show();
    }else{
        QMessageBox::information(this,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_4_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){

        mante = new Mantecadas(this);
        mante->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_5_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){

        cuerno = new Cuernitos(this);
        cuerno->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_6_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
        ore = new Orejas(this);
        ore->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_7_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
        Boli = new Bolillos(this);
        Boli->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_8_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
       tele = new Teleras(this);
        tele->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_9_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
        con = new Conchas(this);
        con->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_10_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
        mada = new Madalenas(this);
        mada->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_11_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
        don = new Donas(this);
        don->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

void Productos::on_pushButton_12_clicked()
{
    cuenta.setFileName("Carrito.txt");
    if (cuenta.exists()){
       crep = new Crepas(this);
        crep->show();
    }else{
        QMessageBox::information(0,"Sesion cerrada","Para hacer otro pedido porfavor vuelve a ingresar tu nombre");
        this->close();
    }
}

