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

signals:
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();
    void button4Clicked();
    void button5Clicked();

public slots:
    // Function to certain buttons that are unavailable to Employee
    void handleEmployeeLogin();

private slots:
    void onButton1Clicked();
    void onButton2Clicked();
    void onButton3Clicked();
    void onButton4Clicked();
    void onButton5Clicked();

private:
    // Function to create a sidebar button with an icon
    QPushButton* createSidebarButton(const QString& iconPath, const QSize& buttonSize, const QString& hoverStyleSheet);

    QFrame* frame;
    QVBoxLayout* sidebarLayout;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QPushButton* button5;
    QLabel* logoLabel;
};

#endif // SIDEBAR_H
