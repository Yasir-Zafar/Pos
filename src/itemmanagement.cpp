#include "../include/itemmanagement.h"

ItemManagement::ItemManagement(QWidget *parent) : QWidget(parent) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/products.db");

    setupUi();
    populateTable();
    showLowQuantityProducts();
}

void ItemManagement::setupUi(){

    titleLabel = new QLabel("Product Management", this);
    titleLabel->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    titleLabel->setContentsMargins(0,0,0,20);
    titleLabel->setStyleSheet("color: #333");

    productsLabel = new QLabel("Products", this);
    productsLabel->setFont(QFont("Arial Rounded", 16, QFont::Bold));

    updateInventoryButton = new QPushButton("Update Inventory", this);
    updateInventoryButton->setFont(QFont("Arial Rounded", 12));
    updatePrice= new QPushButton("Update Price", this);
    updatePrice->setFont(QFont("Arial Rounded", 12));
    addProductButton = new QPushButton("Add Product", this);
    addProductButton->setFont(QFont("Arial Rounded", 12));

    showLowQuantityButton = new QPushButton("Low Stock", this);
    showLowQuantityButton->setFont(QFont("Arial Rounded", 12));
    update = new QPushButton("Update Table", this);
    update->setFont(QFont("Arial Rounded", 12));

    productTable = new QTableWidget(this);
    productTable->setObjectName(QString::fromUtf8("tableWidget"));

    QHBoxLayout *topLayout = new QHBoxLayout;

    QWidget* mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(titleLabel);
    horizontalLayout->addStretch();

    QWidget *buttonWidget = new QWidget;
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    buttonLayout->addWidget(update);
    buttonLayout->addWidget(showLowQuantityButton);
    buttonLayout->addWidget(updateInventoryButton);
    buttonLayout->addWidget(updatePrice);
    buttonLayout->addWidget(addProductButton);
    buttonLayout->setAlignment(Qt::AlignBottom);
    horizontalLayout->addWidget(buttonWidget);

    QVBoxLayout *tableLayout = new QVBoxLayout;
    tableLayout->addWidget(productsLabel);
    tableLayout->addWidget(productTable);

    updateInventoryButton->setStyleSheet("QPushButton { background-color: #f0f0f0; border-radius: 15px; border: 5px solid #333; color: #333; padding: 15px }"
                                         "QPushButton:hover { border: 5px solid #28A4A6; }");

    addProductButton->setStyleSheet("QPushButton { background-color: #f0f0f0; color: #333; border-radius: 15px; border: 5px solid #333; padding: 15px }"
                                    "QPushButton:hover { border: 5px solid #28A4A6; }");

    update->setStyleSheet("QPushButton { background-color: #f0f0f0; color: #333; border-radius: 15px; border: 5px solid #333; padding: 15px }"
                          "QPushButton:hover { border: 5px solid #28A4A6; }");

    showLowQuantityButton->setStyleSheet("QPushButton { background-color: #f0f0f0; color: #333; border-radius: 15px; border: 5px solid #333; padding: 15px }"
                                         "QPushButton:hover { border: 5px solid #28A4A6; }");

    updatePrice->setStyleSheet("QPushButton { background-color: #f0f0f0; color: #333; border-radius: 15px; border: 5px solid #333; padding: 15px }"
                                         "QPushButton:hover { border: 5px solid #28A4A6; }");

    productTable->setStyleSheet("QTableWidget { border: 4px solid #333; border-radius: 10px; }");

    connect(updateInventoryButton, &QPushButton::clicked, this, &ItemManagement::updateInventory);
    connect(updatePrice, &QPushButton::clicked, this, &ItemManagement::changePrice);
    connect(addProductButton, &QPushButton::clicked, this, &ItemManagement::addProduct);
    connect(update, &QPushButton::clicked, this, &ItemManagement::resettables);
    connect(showLowQuantityButton, &QPushButton::clicked, this, &ItemManagement::showLowQuantityProducts);

    mainLayout->addLayout(horizontalLayout);
    mainLayout->addLayout(tableLayout);
    mainLayout->setContentsMargins(20,20,20,20);

    mainWidget->setLayout(mainLayout);
    topLayout->addWidget(mainWidget);

    setStyleSheet("background-color: #ECECEC; border-radius: 20px;");

    setLayout(topLayout);
}

