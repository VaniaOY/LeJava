#include "bisquets.h"
#include "ui_bisquets.h"
#include "carrito.h"
#include <QTextStream>
#include <QMessageBox>

Bisquets::Bisquets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bisquets)
{
    ui->setupUi(this);
}

Bisquets::~Bisquets()
{
    delete ui;
}

void Bisquets::on_pushButton_clicked()
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

            datosArchivo <<previo<<"Biskets \t\t"<<cantidad<<"\t\t $"<<4.5*cantidad<< endl;
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

                sub <<sum+4.5*cantidad<< endl;
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

void Bisquets::on_spinBox_valueChanged(int arg1)
{
   cantidad= arg1;
   QTextStream salida(stdout);
   salida<<cantidad;

}
