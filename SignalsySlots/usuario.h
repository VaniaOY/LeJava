#ifndef USUARIO_H
#define USUARIO_H

#include <QDialog>
#include"productos.h"

namespace Ui {
class Usuario;
}

class Usuario : public QDialog
{
    Q_OBJECT

public:
    explicit Usuario(QWidget *parent = nullptr);
    ~Usuario();

private slots:
    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::Usuario *ui;
};

#endif // USUARIO_H
