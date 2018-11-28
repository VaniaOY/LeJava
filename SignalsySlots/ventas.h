#ifndef VENTAS_H
#define VENTAS_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Ventas;
}

class Ventas : public QDialog
{
    Q_OBJECT

public:
    explicit Ventas(QWidget *parent = nullptr);
    ~Ventas();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventas *ui;
    QFile ventas;
    Ventas *actual;
    Ventas *aux;
    QWidget *pa;
};

#endif // VENTAS_H
