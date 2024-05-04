#include "cart.h"
#include "shop.h"
#include "cartitem.h"

Cart::Cart(QWidget *parent)
    : QWidget(parent) {
    setupCart();
    setStyleSheet("background-color: #f0f0f0; color: #333333; border-radius: 20px;");
}

void Cart::setupCart() {
    cartWidget = new QWidget(this);
    cartWidget->setFixedWidth(420);

    mainLayout = new QVBoxLayout(cartWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Checkout Label
    QLabel *checkoutLabel = new QLabel("Checkout", cartWidget);
    checkoutLabel->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    mainLayout->addWidget(checkoutLabel, 0, Qt::AlignTop | Qt::AlignLeft);

    // Scroll Area
    lll = new QVBoxLayout;
    scrollArea = new QScrollArea(cartWidget);
    scrollArea->setStyleSheet("border-radius: 0px;");
    scrollAreaContentWidgets = new QWidget;
    mainLayout->addWidget(scrollArea);

    // Labels
    QHBoxLayout *totalAmountLayout = new QHBoxLayout();
    QLabel *totalAmountLabel = new QLabel("Total Amount:");
    totalAmountLabel->setFont(QFont("Arial Rounded", 15, QFont::Bold));
    totalAmountLayout->addWidget(totalAmountLabel);
    totalAmountLayout->setSpacing(20);

    QLabel *totalAmountValueLabel = new QLabel("Yasir istg khuda ka wasta");
    totalAmountLayout->addWidget(totalAmountValueLabel);
    mainLayout->addLayout(totalAmountLayout);

    QHBoxLayout *gstLayout = new QHBoxLayout();
    QLabel *gstLabel = new QLabel("GST: ");
    gstLabel->setFont(QFont("Arial Rounded", 12, QFont::Bold));
    gstLayout->addWidget(gstLabel);

    QLabel *gstValueLabel = new QLabel("16%");
    gstValueLabel->setFont(QFont("Arial Rounded", 13));
    gstLayout->addWidget(gstValueLabel);
    mainLayout->addLayout(gstLayout);

    QHBoxLayout *subtotalLayout = new QHBoxLayout();
    QLabel *subtotalLabel = new QLabel("Subtotal:");
    subtotalLabel->setFont(QFont("Arial Rounded", 12, QFont::Bold));
    subtotalLayout->addWidget(subtotalLabel);
    QLabel *subtotalValueLabel = new QLabel("YasirMakeGettersPlease");
    subtotalLayout->addWidget(subtotalValueLabel);
    mainLayout->addLayout(subtotalLayout);

    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *feedbackButton = new QPushButton("Feedback", cartWidget);
    feedbackButton->setFont(QFont("Arial Rounded", 12, QFont::Bold));
    feedbackButton->setStyleSheet("QPushButton {background-color: rgb(40, 164, 166); color: #333; border-style: outset; border-radius: 20px; padding: 0px;}");
    QPushButton *checkoutButton = new QPushButton("Checkout", cartWidget);
    checkoutButton->setFont(QFont("Arial Rounded", 12));
    checkoutButton->setStyleSheet("QPushButton { background-color: rgb(0, 204, 238); border-radius: 20px; }");
    // connect(checkoutButton, &QPushButton::clicked, this, &Cart::on_checkout_clicked);

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
    connect(cardButtons[i], &QPushButton::clicked, this, &Cart::on_pushButton_clicked);
}

void Cart::on_pushButton_clicked()
{
    count++;
    cartItem* temp = new cartItem(this, "Apples", 50);

    top = new QVBoxLayout(this);
    disconnect(temp->counter, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged(int)));

    // Connect valueChanged signal before retrieving the quantity
    connect(temp->counter, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged(int)));

    newWid.append(temp);

    top->addWidget(newWid[newWid.size() - 1]);
    scrollAreaContentWidgets->setLayout(top);

    // Set the scroll area widget as the widget for the scroll area
    lll->addLayout(top);
    scrollArea->setLayout(lll);
}

// void Cart::on_checkout_clicked()
// {
//     QMessageBox::StandardButton reply = QMessageBox::question(this, "Member Check", "Are You A Member", QMessageBox::Yes | QMessageBox::No);
//     if (reply == QMessageBox::Yes) {
//         qDebug() << "You a reaal nigga my G";
//         qDebug() << "Discount Added!";
//         totalAmount = totalAmount * (0.9);
//         ui->label_6->setText(QString::number(totalAmount));
//     }
//     else {
//         QMessageBox::critical(this, "Not a Member", "You're Not a Member Bitch ass Nigga");
//         this->close();
//     }
//     QLayoutItem *child;
//     while ((child = layout->takeAt(0)) != nullptr) {
//         if (child->widget()) {
//             delete child->widget();
//         }
//         delete child;
//     }
//     ui->scrollAreaWidgetContents->hide();
//     QSqlDatabase myindb = QSqlDatabase::addDatabase("QSQLITE");
//     myindb.setDatabaseName("sales.db");
//     if (myindb.open()) {
//         qDebug() << "DB is open";
//     }

//     int start = count;
//     for (int i = 0; i < itemName.size(); i++) {
//         QSqlQuery query(myindb);
//         query.prepare("INSERT INTO info "
//                       "VALUES (?, ?, ?);");
//         query.addBindValue(itemName[i]);
//         query.addBindValue(itemPrice[i]);
//         for (int j = start + 1; j < itemQuantity.size(); j++) {
//             qDebug() << "At index " << j << "  " << itemQuantity[j];
//             if (itemQuantity[j] == 1 && j > 3) {
//                 query.addBindValue(itemQuantity[j - 1]);
//                 qDebug() << itemQuantity[j - 1] << "break";
//                 start = j;
//                 break;
//             }
//             else if (j == itemQuantity.size() - 1) {
//                 query.addBindValue(itemQuantity[j]);
//                 qDebug() << itemQuantity[j] << "break";
//                 break;
//             }
//         }
//         query.exec();
//     }
//     itemName.clear();
//     itemPrice.clear();
//     itemQuantity.clear();
// }

// void Cart::onSpinBoxValueChanged(int newValue)
// {
//     spin++;
//     qDebug() << "New value of QSpinBox:" << newValue;
//     QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
//     int quantity = spinBox->value();
//     itemQuantity.append(quantity);
//     for (int i = 0; i < itemQuantity.size(); i++) {
//         qDebug() << itemQuantity[i];
//     }
// }

Cart::~Cart() {
    delete cartWidget;
}
