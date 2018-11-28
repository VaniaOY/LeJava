#ifndef DONAS_H
#define DONAS_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class Donas;
}

class Donas : public QDialog
{
    Q_OBJECT

public:
    explicit Donas(QWidget *parent = nullptr);
    ~Donas();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Donas *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // DONAS_H
