#include "mainwindow.h"
#include "login.h"
#include "signup_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login loginWindow;
    signup_Window signupWindow;
    MainWindow mainWindow;

    // connect signals and slots
    QObject::connect(&loginWindow, &login::loginSuccessful, &mainWindow, &MainWindow::show);
    QObject::connect(&signupWindow, &signup_Window::SignupSuccessful, &loginWindow, &login::show);

    QObject::connect(&loginWindow, &login::isEmployee, &mainWindow, &MainWindow::handleIsEmployee);

    // show the signup window first
    loginWindow.show();
    // mainWindow.show();

    return a.exec();
}
