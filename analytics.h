#ifndef ANALYTICS_H
#define ANALYTICS_H
#include<QtSql>
#include <QMainWindow>
#include<QtCharts>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void  on_pushButton_clicked();

    void on_DisplayGraph_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_connection;
};
#endif // ANALYTICS_H