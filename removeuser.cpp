#include "removeuser.h"
#include <regex>

RemoveUser::RemoveUser(QWidget *parent) : QDialog(parent)
{
    setupUi();
}

void RemoveUser::setupUi()
{
    resize(688, 464);
    frame = new QFrame(Remove);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setGeometry(QRect(90, 70, 491, 271));
    frame->setStyleSheet(QString::fromUtf8("background-color:#D3D3D3\n"));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);

    QVBoxLayout *mainLayout = new QVBoxLayout(frame);

    QLabel *label_9 = new QLabel("Enter email of employee to delete:", frame);
    QFont font;
    font.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
    font.setPointSize(12);
    label_9->setFont(font);

    QLabel *label_11 = new QLabel("Email:", frame);
    label_11->setFont(font);

    remline_1 = new QLineEdit(frame);
    remline_1->setObjectName(QString::fromUtf8("remline_1"));
    remline_1->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));

    QHBoxLayout *radioLayout = new QHBoxLayout;
    remradio_1 = new QRadioButton("Delete admin", frame);
    remradio_2 = new QRadioButton("Delete employee", frame);
    radioLayout->addWidget(remradio_1);
    radioLayout->addWidget(remradio_2);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    rembutton_2 = new QPushButton("Cancel", frame);
    rembutton_1 = new QPushButton("Ok", frame);
    rembutton_2->setFont(font);
    rembutton_1->setFont(font);
    rembutton_2->setStyleSheet(QString::fromUtf8("border: 2px solid red; \n"
        "border-radius: 20px;\n"
        "color: #FFFFFF;\n"
        "background-color:#A9A9A9"));
    rembutton_1->setStyleSheet(QString::fromUtf8("border: 2px solid red; \n"
        "border-radius: 20px;\n"
        "color: #FFFFFF;\n"
        "background-color:#A9A9A9"));
    buttonLayout->addWidget(rembutton_2);
    buttonLayout->addWidget(rembutton_1);

    mainLayout->addWidget(label_9);
    mainLayout->addWidget(label_11);
    mainLayout->addWidget(remline_1);
    mainLayout->addLayout(radioLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

bool RemoveUser::emailcheck()
{
    QString email = remline_1->text();
    std::string emailtext = email.toStdString();
    std::regex pattern(R"(^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");
    return regex_match(emailtext,pattern);

}

int RemoveUser::checkrow()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS2");
    db2.setDatabaseName("C:/Users/HP/Desktop/admin.db");
    db2.open();

    QString querya = "SELECT * FROM Admins";
    QSqlQuery query(db2);

    query.prepare(querya);

    query.exec();

    int row = 0;
    while (query.next()) {
        row++;
    }

    qDebug() << "Number of rows in the table:" << row;

    db2.close();

    if(row>1)
    {
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
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS2");
    db2.setDatabaseName("home/boi/Projects/C++/Uni/Pos/SQL/employees_2.db");
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
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS2");
    db2.setDatabaseName("home/boi/Projects/C++/Uni/Pos/SQL/admin.db");
    db2.open();

    QString querya = "DELETE FROM Admins WHERE email = :email";
    QSqlQuery query(db2);
    query.prepare(querya);
    QString email = remline_1->text();
    query.bindValue(":email", email);

    query.exec();

    db2.close();
}
