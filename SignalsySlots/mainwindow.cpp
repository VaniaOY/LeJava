#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "administrador.h"
#include "productos.h"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QIODevice>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    if(archivo.exists()){
        archivo.remove();
    }
}

void MainWindow::on_actionNew_Window_triggered()
{
    Administrador admin;
    admin.setModal(true);
    admin.exec();
}

void MainWindow::on_pushButton_clicked()
{
    //QTextStream salida1;

    if (ui->lineEdit->text()!=""){
        archivo.setFileName("Carrito.txt");
     /*  if (archivo.exists()){
           QMessageBox::information(0,"creado","archivo creado");
       }*/
         archivo.open(QIODevice::ReadWrite);
         QTextStream datosArchivo(&archivo);
         datosArchivo <<"Pedido de "<<ui->lineEdit->text()<<"\n Nombre \t\t Cantidad \t\t Subtotal"<< endl;
         archivo.flush();
         archivo.close();

         cuenta.setFileName("Cuanta.txt");
         cuenta.open(QIODevice::ReadWrite);
         QTextStream dato(&cuenta);
         dato <<"0"<< endl;
         cuenta.flush();
          cuenta.close();

        menu = new Productos(this);
        menu->show();
        //this ->hide();


    } else{
        QMessageBox::warning(0,"Usuario No Valido","Intentar de nuevo");
    }

}
