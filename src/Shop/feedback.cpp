#include "../../include/Shop/feedback.h"

#include<QMessageBox>
#include<QString>
#include <regex>
using namespace std;

feedback::feedback(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color: #FFFFFF;");
    setFixedSize(600,800);

    setupUi();
}

void feedback::setupUi()
{
    QFont labelFont("Arial Rounded", 12, QFont::Bold);

    name_label = new QLabel("Name");
    email_label = new QLabel("Email");
    phone_label = new QLabel("Phone Number");
    QLabel* rate_label = new QLabel("Please Rate our Service on a scale of 1 - 5");
    QLabel* additional_label = new QLabel("Let us know if you have any additional feedback!");

    name_label->setFont(labelFont);
    email_label->setFont(labelFont);
    phone_label->setFont(labelFont);
    rate_label->setFont(labelFont);
    additional_label->setFont(labelFont);

    name_label->setStyleSheet("color: #278880;");
    email_label->setStyleSheet("color: #278880;");
    phone_label->setStyleSheet("color: #278880;");
    rate_label->setStyleSheet("color: #278880;");
    additional_label->setStyleSheet("color: #278880;");

    name_label->setMargin(10);
    email_label->setMargin(10);
    phone_label->setMargin(0);

    name_lineEdit = new QLineEdit;
    email_lineEdit = new QLineEdit;
    phone_LineEdit = new QLineEdit;
    addFeed = new QTextEdit;

    name_lineEdit->setFixedSize(230, 40);
    email_lineEdit->setFixedSize(230, 40);
    phone_LineEdit->setFixedSize(230, 40);
    addFeed->setFixedSize(431, 91);

    name_lineEdit->setStyleSheet("border-radius: 20px; padding: 10px; border: 3px solid #333;");
    email_lineEdit->setStyleSheet("border-radius: 20px; padding: 10px; border: 3px solid #333;");
    phone_LineEdit->setStyleSheet("border-radius: 20px; padding: 10px; border: 3px solid #333;");
    addFeed->setStyleSheet("border-radius: 20px; padding: 10px; border: 3px solid #333;");

    mainLayout = new QVBoxLayout();
    QHBoxLayout* nameemail = new QHBoxLayout();
    nameemail->addWidget(name_label, 0, Qt::AlignCenter); // Aligning center
    nameemail->addWidget(email_label, 0, Qt::AlignCenter); // Aligning center
    mainLayout->addLayout(nameemail);

    QHBoxLayout* nameemaillabels = new QHBoxLayout();
    nameemaillabels->addWidget(name_lineEdit);
    nameemaillabels->addWidget(email_lineEdit);
    mainLayout->addLayout(nameemaillabels);

    mainLayout->addWidget(phone_label,  0, Qt::AlignCenter);
    mainLayout->addWidget(phone_LineEdit, 0, Qt::AlignCenter);
    mainLayout->addWidget(rate_label);

    QButtonGroup* ratingGroup = new QButtonGroup();
    rating = new QRadioButton*[5];
    QHBoxLayout* buttons = new QHBoxLayout();
    for (int i = 0; i < 5; ++i) {
        rating[i] = new QRadioButton(QString::number(i + 1));
        ratingGroup->addButton(rating[i]);
        buttons->addWidget(rating[i]);
    }

    mainLayout->addLayout(buttons);

    mainLayout->addWidget(additional_label);
    mainLayout->addWidget(addFeed, 0, Qt::AlignCenter);

    pushButton = new QPushButton("Submit Feedback");
    connect(pushButton, &QPushButton::clicked, this, &feedback::on_pushButton_clicked);
    pushButton->setStyleSheet("QPushButton { background-color: #00CED1; color: rgb(255, 255, 255);font-weight: bold; border-radius: 20px; padding: 10px; }");
    pushButton->setFixedSize(211, 41);
    mainLayout->addWidget(pushButton, 0, Qt::AlignCenter);
    setLayout(mainLayout);
}

bool isvalidEmail(QString input)  // function to verify email
{
    regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    string inputStr = input.toStdString();
    return regex_match(inputStr, pattern);
}

bool isValidPhoneNumber(QString phoneNumber)
{
    const regex pattern(R"(^[+]{0,1}[0-9]{1,3}[-\s\.]{0,1}\({0,1}[0-9]{1,4}\){0,1}[-\s\.]{0,1}[0-9]{1,4}[-\s\.]{0,1}[0-9]{1,4}$)");

    return regex_match(phoneNumber.toStdString(), pattern);
}

void feedback::on_pushButton_clicked()
{
    QString email = email_lineEdit->text();

    if (!isvalidEmail(email)) {
        QMessageBox::warning(this, "Feedback", "Invalid email address. Please enter a valid email.");
        return;
    }

    QString phone = phone_LineEdit->text();

    if (!isValidPhoneNumber(phone)) {
        QMessageBox::warning(this, "Feedback", "Invalid phone number. Please enter a valid phone number.");
        return;
    }

    QMessageBox::information(this, "feedback", "Thank you for your feedback!");
    close();
}
