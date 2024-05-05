#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QApplication>
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Analysis : public QWidget
{
    Q_OBJECT

public:
    Analysis(QWidget *parent = nullptr);
    void setupUi();
private:

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

QT_END_NAMESPACE

#endif // ANALYSIS_H
