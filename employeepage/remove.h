#ifndef REMOVE_H
#define REMOVE_H

#include <QDialog>
#include<QSqlError>
#include<QtSql/QSql>
#include<QSqlDatabase>
#include<QFileInfo>
#include<QDebug>
#include<QSqlQuery>
#include<QString>
#include<QStringList>
#include<QMessageBox>
#include <QDialog>
#include<regex>

namespace Ui {
class Remove;
}

class Remove : public QDialog
{
    Q_OBJECT

public:
    explicit Remove(QWidget *parent = nullptr);
    ~Remove();
    int checkrow();
    int emailcheck2();
    bool emailcheck();
    void deladmin();
    void delemployee();


private slots:

    void on_rembutton_2_clicked();

    void on_rembutton_1_clicked();

private:
    Ui::Remove *ui;
};

#endif // REMOVE_H
