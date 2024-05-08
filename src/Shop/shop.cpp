#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "../../include/Shop/shop.h"

Shop::Shop(QWidget* parent) : QWidget(parent) {
    setupMenu();
}

void Shop::filterCards(const QString& searchText) {
    if (!cardsWidget) return;

    for (int i = 0; i < cardsWidget->layout()->count(); ++i) {
        QWidget* cardWidget = cardsWidget->layout()->itemAt(i)->widget();
        if (!cardWidget) continue;

        QLabel* nameLabel = cardWidget->findChild<QLabel*>("nameLabel");
        if (!nameLabel) continue;

        bool match = nameLabel->text().contains(searchText, Qt::CaseInsensitive);

        cardWidget->setVisible(match);
    }
}

void Shop::setupCards() {
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    cardsWidget = new QWidget(scrollArea);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/products.db");

    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QSqlQuery query("SELECT id, Name, Brand, Category, Price, Unit, Sold, Inventory FROM products");

    while (query.next()) {
        int id = query.value("id").toInt();
        QString productName = query.value("Name").toString();
        QString brand = query.value("Brand").toString();
        QString category = query.value("Category").toString();
        double price = query.value("Price").toDouble();
        int unit = query.value("Unit").toInt();
        int sold = query.value("Sold").toInt();
        int inventory = query.value("Inventory").toInt();

        // Create Product object and add it to the vector
        Product product{id, productName, brand, price, category, unit, sold, inventory};
        productsArray.push_back(product);
    }

    QGridLayout* gridLayout = new QGridLayout(cardsWidget);
    gridLayout->setContentsMargins(15, 15, 15, 15);
    gridLayout->setSpacing(57);
    gridLayout->setColumnStretch(6, 1);

    int row = 0;
    int column = 0;
    for (const Product& product : productsArray) {
        QPushButton* cardButton = new QPushButton;
        cardButton->setFixedSize(170, 170);
        QVBoxLayout* buttonLayout = new QVBoxLayout(cardButton);
        buttonLayout->setContentsMargins(10, 10, 10, 10);
        buttonLayout->setSpacing(0);

        QLabel* nameLabel = new QLabel(product.name);
        nameLabel->setObjectName("nameLabel");
        QLabel* brandLabel = new QLabel(product.brand);
        QLabel* priceLabel = new QLabel(QString("PKR%1").arg(QString::number(product.price, 'f', 2)));

        nameLabel->setStyleSheet("font-size: 18px; font-weight: bold; border: none; padding: 0;");
        brandLabel->setStyleSheet("font-size: 14px; color: #333333; border: none; padding: 0;");
        priceLabel->setStyleSheet("font-size: 12px; color: #333333; border: none; padding: 0;");

        nameLabel->setFixedHeight(45);
        brandLabel->setFixedHeight(15);
        priceLabel->setFixedHeight(15);

        nameLabel->setWordWrap(true);

        nameLabel->setAlignment(Qt::AlignHCenter);
        brandLabel->setAlignment(Qt::AlignHCenter);
        priceLabel->setAlignment(Qt::AlignHCenter);

        buttonLayout->addWidget(nameLabel);
        buttonLayout->addWidget(brandLabel);
        buttonLayout->addWidget(priceLabel);

        cardButton->setLayout(buttonLayout);

        cardButton->setStyleSheet("background-color: #f0f0f0;");
        cardButton->setStyleSheet("QPushButton { border: 6px solid #333333; } QPushButton:hover { border: 5px solid #28A4A6; }");

        gridLayout->addWidget(cardButton, row, column);

        cardButtons.append(cardButton);

        column++;
        if (column == 6) {
            row++;
            column = 0;
        }
    }

    db.close();

    cardsWidget->setLayout(gridLayout);
    scrollArea->setWidget(cardsWidget);
    topBoxLayout->addWidget(scrollArea);
}

void Shop::setupMenu() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    setStyleSheet("background-color: #ECECEC; border-radius: 20px;");

    QWidget* topWidget = new QWidget;
    topBoxLayout = new QVBoxLayout(topWidget);
    topBoxLayout->setContentsMargins(20, 20, 20, 20);

    QHBoxLayout* labelsAndSearchLayout = new QHBoxLayout;
    QVBoxLayout* labelsLayout = new QVBoxLayout;

    QLabel* welcomeLabel = new QLabel("Welcome");
    welcomeLabel->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    welcomeLabel->setFixedHeight(35);
    welcomeLabel->setStyleSheet("color: #333;");

    QLabel* discoverLabel = new QLabel("Discover any items you need");
    discoverLabel->setFont(QFont("Arial Rounded", 12));
    discoverLabel->setFixedHeight(40);
    discoverLabel->setStyleSheet("color: #878383;");

    QLabel* shopLabel = new QLabel("Shop");
    shopLabel->setFont(QFont("Arial Rounded", 16, QFont::Bold));
    shopLabel->setFixedHeight(50);

    labelsLayout->addWidget(welcomeLabel, 0, Qt::AlignTop | Qt::AlignLeft);
    labelsLayout->addWidget(discoverLabel, 0, Qt::AlignTop | Qt::AlignLeft);
    labelsLayout->addWidget(shopLabel, 0, Qt::AlignTop | Qt::AlignLeft);

    QLineEdit* searchBar = new QLineEdit;
    searchBar->setStyleSheet("border: 5px solid #CCCCCC; border-radius: 7px; padding: 5px;");
    searchBar->setPlaceholderText("Search");
    connect(searchBar, &QLineEdit::textChanged, this, &Shop::filterCards);

    labelsAndSearchLayout->addLayout(labelsLayout);
    labelsAndSearchLayout->addStretch();
    labelsAndSearchLayout->addWidget(searchBar, 0, Qt::AlignTop | Qt::AlignRight);

    topBoxLayout->addLayout(labelsAndSearchLayout);

    topWidget->setLayout(topBoxLayout);
    mainLayout->addWidget(topWidget, 1);

    setupCards();

    cart = new Cart(this);
    mainLayout->addWidget(cart);

    setLayout(mainLayout);
}

Shop::~Shop() {
    if (cart) {
        delete cart;
        cart = nullptr;
    }

    for (QPushButton* button : cardButtons) {
        delete button;
    }
    cardButtons.clear();

    if (topBoxLayout) {
        delete topBoxLayout;
        topBoxLayout = nullptr;
    }

    if (cardsWidget) {
        delete cardsWidget;
        cardsWidget = nullptr;
    }

    if (scrollArea) {
        delete scrollArea;
        scrollArea = nullptr;
    }
}
