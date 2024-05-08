#include "../../include/User/dialog.h"
#include <regex>

Dialog::Dialog(QWidget *parent): QDialog(parent){
    setupUi();
}

int Dialog::checkreptemp()
{
    QString email = lineEdit_4->text();

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("C:/Users/HP/Desktop/employees_2.db");

    if (!db2.open()) {
        qDebug() << "Error: Failed to open database:" << db2.lastError().text();
        return 0;
    }

    QString checkQuery = "SELECT * FROM employees WHERE email = ?";
    QSqlQuery check(db2);
    check.prepare(checkQuery);
    check.addBindValue(email);
    if (!check.exec()) {
        qDebug() << "Error executing query:" << check.lastError().text();
        return 0;
    }

    int count = 0;
    while (check.next()) {
        count++;
    }
    qDebug() << "Number of matching emails:" << count;

    if (count > 0) {
        QMessageBox::information(this, "Repeat_Email", "Please enter a unique email id.");
        qDebug() << "Email already exists";
        return 0;
    }

    qDebug() << "Email is unique";
    return 1;
}

int Dialog::checkreptadmin()
{
    QString email = lineEdit_4->text();

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("C:/Users/HP/Desktop/admin.db");

    if (!db2.open()) {
        qDebug() << "Error: Failed to open database:" << db2.lastError().text();
        return 0;
    }

    QString checkQuery = "SELECT * FROM Admins WHERE email = ?";
    QSqlQuery check(db2);
    check.prepare(checkQuery);
    check.addBindValue(email);
    if (!check.exec()) {
        qDebug() << "Error executing query:" << check.lastError().text();
        return 0;
    }

    int count = 0;
    while (check.next()) {
        count++;
    }
    qDebug() << "Number of matching emails:" << count;

    if (count > 0) {
        QMessageBox::information(this, "Repeat_Email", "Please enter a unique email id.");
        qDebug() << "Email already exists";
        return 0;
    }

    qDebug() << "Email is unique";
    return 1;
}

void Dialog::setupUi()
{
    resize(659, 488);
    frame = new QFrame(this);
    frame->setObjectName(QStringLiteral("frame"));
    frame->setGeometry(QRect(110, 40, 491, 431));
    frame->setStyleSheet(QString::fromUtf8("background-color:#D3D3D3\n"));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);

    lineEdit_3 = new QLineEdit(frame);
    lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
    lineEdit_3->setGeometry(QRect(20, 90, 451, 31));
    lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));

    lineEdit_4 = new QLineEdit(frame);
    lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
    lineEdit_4->setGeometry(QRect(20, 160, 451, 31));
    lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));

    lineEdit_5 = new QLineEdit(frame);
    lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
    lineEdit_5->setGeometry(QRect(20, 230, 451, 31));
    lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));

    label_9 = new QLabel(frame);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(150, 0, 191, 21));
    QFont font;
    font.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
    font.setPointSize(12);
    label_9->setFont(font);

    label_10 = new QLabel(frame);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(20, 65, 191, 21));
    label_10->setFont(font);

    label_11 = new QLabel(frame);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setGeometry(QRect(20, 135, 191, 21));
    label_11->setFont(font);

    label_12 = new QLabel(frame);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(20, 205, 191, 21));
    label_12->setFont(font);

    lineEdit_6 = new QLineEdit(frame);
    lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
    lineEdit_6->setGeometry(QRect(20, 300, 451, 31));
    lineEdit_6->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));

    label_13 = new QLabel(frame);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setGeometry(QRect(20, 275, 191, 21));
    label_13->setFont(font);

    pushButton_7 = new QPushButton(frame);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setGeometry(QRect(80, 370, 91, 41));
    pushButton_7->setFont(font);
    pushButton_7->setStyleSheet(QString::fromUtf8("border: 2px solid #28A4A6; \n"
                                                  "border-radius: 20px;\n"
                                                  "color: #FFFFFF;\n"
                                                  "background-color:#A9A9A9"));

    radioButton = new QRadioButton(frame);
    radioButton->setObjectName(QString::fromUtf8("radioButton"));
    radioButton->setGeometry(QRect(100, 40, 89, 20));

    radioButton_2 = new QRadioButton(frame);
    radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
    radioButton_2->setGeometry(QRect(260, 40, 111, 20));

    pushButton_8 = new QPushButton(frame);
    pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
    pushButton_8->setGeometry(QRect(330, 370, 91, 41));
    pushButton_8->setFont(font);
    pushButton_8->setStyleSheet(QString::fromUtf8("border: 2px solid #28A4A6; \n"
                                                  "border-radius: 20px;\n"
                                                  "color: #FFFFFF;\n"
                                                  "background-color:#A9A9A9"));

    label_9->setText("Enter new user details:");
    label_10->setText("Username:");
    label_11->setText("Email:");
    label_12->setText("Shift:");
    label_13->setText("Password:");

    pushButton_7->setText("Cancel");
    pushButton_8->setText("Ok");

    radioButton->setText("New Admin");
    radioButton_2->setText("New Employee");

    connect(pushButton_8, &QPushButton::clicked, this, &Dialog::on_pushButton_8_clicked);
    connect(pushButton_7, &QPushButton::clicked, this, &Dialog::on_pushButton_7_clicked);
}

