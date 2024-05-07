#include "removeuser.h"
#include "qsqlerror.h"
#include <regex>

RemoveUser::RemoveUser(QWidget *parent) : QDialog(parent)
{
    setupUi();
}

void RemoveUser::setupUi()
{
    resize(700, 460);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setContentsMargins(50, 50, 50, 50);

    QLabel *label_9 = new QLabel("Enter email of employee to delete:");
    QFont font;
    font.setFamily("Arial Rounded Bold");
    font.setPointSize(12);
    label_9->setFont(font);
    label_9->setFixedHeight(30);
    label_9->setAlignment(Qt::AlignCenter);

    QHBoxLayout *radioLayout = new QHBoxLayout;
    remradio_1 = new QRadioButton("Delete admin", this);
    remradio_2 = new QRadioButton("Delete employee", this);
    remradio_1->setFixedHeight(30);
    remradio_2->setFixedHeight(30);
    radioLayout->addWidget(remradio_1);
    radioLayout->addWidget(remradio_2);
    radioLayout->setAlignment(Qt::AlignCenter);

    QLabel *label_11 = new QLabel("Email:");
    label_11->setFont(font);
    label_11->setFixedHeight(30);
    label_11->setAlignment(Qt::AlignLeft);

    remline_1 = new QLineEdit;
    remline_1->setObjectName("remline_1");
    remline_1->setStyleSheet("background-color: #FFFFFF;");
    remline_1->setFixedHeight(30);
    remline_1->setFixedWidth(500);
    remline_1->setAlignment(Qt::AlignCenter);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    rembutton_2 = new QPushButton("Cancel");
    rembutton_1 = new QPushButton("Okay");
    rembutton_2->setFont(font);
    rembutton_1->setFont(font);

    rembutton_2->setFixedHeight(40);
    rembutton_1->setFixedHeight(40);

    buttonLayout->addWidget(rembutton_2);
    buttonLayout->addSpacing(20);
    buttonLayout->addWidget(rembutton_1);

    buttonLayout->setAlignment(Qt::AlignCenter);

    connect(rembutton_1, &QPushButton::clicked, this, &RemoveUser::on_rembutton_1_clicked);
    connect(rembutton_2, &QPushButton::clicked, this, &RemoveUser::on_rembutton_2_clicked);

    mainLayout->addWidget(label_9);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(radioLayout);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(label_11);
    mainLayout->addWidget(remline_1);
    mainLayout->addSpacing(30);
    mainLayout->addLayout(buttonLayout);

    rembutton_1->setStyleSheet("QPushButton { border: 2px solid #333; border-radius: 20px; color: #333; background-color: #f0f0f0; }");
    rembutton_2->setStyleSheet("QPushButton { border: 2px solid #333; border-radius: 20px; color: #333; background-color: #f0f0f0; }");

    setLayout(mainLayout);
}

bool RemoveUser::emailcheck()
{
    QString email = remline_1->text();
    std::string emailtext = email.toStdString();
    std::regex pattern(R"(^[\w\-\.]+@([\w\-]+\.)+[\w\-]{2,4}$)");
    return regex_match(emailtext,pattern);
}

int RemoveUser::checkrow()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS2");
    db2.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/SQL/admin.db");
    if (!db2.open()) {
        qDebug() << "Error: Failed to open database:" << db2.lastError().text();
        return -1; // Return -1 to indicate error opening the database
    }

    QSqlQuery query(db2);
    QString querya = "SELECT * FROM Admins";
    if (!query.prepare(querya)) {
        qDebug() << "Error preparing query:" << query.lastError().text();
        db2.close(); // Close the database before returning
        return -1; // Return -1 to indicate error preparing the query
    }

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        db2.close(); // Close the database before returning
        return -1; // Return -1 to indicate error executing the query
    }

    int row = 0;
    while (query.next()) {
        row++;
    }

    qDebug() << "Number of rows in the table:" << row;

    db2.close();

    if (row > 1) {
        return 1;
    }
    return 0;
}

void RemoveUser::on_rembutton_2_clicked()
{
    close();
}


void RemoveUser::on_rembutton_1_clicked()
{

    if(!remradio_1->isChecked()&&!remradio_2->isChecked())
    {
        QMessageBox::information(this, "No_Radio_Selected", "Please select a user type to remove.");
    }
    else
    {
        if(remradio_1->isChecked())
        {
            if(checkrow()==0)
            {
                QMessageBox::information(this, "Cannot_Delete", "Please keep at least 1 admin entry in database.");
                return;
            }

            if(emailcheck2()==1)
            {
                deladmin();
                close();
                QMessageBox::information(this, "Upd", "Please update tables.");
            }
        }
        else if(remradio_2->isChecked())
        {
            if(emailcheck2()==1)
            {
                delemployee();
                close();
                QMessageBox::information(this, "Upd", "Please update tables.");
            }
        }
    }
}

int RemoveUser::emailcheck2()
{
    QString email = remline_1->text();

    if(email.length()<8)
    {
        QMessageBox::information(this, "Email_Len", "Email must be at least 8 characters!");
        return 0;
    }
    else if(emailcheck()==false)
    {
        QMessageBox::information(this, "Email_Format", "Incorrect email format!");
        return 0;
    }
    return 1;
}

void RemoveUser::delemployee()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","EMPLOYEES2");
    db2.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/SQL/employees_2.db");
    db2.open();

    QString querya = "DELETE FROM employees WHERE email = :email";
    QSqlQuery query(db2);
    query.prepare(querya);
    QString email = remline_1->text();
    query.bindValue(":email", email);

    query.exec();
    db2.close();
}

void RemoveUser::deladmin()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/SQL/admin.db");
    db2.open();

    QString querya = "DELETE FROM Admins WHERE email = :email";
    QSqlQuery query(db2);
    query.prepare(querya);
    QString email = remline_1->text();
    query.bindValue(":email", email);

    query.exec();

    db2.close();
}
