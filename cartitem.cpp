#include "cartitem.h"
#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>

cartItem::cartItem(QWidget* parent, QString name1, double price2) : QWidget(parent), name1(name1), price2(price2) {
    name = new QLabel;
    price = new QLabel;
    quantity = new QLabel("Quantity: ");
    counter = new QSpinBox;

    // counter->setStyleSheet("QSpinBox {"
    //                        "   border: 2px solid #4ACCB1;" // Border color
    //                        "   border-radius: 10px;"       // Border radius
    //                        "   padding: 5px;"               // Padding
    //                        "   background-color: #ECECEC;" // Background color
    //                        "   color: #333333;"             // Text color
    //                        "   font-size: 14px;"            // Font size
    //                        "}"
    //                        "QSpinBox::up-button, QSpinBox::down-button {"
    //                        "   width: 20px;"                // Button width
    //                        "   height: 20px;"               // Button height
    //                        "   background-color: #4ACCB1;"  // Button background color
    //                        "   border: none;"                // Remove button border
    //                        "   border-top-left-radius: 10px;"  // Border radius for up button
    //                        "   border-top-right-radius: 10px;" // Border radius for down button
    //                        "}"
    //                        "QSpinBox::up-button:hover, QSpinBox::down-button:hover {"
    //                        "   background-color: #55EBE6;"  // Button background color on hover
    //                        "}"
    //                        "QSpinBox::up-arrow{"
    //                        "   width: 10px;"                // Arrow width
    //                        "   height: 10px;"               // Arrow height
    //                        "   image: url(:/home/boi/Projects/C++/Uni/Pos/img/up.png);" // Arrow image
    //                        "}"
    //                        "QSpinBox::down-arrow {"
    //                        "   width: 10px;"                // Arrow width
    //                        "   height: 10px;"               // Arrow height
    //                        "   image: url(:/home/boi/Projects/C++/Uni/Pos/img/down.png);" // Arrow image
    //                        "}");

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
