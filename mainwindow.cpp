#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(0, 0, 1920, 1080);
    setWindowTitle("Pos");

    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);

    mainLayout = new QHBoxLayout(mainWidget);
    mainWidget->setLayout(mainLayout);

    sidebar = new Sidebar();
    mainLayout->addWidget(sidebar);
    connect(sidebar, &Sidebar::button1Clicked, this, &MainWindow::handleSidebarButton1Click);
    connect(sidebar, &Sidebar::button3Clicked, this, &MainWindow::handleSidebarButton3Click);

    shop = new Shop();
    mainLayout->addWidget(shop);
}

void MainWindow::deleteLastWidget() {
    QWidget *mainWidget = centralWidget();
    if (!mainWidget)
        return;

    QLayout *mainLayout = mainWidget->layout();
    if (!mainLayout)
        return;

    QLayoutItem *lastItem = mainLayout->takeAt(mainLayout->count() - 1);
    if (!lastItem)
        return;

    QWidget *widgetToDelete = lastItem->widget();
    if (widgetToDelete) {
        delete widgetToDelete;
    } else {
        delete lastItem;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sidebar;
    delete user;
}


void MainWindow::handleSidebarButton1Click() {
    MainWindow::deleteLastWidget();
    shop = new Shop();
    mainLayout->addWidget(shop);
}

void MainWindow::handleSidebarButton3Click() {
    MainWindow::deleteLastWidget();
    user = new User();
    mainLayout->addWidget(user);
}
