#ifndef MIDIALOGO_H
#define MIDIALOGO_H

#include <QDialog>
#include "administrador.h"
#include "usuario.h"

namespace Ui {
class Midialogo;
}

class Midialogo : public QDialog
{
    Q_OBJECT

public:
    explicit Midialogo(QWidget *parent = nullptr);
    ~Midialogo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Midialogo *ui;
    Administrador *admin;
    Usuario *user;
};

#endif // MIDIALOGO_H
