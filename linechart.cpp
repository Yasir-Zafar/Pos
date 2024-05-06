#include "linechart.h"

LineChart::LineChart(QWidget *parent) :
  QMainWindow(parent)
{
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("LineChart"));
    resize(800, 600);
    setWindowTitle(QStringLiteral("MainWindow"));

    setupChart();
}

void LineChart::setupChart()
{
    int sless1000 = 0;
    int sless5000 = 0;
    int sless10000 = 0;
    int sless20000 = 0;
    int sless50000 = 0;

    DB_connection_3 = QSqlDatabase::addDatabase("QSQLITE");
    DB_connection_3.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/SQL/products.db");

    if(DB_connection_3.open())
        qDebug() << "Database is connected";
    else
    {
        qDebug() << "Database is not connected";
        qDebug() << "Error:" << DB_connection_3.lastError();
    }

    DB_connection_3.open();
    QSqlDatabase::database().transaction();

    QSqlQuery q1, q2, q3, q4, q5;

    q1.prepare("SELECT SUM(Sold) FROM products WHERE Price <= 1000;");
    if (!q1.exec())
        qDebug() << "Query Error";
    if (q1.next())
        sless1000 = q1.value(0).toInt();

    q2.prepare("SELECT SUM(Sold) FROM products WHERE Price > 1000 AND Price <= 5000;");
    if (!q2.exec())
        qDebug() << "Query Error";
    if (q2.next())
        sless5000 = q2.value(0).toInt();

    q3.prepare("SELECT SUM(Sold) FROM products WHERE Price > 5000 AND Price <= 10000;");
    if (!q3.exec())
        qDebug() << "Query Error";
    if (q3.next())
        sless10000 = q3.value(0).toInt();

    q4.prepare("SELECT SUM(Sold) FROM products WHERE Price > 10000 AND Price <= 20000;");
    if (!q4.exec())
        qDebug() << "Query Error";
    if (q4.next())
        sless20000 = q4.value(0).toInt();

    q5.prepare("SELECT SUM(Sold) FROM products WHERE Price > 20000 AND Price <= 50000;");
    if (!q5.exec())
        qDebug() << "Query Error";
    if (q5.next())
        sless50000 = q5.value(0).toInt();

    QSqlDatabase::database().commit();

    QLineSeries *series = new QLineSeries;
    series->append(0, 0);
    series->append(1000, sless1000);
    series->append(5000, sless5000);
    series->append(10000, sless10000);
    series->append(20000, sless20000);
    series->append(50000, sless50000);

    QChart *chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 55000);
    chart->axes(Qt::Horizontal).first()->setTitleText("PRICE");
    chart->axes(Qt::Vertical).first()->setTitleText("SALES");

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartview);
}
