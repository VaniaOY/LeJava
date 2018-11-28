#include "bolillos.h"
#include "ui_bolillos.h"
#include "carrito.h"
#include <QTextStream>
#include <QMessageBox>

Bolillos::Bolillos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bolillos)
{
    ui->setupUi(this);
}

Bolillos::~Bolillos()
{
    delete ui;
}
void Bolillos::on_pushButton_clicked()
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

                datosArchivo <<previo<<"Bolillos \t\t"<<cantidad<<"\t\t $"<<1.5*cantidad<<endl;
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

                    sub <<sum+1.5*cantidad<< endl;
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





void Bolillos::on_spinBox_valueChanged(int arg1)
{
    cantidad= arg1;
    QTextStream salida(stdout);
    salida<<cantidad;
}
