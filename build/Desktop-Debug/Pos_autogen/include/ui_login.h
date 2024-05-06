/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *main_label;
    QTextBrowser *textBrowser_welcome;
    QLabel *label_status;
    QGroupBox *groupBox;
    QPushButton *pushButton_signup;
    QPushButton *pushButton_login;
    QLabel *label_password;
    QLabel *label_username;
    QRadioButton *radioButton_employee;
    QRadioButton *radioButton_admin;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_username;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1311, 591);
        main_label = new QLabel(login);
        main_label->setObjectName("main_label");
        main_label->setGeometry(QRect(0, -10, 1311, 601));
        main_label->setStyleSheet(QString::fromUtf8("background-image: url(\"/home/boi/Projects/C++/Uni/Pos/img/bg\");"));
        main_label->setPixmap(QPixmap(QString::fromUtf8(":/bg_image/pos_bg.png")));
        main_label->setScaledContents(true);
        textBrowser_welcome = new QTextBrowser(login);
        textBrowser_welcome->setObjectName("textBrowser_welcome");
        textBrowser_welcome->setGeometry(QRect(480, 10, 351, 91));
        textBrowser_welcome->setStyleSheet(QString::fromUtf8("background-color: rgb(176, 240, 241);"));
        textBrowser_welcome->setFrameShape(QFrame::Shape::NoFrame);
        label_status = new QLabel(login);
        label_status->setObjectName("label_status");
        label_status->setGeometry(QRect(20, 560, 251, 20));
        label_status->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox = new QGroupBox(login);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(480, 110, 361, 441));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border:none;\n"
"border-top-left-radius :20px;\n"
"border-top-right-radius : 20px; \n"
"border-bottom-left-radius : 20px; \n"
"border-bottom-right-radius : 20px"));
        pushButton_signup = new QPushButton(groupBox);
        pushButton_signup->setObjectName("pushButton_signup");
        pushButton_signup->setGeometry(QRect(110, 350, 131, 31));
        pushButton_signup->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"font: 700 11pt \"Segoe UI\";\n"
"border: none;\n"
"border-top-left-radius :10px;\n"
"border-top-right-radius : 10px; \n"
"border-bottom-left-radius : 10px; \n"
"border-bottom-right-radius : 10px"));
        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(110, 290, 131, 41));
        pushButton_login->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 148, 148);\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-top-left-radius :10px;\n"
"border-top-right-radius : 10px; \n"
"border-bottom-left-radius : 10px; \n"
"border-bottom-right-radius : 10px"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(50, 200, 269, 21));
        label_password->setStyleSheet(QString::fromUtf8("font: 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"color: rgb(88, 88, 88);"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(50, 100, 269, 21));
        label_username->setStyleSheet(QString::fromUtf8("font: 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"color: rgb(88, 88, 88);"));
        radioButton_employee = new QRadioButton(groupBox);
        radioButton_employee->setObjectName("radioButton_employee");
        radioButton_employee->setGeometry(QRect(30, 20, 131, 26));
        radioButton_employee->setStyleSheet(QString::fromUtf8("color: rgb(0, 95, 95);\n"
"font: 700 12pt \"Segoe UI\";"));
        radioButton_admin = new QRadioButton(groupBox);
        radioButton_admin->setObjectName("radioButton_admin");
        radioButton_admin->setGeometry(QRect(210, 20, 131, 26));
        radioButton_admin->setStyleSheet(QString::fromUtf8("color: rgb(0, 95, 95);\n"
"font: 700 12pt \"Segoe UI\";"));
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(50, 230, 269, 38));
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 13pt \"Segoe UI\";\n"
"background-color: rgb(215, 255, 254);"));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(50, 130, 269, 38));
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 13pt \"Segoe UI\";\n"
"background-color: rgb(215, 255, 254);"));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        main_label->setText(QString());
        textBrowser_welcome->setHtml(QCoreApplication::translate("login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:36pt; font-weight:700; color:#008a8a;\">Welcome</span></p></body></html>", nullptr));
        label_status->setText(QCoreApplication::translate("login", "[+]DB status", nullptr));
        groupBox->setTitle(QString());
        pushButton_signup->setText(QCoreApplication::translate("login", "Sign up", nullptr));
        pushButton_login->setText(QCoreApplication::translate("login", "Login", nullptr));
        label_password->setText(QCoreApplication::translate("login", "Password", nullptr));
        label_username->setText(QCoreApplication::translate("login", "Username", nullptr));
        radioButton_employee->setText(QCoreApplication::translate("login", "Employee", nullptr));
        radioButton_admin->setText(QCoreApplication::translate("login", "Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
