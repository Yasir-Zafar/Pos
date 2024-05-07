#ifndef REMOVEUSER_H
#define REMOVEUSER_H

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

class RemoveUser : public QDialog
{
    Q_OBJECT

public:
    RemoveUser(QWidget *parent = nullptr);
    // ~RemoveUser();

    void setupUi();
    int checkrow();
    int emailcheck2();
    bool emailcheck();
    void deladmin();
    void delemployee();

private slots:
    void on_rembutton_1_clicked();
    void on_rembutton_2_clicked();

private:
    QDialog *Remove;
    QFrame *frame;
    QLineEdit *remline_1;
    QLabel *label_9;
    QLabel *label_11;
    QPushButton *rembutton_2;
    QRadioButton *remradio_1;
    QRadioButton *remradio_2;
    QPushButton *rembutton_1;
};

#endif // REMOVEUSER_H
