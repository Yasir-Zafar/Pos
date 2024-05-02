#ifndef SIGNUP_WINDOW_H
#define SIGNUP_WINDOW_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class signup_Window;
}
QT_END_NAMESPACE

class signup_Window : public QMainWindow
{
    Q_OBJECT

public:
    signup_Window(QWidget *parent = nullptr);
    ~signup_Window();

private slots:
    void on_pushButton_signup_clicked();

    void on_pushButton_login_clicked();

    int countPlaceholders(const QString &query) {
        int count = 0;
        int pos = 0;
        while ((pos = query.indexOf('?', pos)) != -1) {
            ++count;
            ++pos;
        }
        return count;
    }


private:
    Ui::signup_Window *ui;
};
#endif // SIGNUP_WINDOW_H
