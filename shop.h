#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QStringList>
#include <QVector>

#include "cart.h"

struct Product {
    int id;
    QString name;
    QString brand;
    double price;
    QString category;
    int unit;
    int sold;
    int inventory;
};

QVector<Product> productsArray;
QVector<QPushButton*> cardButtons;

class Shop : public QWidget {
    Q_OBJECT

public:
    explicit Shop(QWidget* parent = nullptr);
    ~Shop();
    void setupMenu();
    void filterCards(const QString& searchText);
    void setupCards();

private:
    Cart *cart;
    QVBoxLayout* topBoxLayout;
    QWidget* cardsWidget;
    QScrollArea* scrollArea;
    QLineEdit* searchBar;
};

#endif // SHOP_H
