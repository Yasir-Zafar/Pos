#include "mainwindow.h"
#include "login.h" //  header file for the login window class
#include "signup_window.h" //  header file for the signup window class

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create instances of each window
    login loginWindow;
    signup_Window signupWindow;
    MainWindow mainWindow;

    // // connect signals and slots
    // QObject::connect(&loginWindow, &login::loginSuccessful, &mainWindow, &MainWindow::show);
    // QObject::connect(&signupWindow, &signup_Window::SignupSuccessful, &loginWindow, &login::show);

    // // show the signup window first
    // signupWindow.show();
    mainWindow.show();

    return a.exec();
}
