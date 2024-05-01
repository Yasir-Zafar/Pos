#include "login.h"
#include "ui_login.h"
#include "signup_window.h"
#include<QMessageBox>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
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

login::~login()
{
    delete ui;
}

void login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Check if username field is empty
    if (username.isEmpty()) {
        QMessageBox::warning(this, "login", "Please enter your username.");
        return;
    }

    // Check if password field is empty
    if (password.isEmpty()) {
        QMessageBox::warning(this, "login", "Please enter your password.");
        return;
    }

    // Check password length
    if (password.length() < 8) {
        QMessageBox::warning(this, "Sign Up", "Password should have a minimum of 8 characters.");
        return;
    }

}


void login::on_pushButton_signup_clicked()
{
    signup_Window *sp=new signup_Window();
    this->hide();
    sp->show();

}

