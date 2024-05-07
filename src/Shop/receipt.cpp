#include "../../include/Shop/cartitem.h"
#include "../../include/Shop/receipt.h"

Receipt::Receipt(QWidget *parent) : QWidget(parent){
    setFixedSize(800, 420);

    QTableWidget *receipttable = new QTableWidget(this);

    receipttable->setFixedSize(780, 300);

    receipttable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    receipttable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    receipttable->verticalHeader()->setVisible(false);

    receipttable->setColumnCount(5);

    QStringList headerLabels = {"Name", "Brand", "Rate", "Quantity", "Amount"};
    receipttable->setHorizontalHeaderLabels(headerLabels);

    for (int i = 0; i < receipttable->columnCount(); ++i) {
        receipttable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    QFont font("Arial Rounded MT Bold", 12);
    receipttable->setFont(font);

    receipttable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < itemName.size(); i++)
    {
        int row = receipttable->rowCount();
        receipttable->insertRow(row);
        for (int j = 0; j < 5; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            if (j == 0)
                item->setText(itemName[i]);
            else if (j == 1)
                item->setText(itemBrand[i]);
            else if (j == 2)
                item->setText(QString::number(itemPrice[i]));
            else if (j == 3)
                item->setText(QString::number(itemQuantity[i]));
            else if (j == 4)
                item->setText(QString::number(itemPrice[i] * itemQuantity[i]));
            receipttable->setItem(row, j, item);
        }
    }

    QLabel *totalAmountLabel = new QLabel("Total Amount:", this);
    totalAmountLabel->setFont(QFont("Arial Rounded MT Bold", 12));

    QLabel *totalAmountLabelValue = new QLabel(" PKR" + QString::number(totalAmount), this);
    totalAmountLabelValue->setFont(QFont("Arial Rounded MT Bold", 12));

    QHBoxLayout *totalAmountLayout = new QHBoxLayout();
    totalAmountLayout->addWidget(totalAmountLabel);
    totalAmountLayout->addWidget(totalAmountLabelValue);
    totalAmountLayout->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(receipttable);
    layout->addLayout(totalAmountLayout);
    setLayout(layout);
}
