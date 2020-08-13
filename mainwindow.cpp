#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>
#include <QTimer>
#include <string>


void MainWindow::chrono(){
    grilleUI->setTempsEcoule();
}

void MainWindow::initialiser(size_t ligne,size_t colonne,size_t nombreMines){

    QWidget *centralwidget = new QWidget(this);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    centralwidget->setFont(font);
    QGridLayout *gridLayoutGlobal = new QGridLayout(centralwidget);
    gridLayoutGlobal->setSpacing(0);

    grilleUI=new GrilleUI(this, ligne, colonne, nombreMines);

    gridLayoutGlobal->addLayout(grilleUI->getZoneLabel(), 0, 0, 1, 1);


    gridLayoutGlobal->addLayout(grilleUI,1, 0, 1, 1);


    int marge= int((this->geometry().width()-gridLayoutGlobal->geometry().width())/2);

    this->setContentsMargins(marge ,0,marge, 0);

    this->setCentralWidget(centralwidget);

    connect(grilleUI->getDebutant(), SIGNAL(clicked()),
               this, SIGNAL(jouerModeDebutant()));

  /*  QObject::connect(grilleUI->getDebutant(), SIGNAL(), this,SLOT(jouerModeDebutant()));
    QObject::connect(grilleUI->getMoyen(), SIGNAL(), this,SLOT(jouerModeDebutant()));
    QObject::connect(grilleUI->getExpert(), SIGNAL(), this,SLOT(jouerModeDebutant()));
    QObject::connect(grilleUI->getNouvellePartie(), SIGNAL(), this,SLOT(jouerModeDebutant()));*/



    /* Partie timer*/
    QObject::connect(grilleUI->getTimer(), SIGNAL(timeout()), this,SLOT(chrono()));
    grilleUI->getTimer()->start();
}

void MainWindow::jouerModeDebutant(){
   grilleUI->initialiser(this,9, 9, 10);
}



void MainWindow::jouerModeMoyen(){
      grilleUI->initialiser(this,16, 16, 40);


}

void MainWindow::jouerModeExpert(){
      grilleUI->initialiser(this,16, 30, 99);

}


void MainWindow::rejouer(){
    grilleUI->rejouer();
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    this->resize(800, 600);
    // this->setFixedSize(800,600);
    this->setWindowIcon(QIcon(":/resources/img/bombe_.png"));

    initialiser(0, 0, 0);
    jouerModeExpert();
    this->show();
}
