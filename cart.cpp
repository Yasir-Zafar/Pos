#include "cart.h"
#include "shop.h"

Cart::Cart(QWidget *parent)
    : QWidget(parent) {
    setupCart();
}

void Cart::setupCart() {
    cartWidget = new QWidget(this);
    cartWidget->setFixedWidth(420);

    QVBoxLayout *mainLayout = new QVBoxLayout(cartWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Checkout Label
    QLabel *checkoutLabel = new QLabel("Checkout", cartWidget);
    checkoutLabel->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    mainLayout->addWidget(checkoutLabel, 0, Qt::AlignTop | Qt::AlignLeft);

    // Scroll Area
    QScrollArea *scrollArea = new QScrollArea(cartWidget);
    scrollArea->setStyleSheet("border-radius: 0px;");
    QWidget *scrollAreaWidgetContents = new QWidget();
    scrollArea->setWidget(scrollAreaWidgetContents);
    mainLayout->addWidget(scrollArea);

    // Labels
    QHBoxLayout *gstLayout = new QHBoxLayout();
    QLabel *gstLabel = new QLabel("GST: ");
    gstLabel->setFont(QFont("", 14, QFont::Bold));
    gstLayout->addWidget(gstLabel);
    QLabel *gstValueLabel = new QLabel("16%");
    gstValueLabel->setFont(QFont("", 14, QFont::Bold));
    gstLayout->addWidget(gstValueLabel);
    mainLayout->addLayout(gstLayout);

    QHBoxLayout *totalAmountLayout = new QHBoxLayout();
    QLabel *totalAmountLabel = new QLabel("Total Amount:");
    totalAmountLabel->setFont(QFont("", 14, QFont::Bold));
    totalAmountLayout->addWidget(totalAmountLabel);
    QLabel *totalAmountValueLabel = new QLabel("Yasir istg khuda ka wasta");
    totalAmountLayout->addWidget(totalAmountValueLabel);
    mainLayout->addLayout(totalAmountLayout);

    QHBoxLayout *subtotalLayout = new QHBoxLayout();
    QLabel *subtotalLabel = new QLabel("Subtotal:");
    subtotalLabel->setFont(QFont("", 14, QFont::Bold));
    subtotalLayout->addWidget(subtotalLabel);
    QLabel *subtotalValueLabel = new QLabel("YasirMakeGettersPlease");
    subtotalLayout->addWidget(subtotalValueLabel);
    mainLayout->addLayout(subtotalLayout);

    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *feedbackButton = new QPushButton("Feedback", cartWidget);
    feedbackButton->setStyleSheet("background-color: rgb(40, 164, 166); color: rgb(255, 255, 255); border-radius: 20px; margin: 5 10px;");
    QPushButton *checkoutButton = new QPushButton("Checkout", cartWidget);
    checkoutButton->setStyleSheet("background-color: rgb(0, 204, 238); border-radius: 20px; margin: 5 10px;");

    buttonLayout->addWidget(feedbackButton);
    buttonLayout->addWidget(checkoutButton);
    mainLayout->addLayout(buttonLayout);

    cartWidget->setLayout(mainLayout);

    QVBoxLayout *cartLayout = new QVBoxLayout(this);
    cartLayout->addWidget(cartWidget);
    cartLayout->setContentsMargins(0, 0, 0, 0);
    cartLayout->setAlignment(Qt::AlignLeft);
    setLayout(cartLayout);

    for (int i = 0; i < cardButtons.size(); i++)
    connect(cardButtons[i], &QPushButton::clicked, this, &Cart::on_pushButton_clicked);
}

void Cart::on_pushButton_clicked()
{
    count++;
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    ui->scrollAreaWidgetContents->show();
    qDebug() << senderButton->layout()->dynamicPropertyNames();
    price = senderButton->property("priceLabel").toString();
    newWid = new cartItem(this, name, price);
    QVBoxLayout *top = new QVBoxLayout;
    disconnect(newWid->counter, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged(int)));

    // Connect valueChanged signal before retrieving the quantity
    connect(newWid->counter, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged(int)));

    // Retrieve quantity from the QSpinBox and store it in the vector
    int quantity = newWid->counter->value();
    itemQuantity.append(quantity);

    top->addWidget(newWid);
    layout->addLayout(top);
    // Store item information in vectors
    itemName.append(name);
    itemPrice.append(price);
}

void Cart::on_checkout_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Member Check", "Are You A Member", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "You a reaal nigga my G";
        qDebug() << "Discount Added!";
        totalAmount = totalAmount * (0.9);
        ui->label_6->setText(QString::number(totalAmount));
    }
    else {
        QMessageBox::critical(this, "Not a Member", "You're Not a Member Bitch ass Nigga");
        this->close();
    }
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }
    ui->scrollAreaWidgetContents->hide();
    QSqlDatabase myindb = QSqlDatabase::addDatabase("QSQLITE");
    myindb.setDatabaseName("sales.db");
    if (myindb.open()) {
        qDebug() << "DB is open";
    }

    int start = count;
    for (int i = 0; i < itemName.size(); i++) {
        QSqlQuery query(myindb);
        query.prepare("INSERT INTO info "
                      "VALUES (?, ?, ?);");
        query.addBindValue(itemName[i]);
        query.addBindValue(itemPrice[i]);
        for (int j = start + 1; j < itemQuantity.size(); j++) {
            qDebug() << "At index " << j << "  " << itemQuantity[j];
            if (itemQuantity[j] == 1 && j > 3) {
                query.addBindValue(itemQuantity[j - 1]);
                qDebug() << itemQuantity[j - 1] << "break";
                start = j;
                break;
            }
            else if (j == itemQuantity.size() - 1) {
                query.addBindValue(itemQuantity[j]);
                qDebug() << itemQuantity[j] << "break";
                break;
            }
        }
        query.exec();
    }
    itemName.clear();
    itemPrice.clear();
    itemQuantity.clear();
}

void Cart::onSpinBoxValueChanged(int newValue)
{
    spin++;
    qDebug() << "New value of QSpinBox:" << newValue;
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    int quantity = spinBox->value();
    itemQuantity.append(quantity);
    for (int i = 0; i < itemQuantity.size(); i++) {
        qDebug() << itemQuantity[i];
    }
}
