#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSqlError>
#include <QtSql/QSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include <QMessageBox>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);

private slots:
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();

private:
    void setupUi();
    void add_db_admin();
    void add_db_employee();
    int checklene();
    int checklena();
    bool emailcheck();

    QFrame *frame;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_6;
    QLabel *label_13;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
};

#endif // DIALOG_H
