#include "feedback.h"
#include "ui_feedback.h"
#include<string>
#include<cstring>
#include<QMessageBox>
#include<regex>
#include<QString>
using namespace std;

feedback::feedback(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::feedback)
{
    ui->setupUi(this);
}

feedback::~feedback()
{
    delete ui;
}

bool isvalidEmail(QString input)  // function to verify email
{
    regex pattern(R"(^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");
    string inputStr = input.toStdString();
    return regex_match(inputStr, pattern);
}

bool isValidPhoneNumber(QString phoneNumber)
{
    // Regex to check valid phone number.
    const regex pattern(R"(^[+]{0,1}[0-9]{1,3}[-\s\.]{0,1}\({0,1}[0-9]{1,4}\){0,1}[-\s\.]{0,1}[0-9]{1,4}[-\s\.]{0,1}[0-9]{1,4}$)");

    return regex_match(phoneNumber.toStdString(), pattern);
}


void feedback::on_pushButton_clicked()
{
    QString email = ui->lineEdit_email->text();

    // Validate email format using regex
    if (!isvalidEmail(email)) {
        QMessageBox::warning(this, "Feedback", "Invalid email address. Please enter a valid email.");
        return;
    }

    QString phone=ui->lineEdit_phone->text();

    if (!isValidPhoneNumber(phone)) {
        QMessageBox::warning(this, "Feedback", "Invalid phone number. Please enter a valid phone number.");
        return;
    }
}

