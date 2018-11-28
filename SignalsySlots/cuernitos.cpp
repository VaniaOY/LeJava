#include <QTextStream>
#include <QMessageBox>
#include "cuernitos.h"
#include "ui_cuernitos.h"
#include "carrito.h"

Cuernitos::Cuernitos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cuernitos)
{
    ui->setupUi(this);
}

Cuernitos::~Cuernitos()
{
    delete ui;
}


void Cuernitos::on_pushButton_clicked()
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

            datosArchivo <<previo<<"Cuernitos \t\t"<<cantidad<<"\t\t $"<<12*cantidad<< endl;
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

                sub <<sum+12*cantidad<< endl;
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

void Cuernitos::on_spinBox_valueChanged(int arg1)
{
    cantidad= ui->spinBox->value();
    QTextStream salida(stdout);
    salida<<cantidad;
}
