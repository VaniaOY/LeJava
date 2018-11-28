#ifndef CONCHAS_H
#define CONCHAS_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class Conchas;
}

class Conchas : public QDialog
{
    Q_OBJECT

public:
    explicit Conchas(QWidget *parent = nullptr);
    ~Conchas();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Conchas *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // CONCHAS_H
