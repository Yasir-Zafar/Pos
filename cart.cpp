#include "cart.h"
#include "shop.h"
#include "cartitem.h"

Cart::Cart(QWidget *parent)
    : QWidget(parent) {
    setupCart();
    totalAmount = 0;
    subtotal = 0;
    setStyleSheet("background-color: #f0f0f0; color: #333333; border-radius: 20px;");
    // itemName.resize(0);
    // itemPrice.resize(0);
    // itemQuantity.resize(0);
}

void Cart::setupCart() {
    top = new QVBoxLayout;
    top->setAlignment(Qt::AlignTop);

    cartWidget = new QWidget(this);
    cartWidget->setFixedWidth(350);

    mainLayout = new QVBoxLayout(cartWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Checkout Label
    QLabel *checkoutLabel = new QLabel("Checkout", cartWidget);
    checkoutLabel->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    checkoutLabel->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(checkoutLabel, 0, Qt::AlignTop | Qt::AlignCenter);

    // Scroll Area
    lll = new QVBoxLayout;
    scrollArea = new QScrollArea(cartWidget);
    scrollArea->setFixedSize(350, 500);
    scrollAreaContentWidgets = new QWidget(scrollArea);
    scrollAreaContentWidgets->setMinimumSize(320, 700);
    scrollAreaContentWidgets->setLayout(top);
    scrollArea->setWidget(scrollAreaContentWidgets);
    scrollArea->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(scrollArea,0,Qt::AlignTop);

    // Labels
    QHBoxLayout *totalAmountLayout = new QHBoxLayout();
    QLabel *totalAmountLabel = new QLabel("Total Amount:");
    totalAmountLabel->setFont(QFont("Arial Rounded", 15, QFont::Bold));
    totalAmountLayout->addWidget(totalAmountLabel);
    totalAmountLayout->setSpacing(20);

    totalAmountValueLabel = new QLabel(" ");
    totalAmountLayout->addWidget(totalAmountValueLabel);
    mainLayout->addLayout(totalAmountLayout);

    QHBoxLayout *gstLayout = new QHBoxLayout();
    QLabel *gstLabel = new QLabel("GST: ");
    gstLabel->setFont(QFont("Arial Rounded", 12, QFont::Bold));
    gstLayout->addWidget(gstLabel);

    QLabel *gstValueLabel = new QLabel("16%");
    gstValueLabel->setFont(QFont("Arial Rounded", 11));
    gstLayout->addWidget(gstValueLabel);
    mainLayout->addLayout(gstLayout);

    QHBoxLayout *subtotalLayout = new QHBoxLayout();
    QLabel *subtotalLabel = new QLabel("Subtotal:");
    subtotalLabel->setFont(QFont("Arial Rounded", 12, QFont::Bold));
    subtotalLayout->addWidget(subtotalLabel);
    subtotalValueLabel = new QLabel(" ");
    subtotalLayout->addWidget(subtotalValueLabel);
    mainLayout->addLayout(subtotalLayout);

    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *feedbackButton = new QPushButton("Feedback", cartWidget);
    feedbackButton->setFont(QFont("Arial Rounded", 12, QFont::Bold));
    feedbackButton->setStyleSheet("QPushButton {background-color: rgb(40, 164, 166); color: #333; border-style: outset; border-radius: 20px; padding: 10px;}");
    QPushButton *checkoutButton = new QPushButton("Checkout", cartWidget);
    checkoutButton->setFont(QFont("Arial Rounded", 12));
    checkoutButton->setStyleSheet("QPushButton { background-color: rgb(0, 204, 238); border-radius: 20px; padding: 10px; }");
    connect(checkoutButton, &QPushButton::clicked, this, &Cart::on_checkout_clicked);

    buttonLayout->addWidget(feedbackButton);
    buttonLayout->setSpacing(20);
    buttonLayout->addWidget(checkoutButton);

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
    cartItem* temp = new cartItem(this, name, price);
    newWid.append(temp);
    itemName.push_back(name);
    itemPrice.push_back(price);
    itemBrand.push_back(brand);
    itemQuantity.push_back(temp->counter->value());
    for (int j = 0; j < newWid.size(); j++) {
        connect(newWid[j]->counter,&QSpinBox::valueChanged , this, [this, j] {onSpinBoxValueChanged(j);});
    }
    top->addWidget(newWid[newWid.size() - 1]); // Add the new widget to the existing layout
    scrollAreaContentWidgets->setLayout(top);
    // scrollAreaContentWidgets->adjustSize();
}

void Cart::on_checkout_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Member Check", "Are You A Member", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        totalAmount = totalAmount * (0.9);
        totalAmountValueLabel->setText(QString::number(totalAmount));
        QMessageBox::information(this, "Member", "10% Discount added, Keep supporting us!");

    }
    receipt = new Receipt;
    receipt->show();

    // Inserting into Database
    QSqlDatabase myindb = QSqlDatabase::addDatabase("QSQLITE");
    myindb.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/SQL/sales.db");
    if (myindb.open()) {
        qDebug() << "DB is open";
    }
    QSqlQuery initial(myindb);
    initial.exec("CREATE TABLE IF NOT EXISTS info (name TEXT, price INTEGER, quantity INTEGER);");

    for (int i = 0; i < itemName.size(); i++) {
        QSqlQuery query(myindb);
        query.prepare("INSERT INTO info "
                      "VALUES (?, ?, ?);");
        query.addBindValue(itemName[i]);
        query.addBindValue(itemPrice[i]);
        query.addBindValue(itemQuantity[i]);
        query.exec();
    }

    // Clearing cart
    itemName.clear();
    itemPrice.clear();
    itemQuantity.clear();
    totalAmount = 0;
    totalAmountValueLabel->setText(QString::number(totalAmount));
    subtotal = 0;
    subtotalValueLabel->setText(QString::number(subtotal));
    for (int i = 0; i < newWid.size(); ++i) {
        delete newWid[i]; // Deleting the widget
    }
    newWid.clear();
    top->update(); // Update the layout
}


void Cart::onSpinBoxValueChanged(int i)
{
    int quant = newWid[i]->counter->value();
    int oldQuantity = itemQuantity[i];
    itemQuantity[i] = quant;
    subtotal -= (oldQuantity - itemQuantity[i]) * itemPrice[i]; // Subtract the difference from the subtotal
    // Update subtotal label
    subtotalValueLabel->setText(QString::number(subtotal));
    // Update total amount
    totalAmount = subtotal + (0.16) * subtotal;
    // Update total amount label
    totalAmountValueLabel->setText(QString::number(totalAmount));
    qDebug() << "Quantity of Button " << i << " " << itemQuantity[i];
}

Cart::~Cart() {
    delete cartWidget;
}
