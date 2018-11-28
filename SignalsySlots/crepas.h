#ifndef CREPAS_H
#define CREPAS_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class Crepas;
}

class Crepas : public QDialog
{
    Q_OBJECT

public:
    explicit Crepas(QWidget *parent = nullptr);
    ~Crepas();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Crepas *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // CREPAS_H
