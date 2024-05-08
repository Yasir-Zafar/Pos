#include "../include/mainwindow.h"
#include "../include/Login/login.h"
#include "../include/Login/signup_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login loginWindow;
    signup_Window signupWindow;
    MainWindow mainWindow;

    // connect signals and slots
    // QObject::connect(&loginWindow, &login::loginSuccessful, &loginWindow, &login::close);
    // QObject::connect(&signupWindow, &signup_Window::SignupSuccessful, &mainWindow, &MainWindow::show);

    // QObject::connect(&signupWindow, &signup_Window::LoginSuccessful, &loginWindow, &login::show);
    // QObject::connect(&loginWindow, &login::SignupSuccessful, &signupWindow, &signup_Window::show);

    // QObject::connect(&loginWindow, &login::loginSuccessful, &mainWindow, &MainWindow::show);

    // QObject::connect(&loginWindow, &login::isEmployee, &mainWindow, &MainWindow::handleIsEmployee);

    // signupWindow.show();

    mainWindow.show();

    return a.exec();
}
