#include "administrador.h"
#include "ui_administrador.h"
#include <QString>
#include <QTextStream>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QMessageBox>
#include "ventas.h"

Administrador::Administrador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrador)
{
   ui->setupUi(this);

}

Administrador::~Administrador()
{
    delete ui;
}

void Administrador::on_pushButton_clicked()
{
    QString correo = ui->lineEdit_3->text();
    QString contrasena = ui->lineEdit_4->text();

    QTextStream salida(stdout);
    salida<<correo;
    salida<<contrasena;

    if (correo=="Vangely" && contrasena=="123456"){
        QMessageBox::information(0,"Usuario Valido",".:Bienvenido:.");
        Ventas ven;
        ven.setModal(true);
        ven.exec();
        this->close();
    } else{
        QMessageBox::warning(0,"Usuario No Valido","Usuario incorrecto, vuelva a intentarlo");
    }




}

void Administrador::on_lineEdit_3_editingFinished()
{

}