void ItemManagement::populateTable() {
    productTable->setColumnCount(8);

    productTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList header;
    header << "ID" << "Name" << "Brand" << "Category" << "Price" << "Unit" << "Sold" << "Inventory";
    productTable->setHorizontalHeaderLabels(header);

    productTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for (int i = 0; i < productTable->columnCount(); ++i) {
        productTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    productTable->horizontalHeader()->setStretchLastSection(true);
    productTable->verticalHeader()->setVisible(false);

    productTable->horizontalHeader()->setFont(QFont("Arial Rounded", 13, QFont::Bold));
    productTable->setFont(QFont("Arial", 14));

    QString styleSheet = "QHeaderView::section { background-color: #f0f0f0; color: #28A4A6; }";
    productTable->horizontalHeader()->setStyleSheet(styleSheet);

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM products");
    if (!query.exec()) {
        qDebug() << "Error: Failed to execute query:" << query.lastError().text();
        return;
    }

    int row = 0;
    while (query.next()) {
        productTable->insertRow(row);
        for (int col = 0; col < query.record().count(); ++col) {
            productTable->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        ++row;
    }

    db.close();
}

void ItemManagement::resettables()
{
    productTable->setRowCount(0);
    productTable->setColumnCount(0);

    productTable->setRowCount(0);
    productTable->setColumnCount(0);

    populateTable();
}

void ItemManagement::addProduct() {
    QWidget *widget = new QWidget();
    widget->setWindowTitle("Add Product");

    QVBoxLayout *layout = new QVBoxLayout(widget);

    QStringList labels = {"Name:", "Brand:", "Category:", "Price:", "Unit:", "Sold:", "Inventory:"};
    QVector<QLineEdit*> lineEdits;
    for (const QString &label : labels) {
        QLabel *labelWidget = new QLabel(label, widget);
        QLineEdit *lineEdit = new QLineEdit(widget);
        QVBoxLayout *rowLayout = new QVBoxLayout;
        rowLayout->addWidget(labelWidget);
        rowLayout->addWidget(lineEdit);
        layout->addLayout(rowLayout);
        lineEdits.append(lineEdit);
    }

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *cancelButton = new QPushButton("Cancel", widget);
    QPushButton *okButton = new QPushButton("OK", widget);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(okButton);
    layout->addLayout(buttonLayout);

    widget->setLayout(layout);
    widget->show();

    connect(cancelButton, &QPushButton::clicked, widget, &QWidget::close);
    connect(okButton, &QPushButton::clicked, [=]() {
        for (QLineEdit *lineEdit : lineEdits) {
            if (lineEdit->text().trimmed().isEmpty()) {
                QMessageBox::critical(widget, "Error", "Please fill in all fields.");
                return; // Stop further processing if any field is empty
            }
        }

        QString name = lineEdits[0]->text().trimmed();
        QString brand = lineEdits[1]->text().trimmed();

        if (productExists(name, brand)) {
            QMessageBox::critical(widget, "Error", "Product with the same Name and Brand already exists.");
        } else {
            if (insertProductToDatabase(lineEdits)) {
                QMessageBox::information(widget, "Success", "Product added successfully.");
                widget->hide();
                populateTable();
            } else {
                QMessageBox::critical(widget, "Error", "Failed to add product.");
            }
        }
    });
}

bool ItemManagement::productExists(const QString &name, const QString &brand) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM products WHERE LOWER(Name) = LOWER(?) AND LOWER(Brand) = LOWER(?)");
    query.bindValue(0, name, QSql::In | QSql::Binary);
    query.bindValue(1, brand, QSql::In | QSql::Binary);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false; // Return false in case of query execution error
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0; // Return true if count is greater than 0 (product exists), false otherwise
    } else {
        qDebug() << "No results returned from query.";
        return false; // Return false if no results are returned
    }
}

bool ItemManagement::insertProductToDatabase(const QVector<QLineEdit*> &lineEdits) {
    QString name = lineEdits[0]->text().trimmed();
    QString brand = lineEdits[1]->text().trimmed();
    QString category = lineEdits[2]->text().trimmed();
    double price = lineEdits[3]->text().trimmed().toDouble();
    int unit = lineEdits[4]->text().trimmed().toInt();
    int sold = lineEdits[5]->text().trimmed().toInt();
    int inventory = lineEdits[6]->text().trimmed().toInt();

    if (!db.open()) {
        qDebug() << "Failed to open database connection:" << db.lastError().text();
    }

    QSqlQuery query;
    query.prepare("INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, name);
    query.bindValue(1, brand);
    query.bindValue(2, category);
    query.bindValue(3, price);
    query.bindValue(4, unit);
    query.bindValue(5, sold);
    query.bindValue(6, inventory);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Error inserting product:" << query.lastError().text();
        return false;
    }
}

void ItemManagement::updateInventory() {
    QWidget *widget = new QWidget();
    widget->setWindowTitle("Update Inventory");

    QVBoxLayout *layout = new QVBoxLayout(widget);

    QLabel *productNameLabel = new QLabel("Product Name:", widget);
    QLineEdit *productNameEdit = new QLineEdit(widget);
    QLabel *brandNameLabel = new QLabel("Brand Name:", widget);
    QLineEdit *brandNameEdit = new QLineEdit(widget);
    QLabel *inventoryCountLabel = new QLabel("New Inventory Count:", widget);
    QLineEdit *inventoryCountEdit = new QLineEdit(widget);

    layout->addWidget(productNameLabel);
    layout->addWidget(productNameEdit);
    layout->addWidget(brandNameLabel);
    layout->addWidget(brandNameEdit);
    layout->addWidget(inventoryCountLabel);
    layout->addWidget(inventoryCountEdit);

    QPushButton *okButton = new QPushButton("OK", widget);
    QPushButton *cancelButton = new QPushButton("Cancel", widget);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(okButton);
    layout->addLayout(buttonLayout);

    connect(cancelButton, &QPushButton::clicked, widget, &QWidget::close);
    connect(okButton, &QPushButton::clicked, [=]() {
        QString productName = productNameEdit->text().trimmed();
        QString brandName = brandNameEdit->text().trimmed();
        QString newInventoryCount = inventoryCountEdit->text().trimmed();
        if (updateInventoryInDatabase(productName, brandName, newInventoryCount)) {
            QMessageBox::information(widget, "Success", "Inventory updated successfully.");
            widget->close();
            populateTable();
        } else {
            QMessageBox::critical(widget, "Error", "Failed to update inventory.");
        }
    });

    widget->setLayout(layout);
    widget->show();
}

