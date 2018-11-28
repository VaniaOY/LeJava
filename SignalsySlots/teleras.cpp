#include <QTextStream>
#include <QMessageBox>
#include "teleras.h"
#include "ui_teleras.h"
#include "carrito.h"

Teleras::Teleras(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teleras)
{
    ui->setupUi(this);
}

Teleras::~Teleras()
{
    delete ui;
}

void Teleras::on_pushButton_clicked()
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

            datosArchivo <<previo<<"Teleras \t\t"<<cantidad<<"\t\t $"<<1.30*cantidad<< endl;
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

                sub <<sum+1.30*cantidad<< endl;
                archivo.flush();
                archivo.close();

                Carrito car;
                car.setModal(true);
                car.exec();
                this->close();


            } else{
                QMessageBox::warning(this,"Cuenta no encontrado","Cuenta no encontrada");
            }
        } else{
            QMessageBox::warning(this,"Archivo no encontrado","Archivo no encontrado");
        }

        }else{
         QMessageBox::warning(this,"Cantidad nula","La cantidad minima para ingresar al carrito es 1, vuelva aintentarlo");
         }
}

void Teleras::on_spinBox_valueChanged(int arg1)
{
    cantidad= ui->spinBox->value();
    QTextStream salida(stdout);
    salida<<cantidad;
}
