#ifndef ITEMMANAGEMENT_H
#define ITEMMANAGEMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


class ItemManagement : public QWidget {
    Q_OBJECT

public:
    explicit ItemManagement(QWidget *parent = nullptr);
    void setupUi();
    void populateTable();
    bool productExists(const QString &name, const QString &brand);
    bool insertProductToDatabase(const QVector<QLineEdit*> &lineEdits);
    bool updateInventoryInDatabase(const QString &productName, const QString &brandName, const QString &newInventoryCount);
    void checkLowQuantityProducts();
    void displayLowQuantityWarning();
    bool updatePriceInDatabase(const QString &productName, const QString &brandName, const QString &newPriceCount);

private:
    QVector<QString> lowQuantityProducts;
    QSqlDatabase db;
    QLabel *titleLabel;
    QLabel *productsLabel;
    QPushButton *update;
    QPushButton *updateInventoryButton;
    QPushButton *updatePrice;
    QPushButton *addProductButton;
    QPushButton *showLowQuantityButton;
    QTableWidget *productTable;

private slots:
    void updateInventory();
    void changePrice();
    void addProduct();
    void resettables();
    void showLowQuantityProducts();
};

#endif // ITEMMANAGEMENT_H
