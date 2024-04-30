#include "itemmenu.h"
#include "product.h"

QVector<Product> productsArray;

void setupCheckoutBar(QWidget* checkoutBar) {
    QVBoxLayout* checkoutLayout = new QVBoxLayout(checkoutBar);
    checkoutBar->setFixedWidth(350);

    QLabel* checkoutLabel = new QLabel("Checkout");
    checkoutLabel->setAlignment(Qt::AlignHCenter);
    QFont font = checkoutLabel->font();
    font.setPointSize(22);
    font.setBold(true);
    checkoutLabel->setFont(font);

    checkoutLayout->addWidget(checkoutLabel);
    checkoutLayout->addStretch();
    checkoutBar->setLayout(checkoutLayout);

    checkoutBar->setStyleSheet("background-color: #f0f0f0;");
}

void setupSidebar(QWidget* sidebar) {
    QVBoxLayout* sidebarLayout = new QVBoxLayout(sidebar);
    sidebar->setFixedWidth(150);
    sidebar->setStyleSheet("background-color: #f9f9f9; color: #333333; border-radius: 20px;");
    QSize buttonSize(75, 75);
    QString hoverStyleSheet = "QPushButton:hover { background-color: #ECECEC; }";

    QLabel* logoLabel = new QLabel;
    logoLabel->setText("POS");
    QFont font = logoLabel->font();
    font.setPointSize(25);
    font.setBold(true);
    logoLabel->setFont(font);
    logoLabel->setStyleSheet("color: #28A4A6;");
    logoLabel->setFixedSize(buttonSize);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(logoLabel, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    QPushButton* button1 = new QPushButton;
    button1->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/shopping-bag.png"));
    button1->setIconSize(QSize(60, 60));
    QVBoxLayout* layout1 = new QVBoxLayout;
    layout1->addWidget(button1);

    QPushButton* button2 = new QPushButton;
    button2->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/pie-chart.png"));
    button2->setIconSize(QSize(60, 60));
    QVBoxLayout* layout2 = new QVBoxLayout;
    layout2->addWidget(button2);

    QPushButton* button3 = new QPushButton;
    button3->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/user.png"));
    button3->setIconSize(QSize(60, 60));
    QVBoxLayout* layout3 = new QVBoxLayout;
    layout3->addWidget(button3);

    QPushButton* button4 = new QPushButton;
    button4->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/settings.png"));
    button4->setIconSize(QSize(60, 60));
    QVBoxLayout* layout4 = new QVBoxLayout;
    layout4->addWidget(button4);

    button1->setStyleSheet(hoverStyleSheet);
    button2->setStyleSheet(hoverStyleSheet);
    button3->setStyleSheet(hoverStyleSheet);
    button4->setStyleSheet(hoverStyleSheet);

    button1->setFixedSize(buttonSize);
    button2->setFixedSize(buttonSize);
    button3->setFixedSize(buttonSize);
    button4->setFixedSize(buttonSize);

    sidebarLayout->addLayout(layout1);
    sidebarLayout->addLayout(layout2);
    sidebarLayout->addLayout(layout3);
    sidebarLayout->addLayout(layout4);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button1, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button2, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button3, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    sidebarLayout->addStretch();

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button4, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    sidebar->setLayout(sidebarLayout);
}

void filterCards(const QString& searchText, QWidget* cardsWidget, QScrollArea* scrollArea) {
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

void setupCards(QWidget* bottomWidget, QLineEdit* searchBar) {
    QScrollArea* scrollArea = new QScrollArea(bottomWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QWidget* cardsWidget = new QWidget(scrollArea);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/boi/Projects/C++/Uni/OOP/Pos/SQL/products.db");

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
        Product product(id, productName, brand, price, category, unit, sold, inventory);
        productsArray.push_back(product);
    }

    QGridLayout* gridLayout = new QGridLayout(cardsWidget);
    gridLayout->setContentsMargins(15, 15, 15, 15);
    gridLayout->setSpacing(63);
    gridLayout->setColumnStretch(6, 1);

    int row = 0;
    int column = 0;
    for (const Product& product : productsArray) {
        QPushButton* cardButton = new QPushButton;
        cardButton->setFixedSize(170, 170); // Set the size of each button
        QVBoxLayout* buttonLayout = new QVBoxLayout(cardButton);
        buttonLayout->setContentsMargins(10, 10, 10, 10);
        buttonLayout->setSpacing(0);

        QLabel* nameLabel = new QLabel(product.name());
        nameLabel->setObjectName("nameLabel");
        QLabel* brandLabel = new QLabel(product.brand());
        QLabel* priceLabel = new QLabel(QString("$%1").arg(QString::number(product.price(), 'f', 2)));

        nameLabel->setStyleSheet("font-size: 16px; font-weight: bold; border: none; padding: 0;");
        brandLabel->setStyleSheet("color: #333333; border: none; padding: 0;");
        priceLabel->setStyleSheet("color: #333333; border: none; padding: 0;");

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
        cardButton->setStyleSheet("QPushButton { border: 7px solid #333333; } QPushButton:hover { border: 7px solid #28A4A6; }");

        gridLayout->addWidget(cardButton, row, column);

        column++;
        if (column == 6) {
            row++;
            column = 0;
        }
    }

    db.close();

    cardsWidget->setLayout(gridLayout);

    scrollArea->setWidget(cardsWidget);

    QVBoxLayout* layout = new QVBoxLayout(bottomWidget);
    layout->addWidget(scrollArea);
    bottomWidget->setLayout(layout);

    QObject::connect(searchBar, &QLineEdit::textChanged, [=](const QString &text) {
        filterCards(text, cardsWidget, scrollArea);
    });
}

void setupMenu(QWidget* menu) {
    QVBoxLayout* menuLayout = new QVBoxLayout(menu);
    menu->setStyleSheet("background-color: #ECECEC; border-radius: 20px;");

    QWidget* topWidget = new QWidget;
    QVBoxLayout* topLayout = new QVBoxLayout(topWidget);
    topLayout->setContentsMargins(20, 20, 20, 20);

    QHBoxLayout* labelsAndSearchLayout = new QHBoxLayout;
    QVBoxLayout* labelsLayout = new QVBoxLayout;

    QLabel* welcomeLabel = new QLabel;
    welcomeLabel->setText("Welcome");
    QFont welcomeFont = welcomeLabel->font();
    welcomeFont.setPointSize(18);
    welcomeFont.setBold(true);
    welcomeLabel->setFont(welcomeFont);
    welcomeLabel->setFixedSize(230, 40);
    welcomeLabel->setStyleSheet("color: #333333;");

    QLabel* discoverLabel = new QLabel;
    discoverLabel->setText("Discover any items you need");
    QFont discoverFont = discoverLabel->font();
    discoverFont.setPointSize(12);
    discoverLabel->setFont(discoverFont);
    discoverLabel->setContentsMargins(0, 0, 0, 0);
    discoverLabel->setStyleSheet("color: #878383;");

    welcomeLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    discoverLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    labelsLayout->addWidget(welcomeLabel);
    labelsLayout->addWidget(discoverLabel);

    QLineEdit* searchBar = new QLineEdit;
    searchBar->setStyleSheet("border: 2px solid #CCCCCC; border-radius: 10px; padding: 5px;");
    searchBar->setPlaceholderText("Slave auction search");

    labelsAndSearchLayout->addLayout(labelsLayout);
    labelsAndSearchLayout->addStretch();
    labelsAndSearchLayout->addWidget(searchBar, 0, Qt::AlignTop | Qt::AlignRight);

    topLayout->addLayout(labelsAndSearchLayout);

    QLabel* categoriesLabel = new QLabel("Categories");
    categoriesLabel->setFont(QFont("Arial", 16, QFont::Bold));
    categoriesLabel->setContentsMargins(0, 40, 0, 0);
    topLayout->addWidget(categoriesLabel, 0, Qt::AlignTop | Qt::AlignLeft);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->setContentsMargins(0, 0, 0, 0);
    // Button 1
    QPushButton* button1 = new QPushButton;
    QIcon icon1("/home/boi/Projects/C++/Uni/OOP/Pos/img/n.png");
    button1->setIcon(icon1);
    button1->setIconSize(QSize(50, 50));
    button1->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout1 = new QVBoxLayout;
    buttonLayout1->setAlignment(Qt::AlignCenter);
    buttonLayout1->addWidget(button1);
    QLabel* captionLabel1 = new QLabel("Caption 1");
    captionLabel1->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel1->setAlignment(Qt::AlignCenter);
    buttonLayout1->addWidget(captionLabel1);

    // Button 2
    QPushButton* button2 = new QPushButton;
    QIcon icon2("/home/boi/Projects/C++/Uni/OOP/Pos/img/i.png");
    button2->setIcon(icon2);
    button2->setIconSize(QSize(50, 50));
    button2->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout2 = new QVBoxLayout;
    buttonLayout2->setAlignment(Qt::AlignCenter);
    buttonLayout2->addWidget(button2);
    QLabel* captionLabel2 = new QLabel("Caption 2");
    captionLabel2->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel2->setAlignment(Qt::AlignCenter);
    buttonLayout2->addWidget(captionLabel2);

    // Button 3
    QPushButton* button3 = new QPushButton;
    QIcon icon3("/home/boi/Projects/C++/Uni/OOP/Pos/img/g.png");
    button3->setIcon(icon3);
    button3->setIconSize(QSize(50, 50));
    button3->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout3 = new QVBoxLayout;
    buttonLayout3->setAlignment(Qt::AlignCenter);
    buttonLayout3->addWidget(button3);
    QLabel* captionLabel3 = new QLabel("Caption 3");
    captionLabel3->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel3->setAlignment(Qt::AlignCenter);
    buttonLayout3->addWidget(captionLabel3);

    // Button 4
    QPushButton* button4 = new QPushButton;
    QIcon icon4("/home/boi/Projects/C++/Uni/OOP/Pos/img/g.png");
    button4->setIcon(icon4);
    button4->setIconSize(QSize(50, 50));
    button4->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout4 = new QVBoxLayout;
    buttonLayout4->setAlignment(Qt::AlignCenter);
    buttonLayout4->addWidget(button4);
    QLabel* captionLabel4 = new QLabel("Caption 4");
    captionLabel4->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel4->setAlignment(Qt::AlignCenter);
    buttonLayout4->addWidget(captionLabel4);

    // Button 5
    QPushButton* button5 = new QPushButton;
    QIcon icon5("/home/boi/Projects/C++/Uni/OOP/Pos/img/a.png");
    button5->setIcon(icon5);
    button5->setIconSize(QSize(50, 50));
    button5->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout5 = new QVBoxLayout;
    buttonLayout5->setAlignment(Qt::AlignCenter);
    buttonLayout5->addWidget(button5);
    QLabel* captionLabel5 = new QLabel("Caption 5");
    captionLabel5->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel5->setAlignment(Qt::AlignCenter);
    buttonLayout5->addWidget(captionLabel5);

    buttonsLayout->addLayout(buttonLayout1);
    buttonsLayout->addLayout(buttonLayout2);
    buttonsLayout->addLayout(buttonLayout3);
    buttonsLayout->addLayout(buttonLayout4);
    buttonsLayout->addLayout(buttonLayout5);

    topLayout->addLayout(buttonsLayout);

    topWidget->setLayout(topLayout);
    menuLayout->addWidget(topWidget);

    QWidget* bottomWidget = new QWidget;

    topWidget->setFixedHeight(350);

    setupCards(bottomWidget, searchBar);

    menuLayout->addWidget(topWidget);
    menuLayout->addWidget(bottomWidget);

    menu->setLayout(menuLayout);
}
