#ifndef VISUALIZAR_H
#define VISUALIZAR_H

#include <QDialog>

namespace Ui {
class Visualizar;
}

class Visualizar : public QDialog
{
    Q_OBJECT

public:
    explicit Visualizar(QWidget *parent = nullptr);
    ~Visualizar();

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
    Ui::Visualizar *ui;
};

#endif // VISUALIZAR_H
