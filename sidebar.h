#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class Sidebar : public QWidget {
    Q_OBJECT

public:
    explicit Sidebar(QWidget* parent = nullptr);
    void setupUI();

private:
    QPushButton* createSidebarButton(const QString& iconPath, const QSize& buttonSize, const QString& hoverStyleSheet);

    QFrame* frame;
    QVBoxLayout* sidebarLayout;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QLabel* logoLabel;

signals:
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();

public slots:
    void handleEmployeeLogin();

private slots:
    void onButton1Clicked();
    void onButton2Clicked();
    void onButton3Clicked();
};

#endif // SIDEBAR_H
