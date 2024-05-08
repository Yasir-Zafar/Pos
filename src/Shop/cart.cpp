#include "../../include/Shop/cart.h"
#include "../../include/Shop/cartitem.h"
#include "../../include/Shop/shop.h"

Cart::Cart(QWidget *parent)
    : QWidget(parent) {
    setupCart();
    totalAmount = 0;
    subtotal = 0;
    setStyleSheet("background-color: #f0f0f0; color: #333333; border-radius: 20px;");
}

void Cart::setupCart() {
    top = new QVBoxLayout;
    top->setAlignment(Qt::AlignTop);

    cartWidget = new QWidget(this);
    cartWidget->setFixedWidth(350);

    mainLayout = new QVBoxLayout(cartWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    QLabel *checkoutLabel = new QLabel("Checkout", cartWidget);
    checkoutLabel->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    mainLayout->addWidget(checkoutLabel, 0, Qt::AlignTop | Qt::AlignCenter);

    lll = new QVBoxLayout;
    scrollArea = new QScrollArea(cartWidget);
    scrollArea->setStyleSheet("border-radius: 0px; border: 2px black;");
    scrollArea->setFixedSize(350, 760);
    scrollAreaContentWidgets = new QWidget(scrollArea);
    scrollAreaContentWidgets->setMinimumSize(320, 800);
    scrollAreaContentWidgets->setLayout(top);
    scrollArea->setWidget(scrollAreaContentWidgets);
    mainLayout->addWidget(scrollArea, 1, Qt::AlignTop);
    mainLayout->addSpacing(20);

    QHBoxLayout *subtotalLayout = new QHBoxLayout();
    QLabel *subtotalLabel = new QLabel("Subtotal:");
    subtotalLabel->setFont(QFont("Arial Rounded", 14, QFont::Bold));
    subtotalLayout->addWidget(subtotalLabel);

    subtotalValueLabel = new QLabel(" ");
    subtotalValueLabel->setFont(QFont("Arial Rounded", 14, QFont::Bold));
    subtotalLayout->addWidget(subtotalValueLabel);
    mainLayout->addLayout(subtotalLayout);

    QHBoxLayout *gstLayout = new QHBoxLayout();
    QLabel *gstLabel = new QLabel("GST: ");
    gstLabel->setFont(QFont("Arial Rounded", 13, QFont::Bold));
    gstLayout->addWidget(gstLabel);

    QLabel *gstValueLabel = new QLabel("16%");
    gstValueLabel->setFont(QFont("Arial Rounded", 13));
    gstLayout->addWidget(gstValueLabel);
    mainLayout->addLayout(gstLayout);

    QHBoxLayout *totalAmountLayout = new QHBoxLayout();
    QLabel *totalAmountLabel = new QLabel("Total Amount:");
    totalAmountLabel->setFont(QFont("Arial Rounded", 15, QFont::Bold));
    totalAmountLayout->addWidget(totalAmountLabel);
    totalAmountLayout->setSpacing(20);

    totalAmountValueLabel = new QLabel(" ");
    totalAmountValueLabel->setFont(QFont("Arial Rounded", 15, QFont::Bold));
    totalAmountLayout->addWidget(totalAmountValueLabel);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(totalAmountLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *feedbackButton = new QPushButton("Feedback", cartWidget);
    feedbackButton->setFont(QFont("Arial Rounded", 12, QFont::Bold));
    feedbackButton->setStyleSheet("QPushButton {background-color: rgb(40, 164, 166); color: #333; border-style: outset; border-radius: 20px; padding: 10px;}");
    connect(feedbackButton, &QPushButton::clicked, this, &Cart::on_feedback_clicked);

    QPushButton *checkoutButton = new QPushButton("Checkout", cartWidget);
    checkoutButton->setFont(QFont("Arial Rounded", 12));
    checkoutButton->setStyleSheet("QPushButton { background-color: rgb(0, 204, 238); border-radius: 20px; padding: 10px; }");
    connect(checkoutButton, &QPushButton::clicked, this, &Cart::on_checkout_clicked);

    clearButton = new QPushButton("Clear Cart", cartWidget); // Create clear button
    clearButton->setFont(QFont("Arial Rounded", 12));
    clearButton->setStyleSheet("QPushButton { background-color: rgb(255, 0, 0); border-radius: 20px; padding: 10px; }");
    connect(clearButton, &QPushButton::clicked, this, &Cart::on_clear_clicked); // Connect signal to slot
    buttonLayout->addWidget(clearButton); // Add button to layout

    buttonLayout->addWidget(feedbackButton);
    buttonLayout->setSpacing(20);
    buttonLayout->addWidget(checkoutButton);

    mainLayout->addSpacing(20);
    mainLayout->addLayout(buttonLayout);
    cartWidget->setLayout(mainLayout);

    QVBoxLayout *cartLayout = new QVBoxLayout(this);
    cartLayout->addWidget(cartWidget);
    cartLayout->setContentsMargins(0, 0, 0, 0);
    cartLayout->setAlignment(Qt::AlignLeft);
    setLayout(cartLayout);

    for (int i = 0; i < cardButtons.size(); i++)
        connect(cardButtons[i], &QPushButton::clicked, this, [this, i] {on_pushButton_clicked(i);});
}

QString brand;

void Cart::on_pushButton_clicked(int i)
{
    name = productsArray[i].name;
    price = productsArray[i].price;
    brand = productsArray[i].brand;
    bool isPresent = false;
    int pre;
    for (int i = 0; i < itemName.size(); i++) {
        if (name == itemName[i] && brand == itemBrand[i]) {
            isPresent = true;
            pre = i;
            break;
        }
    }
    if (isPresent) {
        newWid[pre]->counter->setValue(newWid[pre]->counter->value() + 1);
    }
    else {
        cartItem* temp = new cartItem(this, name, price);
        newWid.append(temp);

        temp->counter->setButtonSymbols(QAbstractSpinBox::NoButtons);

        itemName.push_back(name);
        itemPrice.push_back(price);
        itemBrand.push_back(brand);
        itemQuantity.push_back(temp->counter->value());

        for (int j = 0; j < newWid.size(); j++) {
            connect(newWid[j]->counter,&QSpinBox::valueChanged , this, [this, j] {onSpinBoxValueChanged(j);});
        }

        top->addWidget(newWid[newWid.size() - 1]);
        scrollAreaContentWidgets->setLayout(top);
        scrollAreaContentWidgets->adjustSize();
    }
}

void Cart::on_checkout_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Member Check", "Are You A Member", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        totalAmount *= (0.9);
        totalAmountValueLabel->setText(QString::number(totalAmount));
        QMessageBox::information(this, "Member", "10% Discount added, Keep supporting us!");
    }

    // Prompt for discount percentage
    QMessageBox::StandardButton discountReply = QMessageBox::question(this, "Discount", "Would you like to apply a discount?", QMessageBox::Yes | QMessageBox::No);
    if (discountReply == QMessageBox::Yes) {
        bool ok;
        int discountPercent = QInputDialog::getInt(this, "Discount", "Enter discount percentage:", 0, 0, 100, 1, &ok);
        if (ok) {
            // Check for invalid discount percentage
            if (discountPercent < 0 || discountPercent > 100) {
                QMessageBox::warning(this, "Invalid Discount", "Please enter a valid discount percentage (0-100).");
                return;
            }

            // Calculate total amount with discount
            double discountFactor = 1.0 - (discountPercent / 100.0);
            totalAmount *= discountFactor;
            totalAmountValueLabel->setText(QString::number(totalAmount));
            QMessageBox::information(this, "Discount", QString::number(discountPercent) + "% Discount added.");
        }
    }

    // Check for gift card
    QMessageBox::StandardButton giftCardReply = QMessageBox::question(this, "Gift Card", "Do you have a gift card?", QMessageBox::Yes | QMessageBox::No);
    if (giftCardReply == QMessageBox::Yes) {
        totalAmount -= 5000;
        if (totalAmount < 0) {
            totalAmount = 0;
        }
        totalAmountValueLabel->setText(QString::number(totalAmount));
        QMessageBox::information(this, "Gift Card", "$5000 deducted from total.");
    }

    receipt = new Receipt;
    receipt->show();

    QSqlDatabase myindb = QSqlDatabase::addDatabase("QSQLITE");
    myindb.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/sales.db");
    if (myindb.open()) {
        qDebug() << "DB is open";
    }
    QSqlDatabase productsDb = QSqlDatabase::addDatabase("QSQLITE");
    productsDb.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/products.db");
    if (productsDb.open()) {
        qDebug() << "DB is open";
    }

    QSqlQuery initial(myindb);
    initial.exec("CREATE TABLE IF NOT EXISTS info (name TEXT, price INTEGER, quantity INTEGER);");

    for (int i = 0; i < itemName.size(); i++) {
        QSqlQuery query(myindb);
        QSqlQuery query2(productsDb);
        query.prepare("INSERT INTO info VALUES (?, ?, ?);");

        query.addBindValue(itemName[i]);
        query.addBindValue(itemPrice[i]);
        query.addBindValue(itemQuantity[i]);

        query.exec();
        QString trial = "UPDATE products SET Sold = Sold + " + QString::number(itemQuantity[i]) + ", Inventory = Inventory - " + QString::number(itemQuantity[i]) + " WHERE Name = '" + itemName[i] + "';";
        query2.exec(trial);
    }

    QSqlQuery checkoutQuery(productsDb);
    checkoutQuery.exec("CREATE TABLE IF NOT EXISTS checkout (totalAmount INTEGER);");

    checkoutQuery.prepare("INSERT INTO checkout (totalAmount) VALUES (:totalAmount);");
    checkoutQuery.bindValue(":totalAmount", totalAmount);
    checkoutQuery.exec();

    itemName.clear();
    itemPrice.clear();
    itemQuantity.clear();

    totalAmount = 0;
    totalAmountValueLabel->setText(QString::number(totalAmount));
    subtotal = 0;
    subtotalValueLabel->setText(QString::number(subtotal));

    for (int i = 0; i < newWid.size(); ++i) {
        delete newWid[i];
    }

    newWid.clear();
    top->update();
}

