#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QApplication>
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

class Analysis : public QWidget
{
    Q_OBJECT

public:
    Analysis(QWidget *parent = nullptr);
    void setupUi();
    void setupDb();

private slots:
    void  on_pushButton_clicked();

    void on_DisplayGraph_clicked();
private:
    QSqlDatabase DB_connection;
    QSqlDatabase DB_connection_2;

    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *DisplayGraph;
    QListWidget *listWidget;
    QLabel *label_7;
};

#endif // ANALYSIS_H
