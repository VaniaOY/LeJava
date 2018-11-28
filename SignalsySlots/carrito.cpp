#include "carrito.h"
#include "ui_carrito.h"
#include <QTextStream>
#include <QMessageBox>
#include "productos.h"

Carrito::Carrito(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Carrito)
{
    ui->setupUi(this);
    archivo.setFileName("Carrito.txt");
    QString previo;
   // salida<<archivo.exists();
    if (archivo.exists()){
        archivo.open(QIODevice::ReadOnly);
        previo=archivo.readAll();
      //  salida<<previo;
        ui->plainTextEdit->setPlainText(previo);
        archivo.close();

    }else{
        QMessageBox::warning(this,"Archivo no encontrado","Archivo no encontrado");
    }
    cuenta.setFileName("Cuanta.txt");
    QString previo2;
    if (cuenta.exists()){
        cuenta.open(QIODevice::ReadOnly);
        previo2=cuenta.readAll();
        ui->label_2->setText("Total: $"+previo2);
        cuenta.close();

    }else{
        QMessageBox::warning(0,"Cuenta no encontrado","cuenta no encontrado");
    }

}

Carrito::~Carrito()
{
    QTextStream salida(stdout);
    salida<<"Destructor del carrito";

    delete ui;
}


void Carrito::on_pushButton_clicked()
{
    QString previo;
    QString compra;

    //Obtenemos los valore sel archivo ventas
    ventas.setFileName("Ventas.txt");
    ventas.open(QIODevice::ReadOnly);
        previo=ventas.readAll();
        ventas.close();
        ventas.remove();

        //Obtenemos los datos de archivo e pedidos
        archivo.setFileName("Carrito.txt");
            if (archivo.exists()){
                archivo.open(QIODevice::ReadOnly);
                compra=archivo.readAll();
                archivo.close();
        }else{
                QMessageBox::information(0,"Archivo no encontrado","Archivo Carrito no encontrado");
            }

        //Escribimoes en ventas el nuevo pedido
        ventas.open(QIODevice::ReadWrite);
        QTextStream datosArchivo(&ventas);

        datosArchivo <<previo<<compra<< endl;
        ventas.flush();
        ventas.close();

        QMessageBox::information(0,"Pedido Enviaado","Su pedido ha sido enviado");
        archivo.remove();
        cuenta.remove();

        Productos *menu= new Productos(this);
        menu->show();
        this->close();
}

void Carrito::on_pushButton_2_clicked()
{
    this->close();
}
