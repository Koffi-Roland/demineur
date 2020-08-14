#include "presentation.h"
#include <QSplitter>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QStyle>
#include "grilleui.h"

Presentation::Presentation(){

}
Presentation::Presentation(QWidget *centralWidget, QMainWindow* mainWindow){
        QWidget* cadre = new QWidget(centralWidget);
        QHBoxLayout *layoutDonnees;
        QSpacerItem *horizontalSpacer;
        QFrame *line;
        QMenuBar *menuBar;
        QMenu *menufichier;
        QToolBar *mainToolBar;
        QStatusBar *statusBar;

        QSplitter * zoneTypesJeux = new QSplitter(centralWidget);
        zoneTypesJeux->setGeometry(QRect(50, 10, 700, 40));
        zoneTypesJeux->setOrientation(Qt::Horizontal);


        debutant = new QRadioButton("Débutant", zoneTypesJeux);
        moyen = new QRadioButton("Intermédiaire", zoneTypesJeux);
        expert = new QRadioButton("Expert", zoneTypesJeux);
        nouvellePartie = new QPushButton ("Jouer", centralWidget);
        nouvellePartie->setGeometry(QRect(300, 60, 200, 40));

        debutant->setStyleSheet("padding:10px; background-color:#FFFFFF");
        moyen->setStyleSheet("padding:10px; background-color:#FFFFFF");
        expert->setStyleSheet("padding:10px; background-color:#FFFFFF");

        debutant->setMinimumWidth(200);
        moyen->setMinimumWidth(200);
        expert->setMinimumWidth(200);

        line = new QFrame(centralWidget);
        line->setGeometry(QRect(50, 50, 700, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        cadre = new QWidget(centralWidget);
        cadre->setStyleSheet("border-radius:3px; background-color:#FFFFFF");
        cadre->setGeometry(QRect(40, 110, 720, 430));

        widgetGrille = new QWidget (cadre);
        widgetGrille->setGeometry(QRect(10, 64, 700, 350));
       // widgetGrille->setStyleSheet("border-radius:2px;");

        gridLayoutGrille = new QGridLayout(widgetGrille);
        gridLayoutGrille->setSpacing(0) ;

        GrilleUI* grilleUI = new GrilleUI(widgetGrille, 16, 30, 99);
        gridLayoutGrille->addLayout(grilleUI,1, 0, 1, 1);


        QWidget* widgetDonnees = new QWidget (cadre);
        widgetDonnees->setGeometry(QRect(5, 0, 710, 70));
        layoutDonnees = new QHBoxLayout(widgetDonnees);

        QWidget* widgetDonneesGauche = new QWidget (widgetDonnees);
        widgetDonneesGauche->setStyleSheet("border-radius:3px; background-color:#FF0000");
        QHBoxLayout* layoutDonneesGauche = new QHBoxLayout (widgetDonneesGauche);

        QLabel  *inconeMine  = new QLabel(widgetDonneesGauche);
        inconeMine->setPixmap(QPixmap(":/resources/img/bombe_.png"));
        layoutDonneesGauche->addWidget(inconeMine);

        nombreMinesMasquees = new QLCDNumber(3);
        nombreMinesMasquees->setStyleSheet("background-color:#000000");
        nombreMinesMasquees->setProperty("intValue", QVariant(22));
        nombreMinesMasquees->setMinimumSize(QSize(30, 30));
        layoutDonneesGauche->addWidget(nombreMinesMasquees);

        layoutDonnees->addWidget(widgetDonneesGauche);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layoutDonnees->addItem(horizontalSpacer);

        QWidget* widgetDonneesDroit = new QWidget (widgetDonnees);
        widgetDonneesDroit->setStyleSheet("border-radius:3px; background-color:#FF0000");
        QHBoxLayout* layoutDonneesDroit = new QHBoxLayout (widgetDonneesDroit);

        QLabel  *inconeTemps  = new QLabel(widgetDonneesDroit);
        inconeTemps->setPixmap(QPixmap(":/resources/img/chrono.png"));
        layoutDonneesDroit->addWidget(inconeTemps);

        tempsEcoule = new QLCDNumber(3, widgetDonneesDroit);
        tempsEcoule->setStyleSheet("padding:10px;background-color:#000000;");
        tempsEcoule->setProperty("intValue", QVariant(22));
        layoutDonneesDroit->addWidget(tempsEcoule);

        layoutDonnees->addWidget(widgetDonneesDroit);

       mainWindow->setCentralWidget(centralWidget);
       menuBar = new QMenuBar(mainWindow);
       menuBar->setObjectName(QString::fromUtf8("menuBar"));
       menuBar->setGeometry(QRect(0, 0, 751, 22));
       menufichier = new QMenu(menuBar);
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

void Presentation::setTextes(QMainWindow* mainWindow) {

}
/*
Presentation::Presentation(QWidget *centralWidget, QWidget* parent){
    QWidget *horizontalLayoutWidget = new QWidget(centralWidget);
    //QHBoxLayout *horizontalLayout = new QHBoxLayout();
    QHBoxLayout* horizontalLayout = new QHBoxLayout(centralWidget);

    zoneLabel  = new QGridLayout(parent);
    //zoneLabel->addLayout(this, 0, 0, 1, 1);

    QPushButton *nombre_bombe = new QPushButton(parent);
    nombre_bombe->setIcon(QIcon(":/resources/img/bombe_.png"));
    nombre_bombe->setMinimumSize(QSize(40, 40));
    nombre_bombe->setMaximumSize(QSize(40, 40));
    nombre_bombe->setStyleSheet("border: none");
    horizontalLayout->addWidget(nombre_bombe);

    QPushButton *time = new QPushButton(parent);
    time->setIcon(QIcon(":/resources/img/chrono.png"));
    time->setMinimumSize(QSize(40, 40));
    time->setMaximumSize(QSize(40, 40));
    time->setStyleSheet("border: none");
    horizontalLayout->addWidget(time);

    //labelNombreMinesMasquees = new QLabel(getNombreMinees());
    labelNombreMinesMasquees = new QLabel("T");
    horizontalLayout->addWidget(labelNombreMinesMasquees);

    labelTempsEcoule = new QLabel("0");
    horizontalLayout->addWidget(labelTempsEcoule);

    nouvellePartie = new QPushButton(parent);
    nouvellePartie->setText("Nouvelle partie");
    this->addWidget(nouvellePartie);

    debutant = new QPushButton(parent);
    debutant->setText("Débutant");
    horizontalLayout->addWidget(debutant);

    moyen = new QPushButton(parent);
    moyen->setText(" Moyen");
    horizontalLayout->addWidget(moyen);

    expert = new QPushButton(parent);
    expert->setText("Expert");
    horizontalLayout->addWidget(expert);

    _timer=new QTimer(this);
    _timer->setInterval(100);
}
*/

QRadioButton*  Presentation::getExpert(){
    return expert;
}

QRadioButton*  Presentation::getMoyen(){
    return moyen;
}

QRadioButton*  Presentation::getDebutant(){
    return debutant;
}

QPushButton*  Presentation::getNouvellePartie(){
    return nouvellePartie;
}

QGridLayout *Presentation::getGridLayoutGrille()
{
    return  gridLayoutGrille;
}


QWidget *Presentation::getWidgetGrrille()
{
    return widgetGrille;
}
/*
QLabel* Presentation::getLabelNombreMinesMasquees(){
    return labelNombreMinesMasquees;
}

QLabel* Presentation::getLabelTempsEcoule(){
    return labelTempsEcoule;
}

void Presentation::setTempsEcoule() {
    labelTempsEcoule->setText(std::to_string(partie->getTempEcoule()).c_str());
}
*/

QTimer* Presentation::getTimer(){
    return  _timer;
}

Partie* Presentation::getPartie() {
    return  partie;
}
