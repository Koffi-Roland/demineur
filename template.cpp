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

    this->resize(600, 620);
    this->setWindowIcon(QIcon(":/resources/img/bombe_.png"));
    // this->minimumSize();
    QWidget *centralwidget = new QWidget(this);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    centralwidget->setFont(font);

    /* GridLayout Global*/
    QGridLayout *gridLayoutGlobal  = new QGridLayout(centralwidget);

    /* GridLayout Label conteneur des labels*/
    QGridLayout *gridLayoutLabel= new QGridLayout();

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(1);

    /* creation et ajout de label à horizontalLayout*/

    QLabel *labelNombreMinesMasquees = new QLabel(centralwidget);

    horizontalLayout->addWidget(labelNombreMinesMasquees);

    QLabel *labelTempsEcoule = new QLabel(centralwidget);

    horizontalLayout->addWidget(labelTempsEcoule);

    /* Ajout sur la grille gridLayoutLabel */
    gridLayoutLabel->addLayout(horizontalLayout, 0, 0, 1, 1);


    /* Ajout sur la grille Global */

    gridLayoutGlobal->addLayout(gridLayoutLabel, 0, 0, 1, 1);


    /*GridLayout Container conteneur de la GrilleUI   */
   QGridLayout *gridLayoutContainer = new QGridLayout();

    grilleUI=new GrilleUI(this, 20, 15, 40);
    grilleUI->setSpacing(0);
    grilleUI->setSizeConstraint(QLayout::SetNoConstraint);

    /*Ajout de la grilleUI sur  gridLayoutContainer*/
    gridLayoutContainer->addLayout(grilleUI, 0, 0, 1, 1);

    /*Ajout de la gridLayoutContainer sur  gridLayoutGlobal*/
    gridLayoutGlobal->addLayout(gridLayoutContainer, 3, 0, 1, 1);
    this->setCentralWidget(centralwidget);


    /* Partie timer*/
    QObject::connect(grilleUI->getTimer(), SIGNAL(timeout()), this,SLOT(chrono()));
    grilleUI->getTimer()->start();

  //  this->show();

}
