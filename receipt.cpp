#include "receipt.h"

Receipt::Receipt(QWidget *parent) : QWidget(parent){
    // Set widget window size
    setFixedSize(800, 420);

    // Create QTableWidget
    QTableWidget *receipttable = new QTableWidget(this);

    // Set widget window size
    receipttable->setFixedSize(800, 300);

    // Hide scroll bars
    receipttable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    receipttable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Hide numbering of rows/cols
    receipttable->verticalHeader()->setVisible(false);

    // Set numrow,col
    receipttable->setColumnCount(5);

    // Set the headers for the table
    QStringList headerLabels = {"Name", "Brand", "Rate", "Quantity", "Amount"};
    receipttable->setHorizontalHeaderLabels(headerLabels);

    // Set column sizes

    for (int i = 0; i < receipttable->columnCount(); ++i) {
        receipttable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    // Set font
    QFont font("Arial Rounded MT Bold", 12);
    receipttable->setFont(font);

    // Set edit triggers
    receipttable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Adding items
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
    totalAmountLabel->setGeometry(10, 330, 120, 30);

    QFontMetrics metrics(totalAmountLabel->font());
    int textWidth = metrics.horizontalAdvance(totalAmountLabel->text());

    QLabel *totalAmountLabelValue = new QLabel(" PKR" + QString::number(totalAmount), this);
    totalAmountLabelValue->setFont(QFont("Arial Rounded MT Bold", 12));
    totalAmountLabelValue->setGeometry(10 + textWidth, 330, 130, 30);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(receipttable);
    layout->addWidget(totalAmountLabel);
    layout->addWidget(totalAmountLabelValue);
    setLayout(layout);
}
