#ifndef SIDEBAR2_H
#define SIDEBAR2_H
#include<QtSql/QSql>
#include<QSqlDatabase>
#include<QFileInfo>
#include<QDebug>
#include<QSqlQuery>
#include<QString>
#include<QStringList>
#include <QMainWindow>
#include<QSqlError>
#include<QTableWidgetItem>
#include"dialog.h"
#include"remove.h"

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
    void setadmins();
    void setemployees();
    void resettables();
    static sidebar2& getInstance();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_rem_1_clicked();

private:
    Ui::sidebar2 *ui;
};
#endif // SIDEBAR2_H