void Cart::on_feedback_clicked() {
    feed = new feedback;
    feed->show();
}

void Cart::onSpinBoxValueChanged(int i)
{
    int quant = newWid[i]->counter->value();
    int oldQuantity = itemQuantity[i];

    QSqlDatabase productsDb = QSqlDatabase::addDatabase("QSQLITE");
    productsDb.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/products.db");
    if (productsDb.open()) {
        qDebug() << "DB is open";
    }
    QSqlQuery query(productsDb);
    QString qu = "SELECT Inventory FROM products WHERE name = '" + itemName[i] + "';";
    query.exec(qu);
    if (query.next()) {
        if (query.value(0).toInt() <= oldQuantity) {
            QMessageBox::warning(this, "Stock Less", "The amount required exceeds the stock!");
            newWid[i]->counter->setValue(0);
            itemQuantity[i] = 0;
        }
        else {
            itemQuantity[i] = quant;
        }
    }

    subtotal -= (oldQuantity - itemQuantity[i]) * itemPrice[i];

    subtotalValueLabel->setText(QString::number(subtotal));

    totalAmount = subtotal + (0.16) * subtotal;

    totalAmountValueLabel->setText(QString::number(totalAmount));
    qDebug() << "Quantity of Button " << i << " " << itemQuantity[i];
}

void Cart::on_clear_clicked() {
    itemName.clear();
    itemPrice.clear();
    itemQuantity.clear();

    totalAmount = 0;
    totalAmountValueLabel->setText(QString::number(totalAmount));
    subtotal = 0;
    subtotalValueLabel->setText(QString::number(subtotal));

    for (int i = 0; i < newWid.size(); ++i) {
        delete newWid[i];
    }

    newWid.clear();
    top->update();
}

Cart::~Cart() {
    delete cartWidget;
}
