#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "itemmenu.h"
#include "sidebar.h"
#include "cartItem.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* mainWidget = new QWidget;
    setCentralWidget(mainWidget);


    QWidget* menu = new QWidget;

    Sidebar* sidebar = new Sidebar();
    setupCheckoutBar(ui->widget);
    setupMenu(menu);

    QHBoxLayout* mainLayout = new QHBoxLayout(mainWidget);
    layout = new QVBoxLayout(this);
    ui->scrollAreaWidgetContents->setLayout(layout);
    totalAmount = 0;
    ui->label_6->setText(QString::number(totalAmount));
    mainLayout->addWidget(sidebar);
    mainLayout->addWidget(menu, 1);
    mainLayout->addWidget(ui->widget);
    mainWidget->setLayout(mainLayout);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    count++;
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    ui->scrollAreaWidgetContents->show();
    qDebug() << senderButton->layout()->dynamicPropertyNames();
    price = senderButton->property("priceLabel").toString();
    newWid = new cartItem(this, name, price);
    QVBoxLayout *top = new QVBoxLayout;
    disconnect(newWid->counter, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged(int)));

    // Connect valueChanged signal before retrieving the quantity
    connect(newWid->counter, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged(int)));

    // Retrieve quantity from the QSpinBox and store it in the vector
    int quantity = newWid->counter->value();
    itemQuantity.append(quantity);

    top->addWidget(newWid);
    layout->addLayout(top);
    // Store item information in vectors
    itemName.append(name);
    itemPrice.append(price);
}

void MainWindow::on_checkout_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Member Check", "Are You A Member", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "You a reaal nigga my G";
        qDebug() << "Discount Added!";
        totalAmount = totalAmount * (0.9);
        ui->label_6->setText(QString::number(totalAmount));
    }
    else {
        QMessageBox::critical(this, "Not a Member", "You're Not a Member Bitch ass Nigga");
        this->close();
    }
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }
    ui->scrollAreaWidgetContents->hide();
    QSqlDatabase myindb = QSqlDatabase::addDatabase("QSQLITE");
    myindb.setDatabaseName("sales.db");
    if (myindb.open()) {
        qDebug() << "DB is open";
    }
    for (int i = 0; i < itemName.size(); i++) {
        QSqlQuery query(myindb);
        query.prepare("INSERT INTO info "
                      "VALUES (?, ?, ?);");
        query.addBindValue(itemName[i]);
        query.addBindValue(itemPrice[i]);
        query.addBindValue(itemQuantity[count + i]);
        query.exec();
    }
    itemName.clear();
    itemPrice.clear();
    itemQuantity.clear();
}

void MainWindow::onSpinBoxValueChanged(int newValue)
{
    qDebug() << "New value of QSpinBox:" << newValue;
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    int quantity = spinBox->value();
    itemQuantity.append(quantity);
    for (int i = 0; i < itemQuantity.size(); i++) {
        qDebug() << itemQuantity[i];
    }

}


