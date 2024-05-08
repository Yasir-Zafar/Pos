#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "sidebar.h"
#include "Shop/shop.h"
#include "User/user.h"
#include "Analysis/analysis.h"
#include "settings.h"
#include "itemmanagement.h"

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
    Sidebar* sidebar;

signals:
    void employeeLogin();
    void initializationComplete();

public slots:
    void handleSidebarButton1Click();
    void handleSidebarButton2Click();
    void handleSidebarButton3Click();
    void handleSidebarButton4Click();
    void handleSidebarButton5Click();
    void handleIsEmployee();

private:
    Ui::MainWindow *ui;

    QWidget *mainWidget;
    QHBoxLayout *mainLayout;

    Shop* shop;
    User *user;
    Analysis* analysis;
    Settings* settings;
    ItemManagement* manage;
};
#endif // MAINWINDOW_H
