#include "sidebar2.h"
#include "ui_sidebar2.h"

sidebar2::sidebar2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sidebar2)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\Users\HP\Desktop\products (1).db");

    if (!db.open()) {
        ui->label_6->setText("Nah");
    }
    else
    {
        ui->label_6->setText("Yeah");
    }
}

sidebar2::~sidebar2()
{
    delete ui;
}
