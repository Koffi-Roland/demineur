#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>
#include <QTimer>
#include <string>


void MainWindow::chrono(){
    // grilleUI->setTempsEcoule();
}

void MainWindow::jouer()
{
    presentation->jouer();
}

void MainWindow::initialiser() {

    QWidget *centralwidget = new QWidget(this);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    centralwidget->setFont(font);
    QGridLayout *gridLayoutGlobal = new QGridLayout(centralwidget);
    gridLayoutGlobal->setSpacing(0);

    presentation = new Presentation (centralwidget, this);
    gridLayoutGlobal->addLayout(presentation,1, 0, 1, 1);

    this->setCentralWidget(centralwidget);

   connect(presentation->getNouvellePartie(), SIGNAL(clicked()),
              this, SLOT(jouer()));

   // QObject::connect(grilleUI->getTimer(), SIGNAL(timeout()), this,SLOT(chrono()));
   // grilleUI->getTimer()->start();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 600);
    this->setFixedSize(800,600);
    this->setWindowIcon(QIcon(":/resources/img/bombe_.png"));
    initialiser();
    this->show();
}
