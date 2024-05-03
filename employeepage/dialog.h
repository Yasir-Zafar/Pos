#ifndef DIALOG_H
#define DIALOG_H
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
#include"sidebar2.h"
#include<regex>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void add_db_admin();
    void add_db_employee();
    int checklene();
    int checklena();
    bool emailcheck();


private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
