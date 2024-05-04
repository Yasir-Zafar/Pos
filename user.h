#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileInfo>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>
#include <QHeaderView>

class User : public QWidget
{
    Q_OBJECT
public:
    explicit User(QWidget *parent = nullptr);
    void setupUser();
    void setAdmins();
    void setEmployees();
    void resettables();
    ~User();

private:
    QLabel *label;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *rem_1;

private slots:
    void on_pushButton_6_clicked();
};

#endif // USER_H
