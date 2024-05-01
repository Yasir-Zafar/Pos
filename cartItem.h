#ifndef CARTITEM_H
#define CARTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>

class cartItem : public QWidget
{
public:
    int temp;
    QString name1, price2;
    cartItem(QWidget* parent = 0, QString name1 = 0, QString price2 = 0);
    QLabel* name;
    QLabel* price;
    QLabel* quantity;
    QSpinBox* counter;
    void operator= (cartItem& other) {
        this->name = new QLabel;
        this->price = new QLabel;
        this->quantity = new QLabel;
        this->counter = new QSpinBox;
        this->name = other.name;
        this->price = other.price;
        this->quantity = other.quantity;
        this->counter = other.counter;
    }
    void addItem() {
        name->setText("PlaceGetterHere");
        price->setText("PlaceGetterHere");
        quantity->setText("Quantity: ");
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(name);
        layout->addWidget(price);
        layout->addWidget(quantity);
        layout->addWidget(counter);
    }
};

#endif // CARTITEM_H
