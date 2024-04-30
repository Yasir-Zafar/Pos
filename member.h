#ifndef MEMBER_H
#define MEMBER_H
#include <QApplication>
#include <QWidget>
#include<ui_member.h>

namespace Ui {
class member;
}

class member : public QWidget
{
    Q_OBJECT

public:
    explicit member(QWidget* parent = nullptr);
    ~member();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::member* ui;
};

#endif // MEMBER_H
