#include "Pos/mainwindow.h"
#include "pos.h"
#include <QApplication>

int main ( int argc, char *argv [] )
{
    PointOfSale posSystem;
    QApplication a ( argc, argv );
    MainWindow w;
    w.show ();
    return a.exec ();

    return 1;
}
