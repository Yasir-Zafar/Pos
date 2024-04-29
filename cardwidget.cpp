#include "cardwidget.h"
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QVBoxLayout>

CardWidget::CardWidget(QWidget* parent) : QWidget(parent) {
    setupUi();
    loadData();
    applyStyles();
}

void CardWidget::setupUi() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    nameLabel = new QLabel(this);
    brandLabel = new QLabel(this);
    categoryLabel = new QLabel(this);
    priceLabel = new QLabel(this);

    layout->addWidget(nameLabel);
    layout->ddWidget(brandLabel);
    layout->addWidget(categoryLabel);
    layout->addWidget(priceLabel);

    setLayout(layout);
}

void CardWidget::loadData() {
    // Open SQL database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("project_root/SQL/products.db"); // Adjust path as needed

    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    // Retrieve one row from the database
    QSqlQuery query("SELECT Name, Brand, Category, Price FROM products LIMIT 1");

    if (!query.exec() || !query.first()) {
        qDebug() << "Error: Unable to retrieve data from the database";
        db.close();
        return;
    }

    // Extract data from the query result
    QString productName = query.value("Name").toString();
    QString brand = query.value("Brand").toString();
    QString category = query.value("Category").toString();
    double price = query.value("Price").toDouble();

    // Set text to labels
    nameLabel->setText("Product: " + productName);
    brandLabel->setText("Brand: " + brand);
    categoryLabel->setText("Category: " + category);
    priceLabel->setText("Price: $" + QString::number(price, 'f', 2));

    // Close the database connection
    db.close();
}

void CardWidget::applyStyles() {
    // Apply styles to the card widget
    setStyleSheet(
        "background-color: #ffffff;"       // Set background color to white
        "border: 2px solid #000000;"       // Set border to deep black
        "border-radius: 10px;"             // Set border radius to make it rounded
    );

    // Apply styles to the labels
    nameLabel->setStyleSheet("color: #333333;");
    brandLabel->setStyleSheet("color: #333333;");
    categoryLabel->setStyleSheet("color: #333333;");
    priceLabel->setStyleSheet("color: #333333;");
}
