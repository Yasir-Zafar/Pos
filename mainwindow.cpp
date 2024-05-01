#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "itemmenu.h"
#include "sidebar.h"
#include "cartitem.h"
#include <QMessageBox>
#include "employeePage.h"

void MainWindow::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void MainWindow::setupEmployeePage(QHBoxLayout* mainLayout) {
    Sidebar* sidebar = new Sidebar();
    sidebar->setStyleSheet("background-color: #f9f9f9; color: #333333; border-radius: 20px;");

    mainLayout->addWidget(sidebar);

    // Add the employee page
    QWidget* employeePage = new QWidget();

    mainLayout->addWidget(employeePage);

    setLayout(mainLayout);
}

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
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    ui->scrollAreaWidgetContents->show();
    QString name = senderButton->property("Label1").toString();
    QString price = senderButton->property("Label2").toString();
    cartItem* newWid = new cartItem(this, name, price);
    QVBoxLayout *top = new QVBoxLayout;
    top->addWidget(newWid);
    layout->addLayout(top);
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

}


