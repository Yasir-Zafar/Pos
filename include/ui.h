#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow ( QWidget *parent = nullptr );
    ~MainWindow ();

  private slots:
    void onButtonClick ();

  private:
    Ui::MainWindow *ui;
};

#endif
