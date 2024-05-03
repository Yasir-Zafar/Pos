#include "sidebar2.h"
#include "ui_sidebar2.h"

sidebar2::sidebar2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sidebar2)
{
    ui->setupUi(this);

    //Read and show employees and admin details
    setadmins();
    setemployees();

}

sidebar2::~sidebar2()
{
    delete ui;
}


void sidebar2::setadmins()
{
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, 330);
    ui->tableWidget->setColumnWidth(1, 330);
    ui->tableWidget->verticalHeader()->setVisible(false);
    //ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QStringList header;
    header << "Username" << "Email";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    QFont font("Arial", 12);
    ui->tableWidget->setFont(font);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/HP/Desktop/admins.db");

    QSqlQuery query;
    query.exec("SELECT * FROM admin");


    if (!db.open())
    {
        qDebug() << "Error: Failed to open database:" << db.lastError().text();
        // Handle the error appropriately
    } else
    {
        qDebug() << "Database opened successfully!";
        // Proceed with database operations
        QSqlQuery query;

        if (!query.exec("SELECT * FROM admin"))
        {
            qDebug() << "Error executing query:" << query.lastError().text();
            // Handle the error appropriately
        }
        else
        {
            // Process the query result
            while (query.next()) {
                // Retrieve data from the query result
                QString username = query.value(0).toString();
                QString email = query.value(1).toString();


                int newRow = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(newRow);
                ui->tableWidget->setItem(newRow, 0, new QTableWidgetItem(username));
                ui->tableWidget->setItem(newRow, 1, new QTableWidgetItem(email));




                // Do something with the retrieved data
                qDebug() << "Username:" << username << ", Email:" << email;
            }
        }
    }



    // Close the database connection
    db.close();
}

void sidebar2::setemployees()
{
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setColumnWidth(0, 280);
    ui->tableWidget_2->setColumnWidth(1, 280);
    ui->tableWidget_2->setColumnWidth(1, 280);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    //ui->tableWidget_2->horizontalHeader()->setVisible(false);
    ui->tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QStringList header;
    header << "Username" << "Email"<<"Timings";
    ui->tableWidget_2->setHorizontalHeaderLabels(header);

    QFont font("Arial", 12);
    ui->tableWidget_2->setFont(font);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/HP/Desktop/employees.db");

    QSqlQuery query;
    query.exec("SELECT * FROM employee");


    if (!db.open())
    {
        qDebug() << "Error: Failed to open database:" << db.lastError().text();
        // Handle the error appropriately
    } else
    {
        qDebug() << "Database opened successfully!";
        // Proceed with database operations
        QSqlQuery query;

        if (!query.exec("SELECT * FROM employee"))
        {
            qDebug() << "Error executing query:" << query.lastError().text();
            // Handle the error appropriately
        }
        else
        {
            // Process the query result
            while (query.next()) {
                // Retrieve data from the query result
                QString username = query.value(0).toString();
                QString email = query.value(1).toString();
                QString shift = query.value(3).toString();


                int newRow = ui->tableWidget_2->rowCount();
                ui->tableWidget_2->insertRow(newRow);
                ui->tableWidget_2->setItem(newRow, 0, new QTableWidgetItem(username));
                ui->tableWidget_2->setItem(newRow, 1, new QTableWidgetItem(email));
                ui->tableWidget_2->setItem(newRow, 2, new QTableWidgetItem(shift));
            }
        }
    }



    // Close the database connection
    db.close();
}

sidebar2& sidebar2::getInstance()
{
    static sidebar2 instance;
    return instance;
}

void sidebar2::resettables()
{
    setadmins();
    setemployees();
}

void sidebar2::on_pushButton_5_clicked()
{
    Dialog *diag = new Dialog;
    diag->show();
}


void sidebar2::on_pushButton_6_clicked()
{
    resettables();
}

