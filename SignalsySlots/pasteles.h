#ifndef PASTELES_H
#define PASTELES_H

#include <QDialog>
#include "carrito.h"
#include <QFile>
namespace Ui {
class Pasteles;
}

class Pasteles : public QDialog
{
    Q_OBJECT

public:
    explicit Pasteles(QWidget *parent = nullptr);
    ~Pasteles();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Pasteles *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // PASTELES_H
