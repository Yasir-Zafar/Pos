#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product {
public:
    Product(const QString& name, const QString& brand, double price);

    QString name() const;
    QString brand() const;
    double price() const;

    void setName(const QString& name);
    void setBrand(const QString& brand);
    void setPrice(double price);

private:
    QString m_name;
    QString m_brand;
    double m_price;
};

#endif // PRODUCT_H
