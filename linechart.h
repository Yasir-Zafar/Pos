#ifndef LINECHART_H
#define LINECHART_H
#include<QtSql>
#include <QMainWindow>
#include<QChart>
#include<QLineSeries>
#include<QAbstractAxis>
#include<QValueAxis>
#include<QChartView>
namespace Ui {
class LineChart;
}

class LineChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit LineChart(QWidget *parent = nullptr);
    ~LineChart();

private:
    Ui::LineChart *ui;
    QSqlDatabase DB_connection_3;
};

#endif // LINECHART_H
