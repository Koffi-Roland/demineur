#include "mainwindow.h"
#include "grille.h"

#include <QApplication>

int main(int argc, char *argv[])
{



   /* QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    QApplication app(argc, argv);
       MainWindow mainWindow;
       mainWindow.showNormal();
    return app.exec();
}
