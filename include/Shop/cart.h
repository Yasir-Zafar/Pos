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
#include <QDateTime>

#include "cartitem.h"
#include "receipt.h"
#include "feedback.h"
#include "cartitem.h"

class Cart : public QWidget {
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = nullptr);
    ~Cart();

public slots:
    void on_pushButton_clicked(int index);
    void onSpinBoxValueChanged(int newValue);
    void on_checkout_clicked();
    void on_feedback_clicked();

private:
    void setupCart();

    QWidget *cartWidget;
    QVBoxLayout *mainLayout;
    QScrollArea *scrollArea;
    QWidget* scrollAreaContentWidgets;
    QVBoxLayout *top;
    QVBoxLayout* lll;

    QLabel *totalAmountValueLabel;
    QLabel *subtotalValueLabel;

    QVector <cartItem*> newWid;
    QString name;
    double price;

    float subtotal;
    Receipt* receipt;
    feedback* feed;
};

#endif // CART_H
