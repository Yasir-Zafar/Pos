#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "itemmenu.h"
#include "sidebar.h"
#include <QVector>
#include <QMessageBox>
int count = 0;
int spin = 0;

QVector<QString> itemName;
QVector<QString> itemPrice;
QVector<int> itemQuantity;

void MainWindow::switchToThirdPage() {
    if (currentPage) {
        delete currentPage;
    }

    // Create the new page
    currentPage = new QWidget(this);
    currentPage->setStyleSheet("background-color: #FFFFFF;"); // Set background color
    QVBoxLayout* layout = new QVBoxLayout(currentPage);
    // Add widgets to the layout of the third page if needed

    setCentralWidget(currentPage);
    currentLayout = layout;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    QWidget* menu = new QWidget;

    sidebar = new Sidebar();
    connect(sidebar->getThirdButton(), &QPushButton::clicked, this, &MainWindow::switchToThirdPage);
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
    count = 0;
    itemName.resize(0);
    itemPrice.resize(0);
    for (int i = 0; i < cardButtons.size(); i++)
    connect(cardButtons[i], &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString name;
QString price;

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

    int start = count;
    for (int i = 0; i < itemName.size(); i++) {
        QSqlQuery query(myindb);
        query.prepare("INSERT INTO info "
                      "VALUES (?, ?, ?);");
        query.addBindValue(itemName[i]);
        query.addBindValue(itemPrice[i]);
        for (int j = start + 1; j < itemQuantity.size(); j++) {
            qDebug() << "At index " << j << "  " << itemQuantity[j];
            if (itemQuantity[j] == 1 && j > 3) {
                query.addBindValue(itemQuantity[j - 1]);
                qDebug() << itemQuantity[j - 1] << "break";
                start = j;
                break;
            }
            else if (j == itemQuantity.size() - 1) {
                query.addBindValue(itemQuantity[j]);
                qDebug() << itemQuantity[j] << "break";
                break;
            }
        }
        query.exec();
    }
    itemName.clear();
    itemPrice.clear();
    itemQuantity.clear();
}

void MainWindow::onSpinBoxValueChanged(int newValue)
{
    spin++;
    qDebug() << "New value of QSpinBox:" << newValue;
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    int quantity = spinBox->value();
    itemQuantity.append(quantity);
    for (int i = 0; i < itemQuantity.size(); i++) {
        qDebug() << itemQuantity[i];
    }
}
