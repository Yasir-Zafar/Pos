#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
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
    float totalAmount;

private slots:
    void setupEmployeePage(QHBoxLayout *mainLayout);
    void on_pushButton_clicked();//add to cart button
    void on_checkout_clicked();
    void clearLayout(QLayout *layout);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
