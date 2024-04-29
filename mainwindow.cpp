#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "itemmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    QWidget* leftSidebar = new QWidget;
    QWidget* checkoutBar = new QWidget;
    QWidget* menu = new QWidget;

    setupSidebar(leftSidebar);
    setupCheckoutBar(checkoutBar);
    setupMenu(menu);

    QHBoxLayout* mainLayout = new QHBoxLayout(mainWidget);

    mainLayout->addWidget(leftSidebar);
    mainLayout->addWidget(menu, 1);
    mainLayout->addWidget(checkoutBar);

    mainWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

