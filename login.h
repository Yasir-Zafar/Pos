#ifndef LOGIN_H
#define LOGIN_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    
signals:
    // Define the custom signal
    void loginSuccessful(QString username);
    

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

private:
    Ui::login *ui;
    QSqlDatabase empDB;
};

#endif // LOGIN_H