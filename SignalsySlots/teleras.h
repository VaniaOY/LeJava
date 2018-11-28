#ifndef TELERAS_H
#define TELERAS_H

#include <QDialog>
#include "carrito.h"

namespace Ui {
class Teleras;
}

class Teleras : public QDialog
{
    Q_OBJECT

public:
    explicit Teleras(QWidget *parent = nullptr);
    ~Teleras();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Teleras *ui;
    Carrito *Car;
    int cantidad=0;
};

#endif // TELERAS_H
