#ifndef SIDEBAR2_H
#define SIDEBAR2_H
#include<QtSql/QSql>
#include<QSqlDatabase>
#include<QFileInfo>
#include<QDebug>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class sidebar2;
}
QT_END_NAMESPACE

class sidebar2 : public QMainWindow
{
    Q_OBJECT

public:
    sidebar2(QWidget *parent = nullptr);
    ~sidebar2();

private:
    Ui::sidebar2 *ui;
};
#endif // SIDEBAR2_H
