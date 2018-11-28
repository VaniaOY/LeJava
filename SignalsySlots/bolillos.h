#ifndef BOLILLOS_H
#define BOLILLOS_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class Bolillos;
}

class Bolillos : public QDialog
{
    Q_OBJECT

public:
    explicit Bolillos(QWidget *parent = nullptr);
    ~Bolillos();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Bolillos *ui;
    Carrito *Car;
    int cantidad=0;
};

#endif // BOLILLOS_H
