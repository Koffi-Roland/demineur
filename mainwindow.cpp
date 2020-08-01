#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralwidget = new QWidget(this);

    grilleUI=new GrilleUI(centralwidget, 16, 16, 50);
    grilleUI->setSpacing(0);
    grilleUI->setObjectName(QStringLiteral("grille"));
    grilleUI->setSizeConstraint(QLayout::SetNoConstraint);
    this->setCentralWidget(centralwidget);
}
