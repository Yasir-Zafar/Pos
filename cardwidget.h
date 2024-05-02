#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>

class QLabel;

class cardWidget: public QWidget
{
    Q_OBJECT
public:
    explicit cardWidget(QWidget* parent = nullptr);
private:
    QLabel* nameLabel;
    QLabel* brandLabel;
    QLabel* categoryLabel;
    QLabel* priceLabel;

    void setupUi();
    void loadData();
    void applyStyles();
};

#endif // CARDWIDGET_H
