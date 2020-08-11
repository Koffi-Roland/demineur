#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>
#include <QTimer>
#include <string>


void MainWindow::chrono(){
    grilleUI->setTempsEcoule();
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    this->resize(800, 600);
    // this->setFixedSize(800,600);
    this->setWindowIcon(QIcon(":/resources/img/bombe_.png"));


    QWidget *centralwidget = new QWidget(this);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    centralwidget->setFont(font);
    QGridLayout *gridLayoutGlobal = new QGridLayout(centralwidget);
    gridLayoutGlobal->setSpacing(0);


    grilleUI=new GrilleUI(this, 15, 20, 40);
    grilleUI->setSpacing(0);

    gridLayoutGlobal->addLayout(grilleUI->getZoneLabel(), 0, 0, 1, 1);



    gridLayoutGlobal->addLayout(grilleUI,1, 0, 1, 1);


    int marge= int((this->geometry().width()-gridLayoutGlobal->geometry().width())/2);

    this->setContentsMargins(marge ,0,marge, 0);

    this->setCentralWidget(centralwidget);

    /* Partie timer*/
    QObject::connect(grilleUI->getTimer(), SIGNAL(timeout()), this,SLOT(chrono()));
    grilleUI->getTimer()->start();

    this->show();
}
