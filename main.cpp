#include "mainwindow.h"
#include "grille.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    Grille * grille = Grille::getInstance();
    grille->getCases();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
