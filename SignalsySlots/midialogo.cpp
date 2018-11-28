#include "midialogo.h"
#include "ui_midialogo.h"
#include "administrador.h"
#include "usuario.h"
Midialogo::Midialogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Midialogo)
{
    ui->setupUi(this);

}

Midialogo::~Midialogo()
{
    delete ui;
}

void Midialogo::on_pushButton_clicked()
{
        Administrador admin;
        admin.setModal(true);
        admin.exec();
}

void Midialogo::on_pushButton_2_clicked()
{
       Usuario user;
       user.setModal(true);
       user.exec();
}

