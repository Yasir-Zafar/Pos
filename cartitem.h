#ifndef CARTITEM_H
#define CARTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>

inline QVector<QString> itemName;
inline QVector<QString> itemBrand;
inline QVector<double> itemPrice;
inline QVector<int> itemQuantity;
inline float totalAmount;
class cartItem : public QWidget
{
public:
    int temp;
    QString name1;
    double price2;
    cartItem(QWidget* parent = 0, QString name1 = 0, double price1 = 0);
    QLabel* name;
    QLabel* price;
    QLabel* quantity;
    QSpinBox* counter;

public slots:

};

#endif // CARTITEM_H
