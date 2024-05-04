#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "sidebar.h"
#include "shop.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void deleteLastWidget();

public slots:
    void handleSidebarButton1Click();
    void handleSidebarButton3Click();

private:
    Ui::MainWindow *ui;

    QWidget *mainWidget;
    QHBoxLayout *mainLayout;

    Sidebar* sidebar;
    Shop* shop;
    User *user;
};
#endif // MAINWINDOW_H
