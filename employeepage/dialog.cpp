#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::add_db_admin()
{
    QString name= ui->lineEdit_3->text();
    QString email=ui->lineEdit_4->text();
    QString shift=ui->lineEdit_5->text();
    QString pass=ui->lineEdit_6->text();

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS");
    db2.setDatabaseName("C:/Users/HP/Desktop/admins.db");
    if (!db2.open())
    {
        qDebug() << "Error: Failed to open database:" << db2.lastError().text();
    }

    QString querya = "INSERT INTO admin (Username, Email, Password) VALUES (?, ?, ?)";
    QSqlQuery query(db2);
    query.prepare(querya);
    query.addBindValue(name);
    query.addBindValue(email);
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
    QString name= ui->lineEdit_3->text();
    QString email=ui->lineEdit_4->text();
    QString shift=ui->lineEdit_5->text();
    QString pass=ui->lineEdit_6->text();

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","EMPLOYEES");
    db2.setDatabaseName("C:/Users/HP/Desktop/employees.db");
    if (!db2.open())
    {
        qDebug() << "Error: Failed to open database:" << db2.lastError().text();
    }

    QString querya = "INSERT INTO employee (Username, Email, Password, Shift) VALUES (?, ?, ?, ?)";
    QSqlQuery query(db2);
    query.prepare(querya);
    query.addBindValue(name);
    query.addBindValue(email);
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
    if(!ui->radioButton->isChecked()&&!ui->radioButton_2->isChecked())
    {
        QMessageBox::information(this, "No_Radio_Selected", "Please select a user type to add.");
    }
    else
    {

    if(ui->radioButton->isChecked())
    {
        if(checklena()==1)
        {
            add_db_admin();
            close();
            QMessageBox::information(this, "Upd", "Please update tables.");
        }

    }
    else if(ui->radioButton_2->isChecked())
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
    QString name= ui->lineEdit_3->text();
    QString email=ui->lineEdit_4->text();
    QString shift=ui->lineEdit_5->text();
    QString pass=ui->lineEdit_6->text();

    if(name.length()<8)
    {
        QMessageBox::information(this, "Name_Len", "Name must be at least 8 characters!");
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
    QString name= ui->lineEdit_3->text();
    QString email=ui->lineEdit_4->text();
    QString pass=ui->lineEdit_6->text();

    if(name.length()<8)
    {
        QMessageBox::information(this, "Name_Len", "Name must be at least 8 characters!");
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
    QString email=ui->lineEdit_4->text();
    std::string emailtext = email.toStdString();
    std::regex pattern(R"(^[\w-.]+@([\w-]+.)+[\w-]{2,4}$)");
    return regex_match(emailtext,pattern);

}

void Dialog::on_pushButton_7_clicked()
{
    close();
}

