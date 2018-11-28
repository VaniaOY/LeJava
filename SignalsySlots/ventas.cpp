#include "ventas.h"
#include "ui_ventas.h"
#include "QMessageBox"

Ventas::Ventas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventas)
{
    pa=parent;
    ui->setupUi(this);
    ventas.setFileName("Ventas.txt");
    QString previo;
    if (ventas.exists()){
        ventas.open(QIODevice::ReadOnly);
        previo=ventas.readAll();
        ui->plainTextEdit->setPlainText(previo);
        ventas.close();

    }else{
        QMessageBox::information(0,"Vacio","No tienes pedidos hasta ahora");
    }
}

Ventas::~Ventas()
{
    delete ui;
}

void Ventas::on_pushButton_clicked()
{
    ventas.remove();
    this->repaint();
    this->close();
    Ventas actual;
    actual.setModal(true);
    actual.exec();


}
