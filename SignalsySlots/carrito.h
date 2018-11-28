#ifndef CARRITO_H
#define CARRITO_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Carrito;
}

class Carrito : public QDialog
{
    Q_OBJECT

public:
    explicit Carrito(QWidget *parent = nullptr);
    ~Carrito();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Carrito *ui;
    QFile archivo;
    QFile ventas;
    QFile cuenta;


};

#endif // CARRITO_H
