#include "product.h"

Product::Product(int id, const QString& name, const QString& brand, double price,
                 const QString& category, int unit, int sold, int inventory)
    : m_id(id), m_name(name), m_brand(brand), m_price(price),
      m_category(category), m_unit(unit), m_sold(sold), m_inventory(inventory) {}

int Product::id() const {
    return m_id;
}

QString Product::name() const {
    return m_name;
}

QString Product::brand() const {
    return m_brand;
}

double Product::price() const {
    return m_price;
}

QString Product::category() const {
    return m_category;
}

int Product::unit() const {
    return m_unit;
}

int Product::sold() const {
    return m_sold;
}

int Product::inventory() const {
    return m_inventory;
}

void Product::setId(int id) {
    m_id = id;
}

void Product::setName(const QString& name) {
    m_name = name;
}

void Product::setBrand(const QString& brand) {
    m_brand = brand;
}

void Product::setPrice(double price) {
    m_price = price;
}

void Product::setCategory(const QString& category) {
    m_category = category;
}

void Product::setUnit(int unit) {
    m_unit = unit;
}

void Product::setSold(int sold) {
    m_sold = sold;
}

void Product::setInventory(int inventory) {
    m_inventory = inventory;
}
