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
    QPushButton* getThirdButton();

signals:
    void thirdButtonClicked();

private slots:
    void handleThirdButtonClick();

private:
    void setupUI();
    QPushButton* createSidebarButton(const QString& iconPath, const QSize& buttonSize, const QString& hoverStyleSheet);

    QFrame* frame; // Container frame
    QVBoxLayout* sidebarLayout;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QLabel* logoLabel;
};

#endif // SIDEBAR_H
