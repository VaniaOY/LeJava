#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QDialog>
#include "productos.h"

namespace Ui {
class Administrador;
}
class QSqlQuery;
class Administrador : public QDialog
{
    Q_OBJECT

public:
    explicit Administrador(QWidget *parent = nullptr);
    ~Administrador();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_3_editingFinished();

private:
    Ui::Administrador *ui;
    Productos *prod;
};

#endif // ADMINISTRADOR_H
