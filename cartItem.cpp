#include "cartItem.h"
#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>
cartItem::cartItem(QWidget* parent, QString name1, QString price2) : QWidget(parent), name1(name1), price2(price2) {
    name = new QLabel;
    price = new QLabel;
    quantity = new QLabel;
    counter = new QSpinBox;
    name->setText(this->name1);
    price->setText("Price: " + this->price2);
    quantity->setText("Quantity: ");
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(name);
    layout->addWidget(price);
    layout->addWidget(quantity);
    layout->addWidget(counter);
}

