#include "presentation.h"
#include <QSplitter>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QStyle>
#include <QDebug>
#include "QMessageBox"

Presentation::Presentation(){}
Presentation::Presentation(QWidget *centralWidget, QMainWindow* mainWindow){
    cadre = new QWidget(centralWidget);
    QHBoxLayout *layoutDonnees;

    typeJeux = new TypeJeux (centralWidget);

    cadre = new QWidget(centralWidget);
    cadre->setStyleSheet("border-radius:3px; background-color:#035673");
    cadre->setGeometry(QRect(40, 110, 720, 430));

    QWidget* widgetDonnees = new QWidget (cadre);
    widgetDonnees->setGeometry(QRect(5, 0, 710, 70));
    layoutDonnees = new QHBoxLayout(widgetDonnees);
    nombreMinesMasquees = new Donnee(layoutDonnees, widgetDonnees, 0, ":/resources/img/bombe_.png");
    QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layoutDonnees->addItem(horizontalSpacer);
    tempsEcoule  = new Donnee(layoutDonnees, widgetDonnees, 0, ":/resources/img/chrono.png");

    widgetGrille = new QWidget (cadre);
    widgetGrille->setGeometry(QRect(10, 64, 700, 350));
    gridLayoutGrille = new QGridLayout(widgetGrille);
    gridLayoutGrille->setSpacing(0) ;

    _timer = new QTimer(this);
    _timer->setInterval(100);

    mainWindow->setCentralWidget(centralWidget);
    definirMenus(mainWindow);
}

QToolButton*  Presentation::getNouvellePartie(){
    return typeJeux->getNouvellePartie();
}

void Presentation::setNombreMinesMasquees()
{
    nombreMinesMasquees->setNombre(grilleUI->getNombreMinees());
}

void Presentation::setTempsEcoule()
{
   tempsEcoule->setNombre(partie->getTempEcoule());
   if(partie->estTerminee()){
       _timer->stop();
       afficherMessage();
   }
}



QGridLayout *Presentation::getGridLayoutGrille()
{
    return  gridLayoutGrille;
}

QWidget *Presentation::getWidgetGrille()
{
    return widgetGrille;
}

QTimer* Presentation::getTimer(){
    return  _timer;
}

void Presentation::initialiserGrille(size_t ligne, size_t colonne, size_t nombreMines)
{
    if( grilleUI != nullptr) {
        removeItem(grilleUI);
        gridLayoutGrille->removeItem(grilleUI);
        delete grilleUI;
    }
    grilleUI = new GrilleUI(widgetGrille, ligne, colonne, nombreMines);
    gridLayoutGrille->addLayout(grilleUI,1, 0, 1, 1);
    partie = new Partie (grilleUI->getGrille());
}

void Presentation::jouer()
{
    typeJeux->initialiser();
    initialiserGrille(typeJeux->getLigne(), typeJeux->getColonne(), typeJeux->getNombreMines());
    tempsEcoule->setNombre(0);
    _timer->start();
}

Partie* Presentation::getPartie() {
    return  partie;
}

void Presentation::definirMenus(QMainWindow* mainWindow)
{
    QMenuBar *menuBar;
    QMenu *menufichier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    menuBar = new QMenuBar(mainWindow);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 751, 22));
    menufichier = new QMenu("Fichier",menuBar);
    menufichier->setObjectName(QString::fromUtf8("menufichier"));
    mainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(mainWindow);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    mainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    mainWindow->insertToolBarBreak(mainToolBar);
    statusBar = new QStatusBar(mainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    mainWindow->setStatusBar(statusBar);
    menuBar->addAction(menufichier->menuAction());
}

void Presentation::afficherMessage()
{
    QMessageBox msgBox;
    msgBox.setText("Oops! Vous avez perdu");
    if(partie->estGagnee()) {
        msgBox.setText("Bravo! vous avez gagné");
    }
    msgBox.exec();
}

