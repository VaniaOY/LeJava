#ifndef BISQUETS_H
#define BISQUETS_H

#include <QDialog>
#include <QFile>
#include "carrito.h"

namespace Ui {
class Bisquets;
}

class Bisquets : public QDialog
{
    Q_OBJECT

public:
    explicit Bisquets(QWidget *parent = nullptr);
    ~Bisquets();
    QFile archivo;
    QFile cuenta;


private slots:
    void on_pushButton_clicked();
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Bisquets *ui;
     Carrito *Car;
     int cantidad=0;
};

#endif // BISQUETS_H
