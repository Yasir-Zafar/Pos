#ifndef CART_H
#define CART_H

#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

#include <QHBoxLayout>
#include <QSpinBox>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "cartitem.h"
#include "receipt.h"

class Cart : public QWidget {
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = nullptr);
    ~Cart();

public slots:
    void on_pushButton_clicked(int index);
    void onSpinBoxValueChanged(int newValue);
    void on_checkout_clicked();

private:
    void setupCart();

    QWidget *cartWidget;
    QVBoxLayout *mainLayout;
    QVBoxLayout *lll;
    QVBoxLayout* lay;
    QScrollArea *scrollArea;
    QWidget* scrollAreaContentWidgets;
    QVBoxLayout *top;

    QLabel *totalAmountValueLabel;
    QLabel *subtotalValueLabel;

    QVector <cartItem*> newWid;
    QString name;
    double price;

    float subtotal;
    Receipt* receipt;
};

#endif // CART_H