void Dialog::add_db_admin()
{
    QString name  = lineEdit_3->text();
    QString email = lineEdit_4->text();
    QString shift = lineEdit_5->text();
    QString pass  = lineEdit_6->text();

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS");
    db2.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/admin.db");
    if (!db2.open())
    {
        qDebug() << "Error: Failed to open database:" << db2.lastError().text();
    }

    QString querya = "INSERT INTO Admins (email,username, passwordd) VALUES (?, ?, ?)";
    QSqlQuery query(db2);
    query.prepare(querya);
    query.addBindValue(email);
    query.addBindValue(name);
    query.addBindValue(pass);;

    // Do something with the retrieved data
    qDebug() << querya;

    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
    db2.close();
}

void Dialog::add_db_employee()
{
    QString name  = lineEdit_3->text();
    QString email = lineEdit_4->text();
    QString shift = lineEdit_5->text();
    QString pass  = lineEdit_6->text();

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","EMPLOYEES");
    db2.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/employees_2.db");
    if (!db2.open())
    {
        qDebug() << "Error: Failed to open database:" << db2.lastError().text();
    }

    QString querya = "INSERT INTO employees (email,username,passwordd,shift) VALUES (?, ?, ?, ?)";
    QSqlQuery query(db2);
    query.prepare(querya);
    query.addBindValue(email);
    query.addBindValue(name);
    query.addBindValue(pass);
    query.addBindValue(shift);

    // Do something with the retrieved data
    qDebug() << querya;

    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
    db2.close();
}

void Dialog::on_pushButton_8_clicked()
{
    if(!radioButton->isChecked()&&!radioButton_2->isChecked())
    {
        QMessageBox::information(this, "No_Radio_Selected", "Please select a user type to add.");
    }
    else
    {
        if(radioButton->isChecked()&&checkreptadmin()==1)
        {
            if(checklena()==1)
            {
                add_db_admin();
                close();
                QMessageBox::information(this, "Upd", "Please update tables.");
            }

        }
        else if(radioButton_2->isChecked()&&checkreptemp()==1)
        {

            if(checklene()==1)
            {
                add_db_employee();
                close();
                QMessageBox::information(this, "Upd", "Please update tables.");
            }
        }
    }
}

int Dialog::checklene()
{
    QString name  = lineEdit_3->text();
    QString email = lineEdit_4->text();
    QString shift = lineEdit_5->text();
    QString pass  = lineEdit_6->text();

    if(name.length()<6)
    {
        QMessageBox::information(this, "Name_Len", "Name must be at least 6 characters!");
        return 0;
    }
    else if(email.length()<8)
    {
        QMessageBox::information(this, "Email_Len", "Email must be at least 8 characters!");
        return 0;
    }
    else if(shift.length()<5)
    {
        QMessageBox::information(this, "Shift_Len", "Shift must be at least 5 characters!");
        return 0;
    }
    else if(pass.length()<8)
    {
        QMessageBox::information(this, "Pass_Len", "Password must be at least 8 characters!");
        return 0;
    }
    else if(emailcheck()==false)
    {
        QMessageBox::information(this, "Email_Format", "Incorrect email format!");
        return 0;
    }

    return 1;
}

int Dialog::checklena()
{
    QString name  = lineEdit_3->text();
    QString email = lineEdit_4->text();
    QString pass  = lineEdit_6->text();

    if(name.length()<6)
    {
        QMessageBox::information(this, "Name_Len", "Name must be at least 6 characters!");
        return 0;
    }
    else if(email.length()<8)
    {
        QMessageBox::information(this, "Email_Len", "Email must be at least 8 characters!");
        return 0;
    }
    else if(pass.length()<8)
    {
        QMessageBox::information(this, "Pass_Len", "Password must be at least 8 characters!");
        return 0;
    }
    else if(emailcheck()==false)
    {
        QMessageBox::information(this, "Email_Format", "Incorrect email format!");
        return 0;
    }

    return 1;
}

bool Dialog::emailcheck()
{
    QString email = lineEdit_4->text();
    std::string emailtext = email.toStdString();
    std::regex pattern(R"(^[\w\-\.]+@([\w\-]+\.)+[\w\-]{2,4}$)");
    return regex_match(emailtext,pattern);
}

void Dialog::on_pushButton_7_clicked()
{
    close();
}
