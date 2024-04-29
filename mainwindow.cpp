#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "itemmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create mainWidget and set it as the central widget of MainWindow
    QWidget* mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    // Create leftSidebar, checkoutBar, and empty widget
    QWidget* leftSidebar = new QWidget;
    QWidget* checkoutBar = new QWidget;
    QWidget* menu = new QWidget;

    // Setup sidebar, checkout bar, and empty widget
    setupSidebar(leftSidebar);
    setupCheckoutBar(checkoutBar);
    setupMenu(menu);

    // Add the widgets to the main window layout
    QHBoxLayout* mainLayout = new QHBoxLayout(mainWidget);

    // Set fixed size for the sidebars
    leftSidebar->setFixedWidth(200); // Adjust width as needed
    checkoutBar->setFixedHeight(100); // Adjust height as needed

    // Add the sidebars and empty widget to the main layout
    mainLayout->addWidget(leftSidebar);
    mainLayout->addWidget(menu, 1); // Stretch factor 1 to fill remaining space
    mainLayout->addWidget(checkoutBar);

    // Set the main layout for the mainWidget
    mainWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

