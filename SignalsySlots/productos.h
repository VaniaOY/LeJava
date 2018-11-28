#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <QDialog>
#include "bisquets.h"
#include "cuernitos.h"
#include "pasteles.h"
#include "bolillos.h"
#include "conchas.h"
#include "crepas.h"
#include "donas.h"
#include "madalenas.h"
#include "orejas.h"
#include "panfrances.h"
#include "teleras.h"
#include "mantecadas.h"
#include "carritoo.h"
#include <QFile>

namespace Ui {
class Productos;
}

class Productos : public QDialog
{
    Q_OBJECT

public:
    explicit Productos(QWidget *parent = nullptr);
    ~Productos();
    void myCarrito(CarritoO *carr);



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::Productos *ui;
    PanFrances *panfra;
    Bisquets *bisquet;
    Pasteles *paste;
    Cuernitos *cuerno;
    Mantecadas *mante;
    Cuernitos *cuern;
    Orejas *ore;
    Bolillos *Boli;
    Teleras *tele;
    Conchas *con;
    Madalenas *mada;
    Donas *don;
    Crepas *crep;
    CarritoO *carro;
    QFile cuenta;

};

#endif // PRODUCTOS_H
