#include "signup_window.h"
#include "ui_signup_window.h"
#include<string>
#include<cstring>
#include<QMessageBox>
#include<regex>
#include<QString>
#include "login.h"

using namespace std;

signup_Window::signup_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signup_Window)
{
    ui->setupUi(this);

    QSqlDatabase CUSTDB=QSqlDatabase::addDatabase("QSQLITE");
    CUSTDB.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/customers.db");

    if(!CUSTDB.open())
    {
        ui->label_status->setText("Failed to connect database");
    }
    else
    {
        ui->label_status->setText("Database is connected");
    }
}

signup_Window::~signup_Window()
{
    delete ui;
}

bool isValidEmail(QString input)  // function to verify email
{
    regex pattern(R"(^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");
    string inputStr = input.toStdString();
    return regex_match(inputStr, pattern);
}

void signup_Window::on_pushButton_signup_clicked()
{
    QString email = ui->lineEdit_email->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Check if email field is empty
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please enter an email address.");
        return;
    }

    // Validate email format using regex
    if (!isValidEmail(email)) {
        QMessageBox::warning(this, "Sign Up", "Invalid email address. Please enter a valid email.");
        return;
    }

    // Check if username field is empty
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please enter a username.");
        return;
    }

    if(username.length()<6)
    {
        QMessageBox::warning(this, "Sign Up", "enter a longer username.");
        return;
    }

    // Check if password field is empty
    if (password.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please enter a password.");
        return;
    }

    // Check password length
    if (password.length() < 8) {
        QMessageBox::warning(this, "Sign Up", "Password should have a minimum of 8 characters.");
        return;
    }



    //write data into database



}

void signup_Window::on_pushButton_login_clicked()
{
    login *Log=new login();
    this->hide();
    Log->show();
}