void ItemManagement::changePrice() {
    QWidget *widget = new QWidget();
    widget->setWindowTitle("Update Price");

    QVBoxLayout *layout = new QVBoxLayout(widget);

    QLabel *productNameLabel = new QLabel("Product Name:", widget);
    QLineEdit *productNameEdit = new QLineEdit(widget);
    QLabel *brandNameLabel = new QLabel("Brand Name:", widget);
    QLineEdit *brandNameEdit = new QLineEdit(widget);
    QLabel *priceCountLabel = new QLabel("New Price:", widget);
    QLineEdit *priceCountEdit = new QLineEdit(widget);

    layout->addWidget(productNameLabel);
    layout->addWidget(productNameEdit);
    layout->addWidget(brandNameLabel);
    layout->addWidget(brandNameEdit);
    layout->addWidget(priceCountLabel);
    layout->addWidget(priceCountEdit);

    QPushButton *okButton = new QPushButton("OK", widget);
    QPushButton *cancelButton = new QPushButton("Cancel", widget);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(okButton);
    layout->addLayout(buttonLayout);

    connect(cancelButton, &QPushButton::clicked, widget, &QWidget::close);
    connect(okButton, &QPushButton::clicked, [=]() {
        QString productName = productNameEdit->text().trimmed();
        QString brandName = brandNameEdit->text().trimmed();
        QString newPriceCount = priceCountEdit->text().trimmed();
        if (updatePriceInDatabase(productName, brandName, newPriceCount)) {
            QMessageBox::information(widget, "Success", "Price updated successfully.");
            widget->close();
            populateTable();
        } else {
            QMessageBox::critical(widget, "Error", "Failed to update price.");
        }
    });

    widget->setLayout(layout);
    widget->show();
}

bool ItemManagement::updateInventoryInDatabase(const QString &productName, const QString &brandName, const QString &newInventoryCount) {
    if (!db.open()) {
        qDebug() << "Failed to open database connection:" << db.lastError().text();
    }

    int newCount = newInventoryCount.toInt();
    if (newCount > 75) {
        QMessageBox::critical(nullptr, "Error", "Inventory cannot exceed 75.");
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE products SET Inventory = ? WHERE LOWER(Name) = LOWER(?) AND LOWER(Brand) = LOWER(?)");
    query.bindValue(0, newCount);
    query.bindValue(1, productName);
    query.bindValue(2, brandName);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            return true;
        }
    }

    return false;
}

bool ItemManagement::updatePriceInDatabase(const QString &productName, const QString &brandName, const QString &newPriceCount) {
    if (!db.open()) {
        qDebug() << "Failed to open database connection:" << db.lastError().text();
    }

    int newCount = newPriceCount.toInt();
    QSqlQuery query;
    query.prepare("UPDATE products SET Price = ? WHERE LOWER(Name) = LOWER(?) AND LOWER(Brand) = LOWER(?)");
    query.bindValue(0, newCount);
    query.bindValue(1, productName);
    query.bindValue(2, brandName);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            return true;
        }
    }

    return false;
}

void ItemManagement::checkLowQuantityProducts() {
    lowQuantityProducts.clear();

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database:" << db.lastError().text();
        return;
    }

    QSqlQuery query("SELECT Name, Brand, Inventory FROM products WHERE Inventory < 15", db);
    while (query.next()) {
        QString productName = query.value(0).toString();
        QString brandName = query.value(1).toString();
        lowQuantityProducts.append(productName + " (" + brandName + ")");
    }

    db.close();
}

void ItemManagement::displayLowQuantityWarning() {
    if (!lowQuantityProducts.isEmpty()) {
        QMessageBox warningMsg;
        warningMsg.setWindowTitle("Low Inventory Warning");
        warningMsg.setIcon(QMessageBox::Warning);
        warningMsg.setText("The following products have inventory below 15:");
        QString productList;
        for (const QString& product : lowQuantityProducts) {
            productList += "- " + product + "\n";
        }
        warningMsg.setInformativeText(productList);
        warningMsg.exec();
    } else {
        QMessageBox::information(this, "Low Inventory", "No products have inventory below 15.");
    }
}

void ItemManagement::showLowQuantityProducts() {
    checkLowQuantityProducts();
    displayLowQuantityWarning();
}
