#include "login.h"
#include "ui_login.h"
#include "signup_window.h"
#include<QMessageBox>


login::login(QWidget *parent) : QWidget(parent) , ui(new Ui::login)
{
    ui->setupUi(this);

    QSqlDatabase empDB=QSqlDatabase::addDatabase("QSQLITE");
    empDB.setDatabaseName("C:/Users/Lenovo/Downloads/SQLiteDatabaseBrowserPortable/employees_2.db");

    if(!empDB.open())
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
    empDB.close();
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

    //verify data

    if(ui->radioButton_employee->isChecked())
    {

     QSqlDatabase empDB=QSqlDatabase::addDatabase("QSQLITE");
    empDB.setDatabaseName("C:/Users/Lenovo/Downloads/SQLiteDatabaseBrowserPortable/employees_2.db");

    if(!empDB.open())
    {
        QMessageBox::warning(this,"error!","failed to open db");
    }
    else
        QMessageBox::information(this,"db status","db opened successfully");

    QSqlQuery qry;
    if(qry.exec("SELECT username, passwordd FROM employees WHERE username='" + username + "' AND passwordd='" + password+"'"))
    {
        if(qry.next()) {
            ui->label_status->setText("[+]Valid Username and Password");
            QString msg = "Welcome, " + qry.value(0).toString();
            QMessageBox::information(this, "Login Successful", msg);
            emit loginSuccessful(username);
        }
        else {
            ui->label_status->setText("[-]Wrong Username or Password.");
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        }
    }
    else {
        ui->label_status->setText("[-]Database Error.");
        QMessageBox::critical(this, "Error", "Database error occurred." + qry.lastError().text());
    }

   }


   if(ui->radioButton_admin->isChecked())
   {
       QSqlDatabase admDB=QSqlDatabase::addDatabase("QSQLITE");
       admDB.setDatabaseName("C:/Users/Lenovo/Downloads/SQLiteDatabaseBrowserPortable/admin.db");

       if(!admDB.open())
       {
           QMessageBox::warning(this,"error!","failed to open db");
       }
       else
           QMessageBox::information(this,"db status","db opened successfully");

       QSqlQuery qry;
       if(qry.exec("SELECT username, passwordd FROM Admins WHERE username='" + username + "' AND passwordd='" + password+"'"))
       {
           if(qry.next()) {
               ui->label_status->setText("[+]Valid Username and Password");
               QString msg = "Welcome, " + qry.value(0).toString();
               QMessageBox::information(this, "Login Successful", msg);
               emit loginSuccessful(username);
           }
           else {
               ui->label_status->setText("[-]Wrong Username or Password.");
               QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
           }
       }
       else {
           ui->label_status->setText("[-]Database Error.");
           QMessageBox::critical(this, "Error", "Database error occurred." + qry.lastError().text());
       }

   }


}


void login::on_pushButton_signup_clicked()
{
    signup_Window *sp=new signup_Window();
    this->hide();
    sp->show();

}