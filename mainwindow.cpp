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
    connect(sidebar, &Sidebar::button2Clicked, this, &MainWindow::handleSidebarButton2Click);
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

    if (mainLayout->count() < 2)
        return;

    QLayoutItem *secondItem = mainLayout->itemAt(1);
    QWidget *widgetToDelete = secondItem->widget();

    if (widgetToDelete) {
        delete widgetToDelete;
    } else {
        delete secondItem;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sidebar;
    delete user;

    delete mainWidget;
    delete mainLayout;
}


void MainWindow::handleSidebarButton1Click() {
    MainWindow::deleteLastWidget();
    shop = new Shop();
    mainLayout->addWidget(shop);
}

void MainWindow::handleSidebarButton2Click() {
    MainWindow::deleteLastWidget();
    analysis = new Analysis();
    mainLayout->addWidget(analysis);
}

void MainWindow::handleSidebarButton3Click() {
    MainWindow::deleteLastWidget();
    user = new User();
    mainLayout->addWidget(user);
}
