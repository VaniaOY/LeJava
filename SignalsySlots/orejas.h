#ifndef OREJAS_H
#define OREJAS_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class Orejas;
}

class Orejas : public QDialog
{
    Q_OBJECT

public:
    explicit Orejas(QWidget *parent = nullptr);
    ~Orejas();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Orejas *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // OREJAS_H
