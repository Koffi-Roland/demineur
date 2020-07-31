#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    grilleUI=new GrilleUI(this, 16, 16);
    grilleUI->setSpacing(0);
    grilleUI->setObjectName(QStringLiteral("grille"));
    grilleUI->setSizeConstraint(QLayout::SetNoConstraint);
}
