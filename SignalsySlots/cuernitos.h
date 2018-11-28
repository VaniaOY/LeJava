#ifndef CUERNITOS_H
#define CUERNITOS_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class Cuernitos;
}

class Cuernitos : public QDialog
{
    Q_OBJECT

public:
    explicit Cuernitos(QWidget *parent = nullptr);
    ~Cuernitos();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Cuernitos *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // CUERNITOS_H
