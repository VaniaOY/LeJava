#ifndef MANTECADAS_H
#define MANTECADAS_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class Mantecadas;
}

class Mantecadas : public QDialog
{
    Q_OBJECT

public:
    explicit Mantecadas(QWidget *parent = nullptr);
    ~Mantecadas();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Mantecadas *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // MANTECADAS_H
