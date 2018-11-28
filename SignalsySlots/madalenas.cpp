#include <QTextStream>
#include <QMessageBox>
#include "madalenas.h"
#include "ui_madalenas.h"
#include "carrito.h"


Madalenas::Madalenas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Madalenas)
{
    ui->setupUi(this);
}

Madalenas::~Madalenas()
{
    delete ui;
}
void Madalenas::on_pushButton_clicked()
{

    if(cantidad!=0){
        QString previo, previoc;
        archivo.setFileName("Carrito.txt");
        if (archivo.exists()){
            archivo.open(QIODevice::ReadOnly);
            previo=archivo.readAll();
            archivo.close();

            archivo.remove();

            archivo.open(QIODevice::ReadWrite);
            QTextStream datosArchivo(&archivo);

            datosArchivo <<previo<<"Magdalenas \t\t"<<cantidad<<"\t\t $"<<8.5*cantidad<< endl;
            archivo.flush();
            archivo.close();

            cuenta.setFileName("Cuanta.txt");
            if (cuenta.exists()){
                cuenta.open(QIODevice::ReadOnly);
                previoc=cuenta.readAll();
                double sum=previoc.split(" ")[0].toDouble();
                cuenta.close();
                cuenta.remove();

                cuenta.open(QIODevice::ReadWrite);
                QTextStream sub(&cuenta);

                sub <<sum+8.5*cantidad<< endl;
                archivo.flush();
                archivo.close();

                Carrito car;
                car.setModal(true);
                car.exec();
                this->close();


            } else{
                QMessageBox::warning(0,"Cuenta no encontrado","Cuenta no encontrada");
            }
        } else{
            QMessageBox::warning(0,"Archivo no encontrado","Archivo no encontrado");
        }

        }else{
         QMessageBox::warning(0,"Cantidad nula","La cantidad minima para ingresar al carrito es 1, vuelva aintentarlo");
         }
}

void Madalenas::on_spinBox_valueChanged(int arg1)
{
    cantidad= ui->spinBox->value();
    QTextStream salida(stdout);
    salida<<cantidad;
}
