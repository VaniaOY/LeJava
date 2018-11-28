#ifndef MADALENAS_H
#define MADALENAS_H

#include <QDialog>
#include "carrito.h"

namespace Ui {
class Madalenas;
}

class Madalenas : public QDialog
{
    Q_OBJECT

public:
    explicit Madalenas(QWidget *parent = nullptr);
    ~Madalenas();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Madalenas *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // MADALENAS_H
