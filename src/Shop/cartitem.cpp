#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>
#include "../../include/Shop/cartitem.h"

cartItem::cartItem(QWidget* parent, QString name1, double price2) : QWidget(parent), name1(name1), price2(price2) {
    name = new QLabel;
    price = new QLabel;
    quantity = new QLabel("Quantity: ");
    counter = new QSpinBox;

    name->setText(this->name1);
    QString pr = QString::number(this->price2);
    price->setText("PKR: " + pr);

    QFont nameFont("Arial Rounded", 14, QFont::Bold);
    QFont priceFont("Arial Rounded", 11);
    QFont quantityFont("Arial Rounded", 11);
    QFont counterFont("Arial Rounded", 11);

    name->setFont(nameFont);
    price->setFont(priceFont);
    quantity->setFont(quantityFont);
    counter->setFont(counterFont);

    QHBoxLayout* labelLayout = new QHBoxLayout;
    labelLayout->addWidget(name);
    labelLayout->addSpacing(20);

    QHBoxLayout* quantityLayout = new QHBoxLayout;
    quantityLayout->addWidget(price);
    quantityLayout->addWidget(quantity);
    quantityLayout->addWidget(counter);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(labelLayout);
    layout->addLayout(quantityLayout);

    // Set margins and spacing
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(10);
}
