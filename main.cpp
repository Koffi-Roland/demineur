#include "mainwindow.h"
#include "grille.h"

#include <QApplication>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
    Grille * grille = Grille::getInstance();
    grille->getCases();
=======

>>>>>>> 446cd8a98cc91e6ce32bbb625c456dc552c51521
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
