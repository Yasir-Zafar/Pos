#ifndef LINECHART_H
#define LINECHART_H

#include <QMainWindow>
#include <QtSql>
#include <QChart>
#include <QLineSeries>
#include <QAbstractAxis>
#include <QValueAxis>
#include <QChartView>

class LineChart : public QMainWindow {
    Q_OBJECT

public:
    explicit LineChart(QWidget *parent = nullptr);

private:
    QWidget *centralwidget;
    void setupChart();

    QSqlDatabase DB_connection_3;
};

#endif // LINECHART_H
