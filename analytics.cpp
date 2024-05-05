#include "analytics.h"
#include "ui_analytics.h"
#include"linechart.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB_connection = QSqlDatabase ::addDatabase("QSQLITE");
    DB_connection.setDatabaseName("D:/checkout.db");
    if(DB_connection.open())
    {
        qDebug() << "Database is connected";
    }
    else
    {
        qDebug() << "Database is not connected";
        qDebug() << "Error:" << DB_connection.lastError();
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DB_connection.open();
    DB_connection_2.open();
    DB_connection_3.open();
    QSqlDatabase :: database() .transaction();
    QSqlQuery sumdata(DB_connection);

    QString sum ;
     sumdata.prepare("SELECT SUM(Total) FROM checkout");
    sumdata.exec();
     if(sumdata.next())
    {
    sum = sumdata.value(0).toString();
     }
    qDebug() << "sum=" << sum;
     ui->label->setText("Rs. " + sum);

    ui->label->setAlignment(Qt::AlignCenter);
     DB_connection_2 = QSqlDatabase ::addDatabase("QSQLITE");
     DB_connection_2.setDatabaseName("D:/sales.db");
     if(DB_connection_2.open())
     {
         qDebug() << "Database is connected";
     }
     else
     {
         qDebug() << "Database is not connected";
         qDebug() << "Error:" << DB_connection_2.lastError();
     }

    QSqlQuery solditems(DB_connection_2);
    QString itemssold;
    solditems.prepare("SELECT SUM(quantity) FROM info;");
    if(!solditems.exec())
        itemssold = "error";
    if(solditems.next())
    {
        itemssold = solditems.value(0).toString();
    }
    ui->label_3-> setText(itemssold);
    ui->label_3->setAlignment(Qt::AlignCenter);
    DB_connection_3 = QSqlDatabase ::addDatabase("QSQLITE");
    DB_connection_3.setDatabaseName("D:/products.db");
    if(DB_connection_3.open())
    {
        qDebug() << "Database is connected";
    }
    else
    {
        qDebug() << "Database is not connected";
        qDebug() << "Error:" << DB_connection_3.lastError();
    }


    QSqlQuery readinventory(DB_connection_3);
    QString inventory;
    readinventory.prepare("SELECT SUM(Inventory) FROM products");
    readinventory.exec();
    if(readinventory.next())
    {
        inventory = readinventory.value(0).toString();
    }

    ui->label_5-> setText(inventory);
    ui->label_5->setAlignment(Qt::AlignCenter);

    QSqlQuery readmaximum(DB_connection_3);
    QString m1 ;
    readmaximum.prepare("SELECT MAX(Sold) FROM products ");
    if(readmaximum.exec())
        m1 = "error query";
    if(readmaximum.next())
    {
        m1 = readmaximum.value(0).toString();
    }
    QString max1;
    QSqlQuery readmaxname(DB_connection_3);
    readmaxname.prepare("SELECT Name FROM products WHERE Sold =" + m1);
    if(readmaxname.exec())
        max1 = "error query";
    if(readmaxname.next())
    {
        max1 = readmaxname.value(0).toString();
    }
    ui->listWidget->addItem("1."+max1);
    ui->listWidget->addItem("");
    QSqlQuery readmaximum2(DB_connection_3);
    QString m2 ;
    readmaximum.prepare("SELECT MAX(Sold) FROM products Where Sold != " + m1);
    if(!readmaximum.exec())
        m2 = "error query";
    if(readmaximum.next())
    {
        m2 = readmaximum.value(0).toString();
    }
    qDebug() << m2;
    QString max2;
    QSqlQuery readmaxname2(DB_connection_3);
    readmaxname2.prepare("SELECT Name FROM products WHERE Sold =" + m2);
    if(!readmaxname2.exec())
        max2 = "error query";
    if(readmaxname2.next())
    {
        max2 = readmaxname2.value(0).toString();
    }
    ui->listWidget->addItem("2."+max2);
    ui->listWidget->addItem("");

    QSqlQuery readmaximum3(DB_connection_3);
    QString m3 ;
    readmaximum3.prepare("SELECT MAX(Sold) FROM products WHERE Sold !=" + m1 +" AND Sold !=" + m2 + ";");
    if(!readmaximum3.exec())
        m3 = "error query";
    if(readmaximum3.next())
    {
        m3 = readmaximum3.value(0).toString();
    }
    qDebug() << m3;
    QString max3;
    QSqlQuery readmaxname3(DB_connection_3);
    readmaxname3.prepare("SELECT Name FROM products WHERE Sold =" + m3);
    if(!readmaxname3.exec())
        max3 = "error query";
    if(readmaxname3.next())
    {
        max3 = readmaxname3.value(0).toString();
    }
    ui->listWidget->addItem("3."+max3);

     QSqlDatabase::database().commit();
    DB_connection.close();
     DB_connection_2.close();
    DB_connection_3.close();




}


void MainWindow::on_DisplayGraph_clicked()
{
    LineChart *newlinechart = new LineChart;
    newlinechart->show();
}

