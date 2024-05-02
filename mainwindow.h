#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include "cartitem.h"
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase salesDb;
    cartItem* newWid;
    float totalAmount;
    QVBoxLayout *layout;

private slots:
    void setupEmployeePage(QHBoxLayout *mainLayout);
    void clearLayout(QLayout *layout);
    void on_pushButton_clicked();
    void on_checkout_clicked();
    void onSpinBoxValueChanged(int newValue);

private:
Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
