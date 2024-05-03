#ifndef CART_H
#define CART_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSqlDatabase>
#include <QSqlQuery>

class Cart : public QWidget {
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = nullptr);

private slots:
    void on_pushButton_clicked();
    void onSpinBoxValueChanged(int newValue);
    void on_checkout_clicked();

private:
    void setupCart();

    QWidget *cartWidget;
    QVector<QString> itemName;
    QVector<QString> itemPrice;
    QVector<int> itemQuantity;

    int count = 0;
    int spin = 0;
    QString name;
    QString price;
    int totalAmount = 0;
};

#endif // CART_H
