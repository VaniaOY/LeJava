#include "usuario.h"
#include "ui_usuario.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include "productos.h"
#include "QTextStream"
#include "carritoo.h"
Usuario::Usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usuario)
{
    ui->setupUi(this);
}

Usuario::~Usuario()
{

    delete ui;
}

void Usuario::on_lineEdit_editingFinished()
{

}

void Usuario::on_pushButton_clicked()
{
 /*   QString correo = ui->lineEdit_3->text();
    QString contrasena = ui->lineEdit_4->text();

    QTextStream salida(stdout);
    salida<<correo;
    salida<<contrasena;
    QMessageBox::StandardButton reply;
    if (correo=="invitado" && contrasena=="password"){
        QMessageBox::information(0,"Usuario Valido","ok");
        CarritoO myCarrito;
        Productos prod;
        prod.myCarrito(&myCarrito);
        prod.setModal(true);
        prod.exec();
    } else{
        reply=QMessageBox::warning(0,"Usuario No Valido","ok");
    }
*/

}
