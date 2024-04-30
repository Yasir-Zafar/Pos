#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "itemmenu.h"
#include "sidebar.h"
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

    QWidget* checkoutBar = new QWidget;
    QWidget* menu = new QWidget;

    Sidebar* sidebar = new Sidebar();
    setupCheckoutBar(checkoutBar);
    setupMenu(menu);

    QHBoxLayout* mainLayout = new QHBoxLayout(mainWidget);

    mainLayout->addWidget(sidebar);
    mainLayout->addWidget(menu, 1);
    mainLayout->addWidget(checkoutBar);

    mainWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

