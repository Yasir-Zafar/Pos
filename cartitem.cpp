#include "cartitem.h"
#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>

cartItem::cartItem(QWidget* parent, QString name1, double price2) : QWidget(parent), name1(name1), price2(price2) {
    name = new QLabel;
    price = new QLabel;
    quantity = new QLabel("Quantity: ");
    counter = new QSpinBox;

    name->setText(this->name1);
    QString pr = QString::number(this->price2);
    price->setText("Price: PKR" + pr);

    QHBoxLayout* labelLayout = new QHBoxLayout;
    labelLayout->addWidget(name);
    labelLayout->addWidget(price);


    QHBoxLayout* quantityLayout = new QHBoxLayout;
    quantityLayout->addWidget(quantity);
    quantityLayout->addWidget(counter);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(labelLayout);
    layout->addLayout(quantityLayout);

    // Set margins and spacing
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
}
