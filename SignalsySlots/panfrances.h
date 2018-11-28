#ifndef PANFRANCES_H
#define PANFRANCES_H

#include <QDialog>
#include "carrito.h"
#include <QFile>

namespace Ui {
class PanFrances;
}

class PanFrances : public QDialog
{
    Q_OBJECT

public:
    explicit PanFrances(QWidget *parent = nullptr);
    ~PanFrances();
    QFile archivo;
    QFile cuenta;

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::PanFrances *ui;
    Carrito *Car;
    int cantidad=0;
    PanFrances *panfra;
};

#endif // PANFRANCES_H
