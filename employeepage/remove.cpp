#include "remove.h"
#include "ui_remove.h"

Remove::Remove(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Remove)
{
    ui->setupUi(this);
}

Remove::~Remove()
{
    delete ui;
}

bool Remove::emailcheck()
{
    QString email=ui->remline_1->text();
    std::string emailtext = email.toStdString();
    std::regex pattern(R"(^[\w-.]+@([\w-]+.)+[\w-]{2,4}$)");
    return regex_match(emailtext,pattern);

}

int Remove::checkrow()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS2");
    db2.setDatabaseName("C:/Users/HP/Desktop/admins.db");
    db2.open();

    QString querya = "SELECT * FROM admin";
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

void Remove::on_rembutton_2_clicked()
{
    close();
}


void Remove::on_rembutton_1_clicked()
{

    if(!ui->remradio_1->isChecked()&&!ui->remradio_2->isChecked())
    {
        QMessageBox::information(this, "No_Radio_Selected", "Please select a user type to remove.");
    }
    else
    {

        if(ui->remradio_1->isChecked())
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
        else if(ui->remradio_2->isChecked())
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

int Remove::emailcheck2()
{
    QString email=ui->remline_1->text();

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

void Remove::delemployee()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS2");
    db2.setDatabaseName("C:/Users/HP/Desktop/employees.db");
    db2.open();

    QString querya = "DELETE FROM employee WHERE Email = :email";
    QSqlQuery query(db2);
    query.prepare(querya);
    QString email=ui->remline_1->text();
    query.bindValue(":email", email);




    query.exec();

    db2.close();
}

void Remove::deladmin()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","ADMINS2");
    db2.setDatabaseName("C:/Users/HP/Desktop/admins.db");
    db2.open();

    QString querya = "DELETE FROM admin WHERE Email = :email";
    QSqlQuery query(db2);
    query.prepare(querya);
    QString email=ui->remline_1->text();
    query.bindValue(":email", email);




    query.exec();

    db2.close();
}


