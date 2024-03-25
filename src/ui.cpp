#include "ui.h"
#include "Pos/mainwindow.h"
#include "Pos/ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow ( QWidget *parent )
    : QMainWindow ( parent ), ui ( new Ui::MainWindow )
{
    ui->setupUi ( this );

    // Connect the button click signal to a custom slot
    connect ( ui->pushButton, SIGNAL ( clicked () ), this,
              SLOT ( onButtonClick () ) );
}

MainWindow::~MainWindow () { delete ui; }

void MainWindow::onButtonClick ()
{
    QMessageBox::information ( this, "Button Clicked", "Niggers" );
}
