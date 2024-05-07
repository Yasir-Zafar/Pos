// settings.h
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QApplication>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>

class Settings : public QWidget {
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    void setupUI();

private slots:
    void shutdownApp();

public slots:
    void handleEmployeeLogin();

private:
    QVBoxLayout *mainLayout;
    QPushButton *shutdownButton;
    QPushButton *updateInventoryButton;
};

#endif // SETTINGS_H
