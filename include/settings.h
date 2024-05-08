// settings.h
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QApplication>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>

#include <QFile>
#include <QMessageBox>

class Settings : public QWidget {
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    void setupUI();
    void backupSQLFiles();

private slots:
    void shutdownApp();

public slots:
    void handleEmployeeLogin();

private:
    QVBoxLayout *mainLayout;
    QPushButton *shutdownButton;
};

#endif // SETTINGS_H
