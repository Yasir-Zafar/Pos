#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextBlock>
#include <QTextEdit>
#include <QPushButton>

class feedback : public QWidget
{
    Q_OBJECT

public:
    explicit feedback(QWidget *parent = nullptr);
    void setupUi();

private slots:
    void on_pushButton_clicked();

private:
    QLabel* name_label;
    QLabel* email_label;
    QLabel* phone_label;
    QLineEdit* name_lineEdit;
    QLineEdit* phone_LineEdit;
    QLineEdit* email_lineEdit;
    QRadioButton** rating;
    QPushButton* pushButton;
    QTextEdit* addFeed;
    QVBoxLayout* mainLayout;
};

#endif // FEEDBACK_H
