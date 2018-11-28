#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "midialogo.h"
#include "visualizar.h"
#include "productos.h"
#include <QFile>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_Window_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QFile archivo;
    QFile cuenta;
    Midialogo *miDialogo;
    Productos *menu;
    Visualizar *visua;
};

#endif // MAINWINDOW_H
