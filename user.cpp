#include "user.h"
#include "dialog.h"
#include "removeuser.h"

User::User(QWidget *parent)
    : QWidget{parent}
{
    setupUser();
    setAdmins();
    setEmployees();
}

void User::setupUser(){
    label_6 = new QLabel("User Management", this); // 1
    label_6->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    label_6->setContentsMargins(0,0,0,20);
    label_6->setStyleSheet("color: #333");

    label_7 = new QLabel("Admin", this); // table 1
    label_7->setFont(QFont("Arial Rounded", 14, QFont::Bold));

    label_8 = new QLabel("Employee", this); // table 2
    label_8->setFont(QFont("Arial Rounded", 14, QFont::Bold));

    pushButton_6 = new QPushButton("Update Tables", this);// button 1
    pushButton_6->setFont(QFont("Arial Rounded", 12));
    pushButton_5 = new QPushButton("Add New", this);  // button 2
    pushButton_5->setFont(QFont("Arial Rounded", 12));
    rem_1 = new QPushButton("Remove", this); // button 3
    rem_1->setFont(QFont("Arial Rounded", 12));

    // Create and configure the QTableWidgets
    tableWidget = new QTableWidget(this); // admin
    tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

    tableWidget_2 = new QTableWidget(this); // employees
    tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

    QHBoxLayout *topLayout = new QHBoxLayout;

    QWidget* mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    setStyleSheet("background-color: #ECECEC; border-radius: 20px;");
    mainLayout->setContentsMargins(20, 20, 20, 20);

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(label_6);
    horizontalLayout->addStretch();

    QWidget *buttonWidget = new QWidget;
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    buttonLayout->addWidget(pushButton_6);
    buttonLayout->addSpacing(100);
    buttonLayout->addWidget(pushButton_5);
    buttonLayout->addWidget(rem_1);
    buttonLayout->setAlignment(Qt::AlignBottom);
    horizontalLayout->addWidget(buttonWidget);

    QVBoxLayout *employeeLayout = new QVBoxLayout;
    employeeLayout->addWidget(label_8);
    employeeLayout->addWidget(tableWidget_2);

    QVBoxLayout *adminLayout = new QVBoxLayout;
    adminLayout->addWidget(label_7);
    adminLayout->addWidget(tableWidget);

    pushButton_5->setStyleSheet("QPushButton { background-color: #f0f0f0; border-radius: 15px; border: 5px solid #333; color: #333; padding: 15px }"
                                "QPushButton:hover { border: 5px solid #28A4A6; }");

    pushButton_6->setStyleSheet("QPushButton { background-color: #f0f0f0; color: #333; border-radius: 15px; border: 5px solid #333; padding: 15px }"
                                "QPushButton:hover { border: 5px solid #28A4A6; }");

    rem_1->setStyleSheet("QPushButton { background-color: #f0f0f0; border-radius: 15px; border: 5px solid #333; color: #f44336; padding: 15px }"
                         "QPushButton:hover { border: 5px solid #28A4A6; }");

    tableWidget->setStyleSheet("QTableWidget { border: 4px solid #333; border-radius: 10px; }");
    tableWidget_2->setStyleSheet("QTableWidget { border: 4px solid #333; border-radius: 10px; }");

    connect(pushButton_5, &QPushButton::clicked, this, &User::on_pushButton_5_clicked);
    connect(pushButton_6, &QPushButton::clicked, this, &User::on_pushButton_6_clicked);
    connect(rem_1, &QPushButton::clicked, this, &User::on_rem_1_clicked);

    mainLayout->addLayout(horizontalLayout);
    mainLayout->addLayout(employeeLayout);
    mainLayout->addSpacing(40);
    mainLayout->addLayout(adminLayout);
    mainLayout->setContentsMargins(20,20,20,20);

    mainWidget->setLayout(mainLayout);
    topLayout->addWidget(mainWidget);

    setLayout(topLayout);
}

void User::setAdmins()
{
    tableWidget->setColumnCount(2);

    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList header;
    header << "Username" << "Email";
    tableWidget->setHorizontalHeaderLabels(header);

    tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for (int i = 0; i < tableWidget->columnCount(); ++i) {
        tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    tableWidget->setHorizontalHeaderLabels(header);

    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->verticalHeader()->setVisible(false);

    tableWidget->horizontalHeader()->setFont(QFont("Arial Rounded", 13, QFont::Bold));
    tableWidget->setFont(QFont("Arial", 14));

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/SQL/admin.db");

    QSqlQuery query;
    query.exec("SELECT * FROM Admins");

    if (!db.open())
    {
        qDebug() << "Error: Failed to open database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully!";

        QSqlQuery query2;
        if (!query2.exec("SELECT * FROM Admins"))
        {
            qDebug() << "Error executing query:" << query2.lastError().text();
        }
        else
        {
            // Process the query result
            while (query2.next()) {
                QString username = query2.value(0).toString();
                QString email = query2.value(1).toString();

                int newRow = tableWidget->rowCount();
                tableWidget->insertRow(newRow);
                tableWidget->setItem(newRow, 0, new QTableWidgetItem(email));
                tableWidget->setItem(newRow, 1, new QTableWidgetItem(username));

                // Do something with the retrieved data
                // qDebug() << "Username:" << username << ", Email:" << email;
            }
        }
    }

    // Close the database connection
    db.close();
}


void User::setEmployees()
{
    tableWidget_2->setColumnCount(3);
    tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < tableWidget->columnCount(); ++i) {
        tableWidget_2->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    tableWidget_2->verticalHeader()->setVisible(false);

    QStringList header;
    header << "Username" << "Email"<<"Timings";
    tableWidget_2->setHorizontalHeaderLabels(header);

    tableWidget_2->horizontalHeader()->setFont(QFont("Arial Rounded", 13, QFont::Bold));
    tableWidget_2->setFont(QFont("Arial", 14));

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/SQL/employees_2.db");

    QSqlQuery query;
    query.exec("SELECT * FROM employees");

    if (!db.open())
    {
        qDebug() << "Error: Failed to open database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully!";
        QSqlQuery query2;

        if (!query2.exec("SELECT * FROM employees"))
        {
            qDebug() << "Error executing query:" << query2.lastError().text();
        }
        else
        {
            while (query2.next()) {
                QString username = query2.value(0).toString();
                QString email = query2.value(1).toString();
                QString shift = query2.value(3).toString();

                int newRow = tableWidget_2->rowCount();
                tableWidget_2->insertRow(newRow);
                tableWidget_2->setItem(newRow, 0, new QTableWidgetItem(email));
                tableWidget_2->setItem(newRow, 1, new QTableWidgetItem(username));
                tableWidget_2->setItem(newRow, 2, new QTableWidgetItem(shift));
            }
        }
    }

    db.close();
}

void User::resettables()
{
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);

    tableWidget_2->setRowCount(0);
    tableWidget_2->setColumnCount(0);

    setAdmins();
    setEmployees();
}

void User::on_pushButton_5_clicked()
{
    Dialog *diag = new Dialog;
    diag->show();
}

void User::on_pushButton_6_clicked()
{
    resettables();
}

void User::on_rem_1_clicked()
{
    RemoveUser *remove = new RemoveUser;
    remove->show();
}
