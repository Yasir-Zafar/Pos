#ifndef RECEIPT_H
#define RECEIPT_H

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QStringList>
#include <QVBoxLayout>

class Receipt : public QWidget {
    Q_OBJECT

public:
    explicit Receipt(QWidget *parent = nullptr);
    void setupUI();

private:
    QVBoxLayout *mainLayout;
    QTableWidget *receipttable;
};

#endif // RECEIPT_H
