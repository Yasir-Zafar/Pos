#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product {
public:
    Product(int id, const QString& name, const QString& brand, double price,
            const QString& category, int unit, int sold, int inventory);

    int id() const;
    QString name() const;
    QString brand() const;
    double price() const;
    QString category() const;
    int unit() const;
    int sold() const;
    int inventory() const;

    void setId(int id);
    void setName(const QString& name);
    void setBrand(const QString& brand);
    void setPrice(double price);
    void setCategory(const QString& category);
    void setUnit(int unit);
    void setSold(int sold);
    void setInventory(int inventory);

private:
    int m_id;
    QString m_name;
    QString m_brand;
    double m_price;
    QString m_category;
    int m_unit;
    int m_sold;
    int m_inventory;
};

#endif // PRODUCT_H
