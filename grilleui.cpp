#include "grilleui.h"
#include "caseui.h"
#include "grille.h"
#include <QDebug>

GrilleUI::GrilleUI(QWidget* parent, size_t ligne, size_t colonne, size_t nombreMines)
{
    grille = new Grille(ligne, colonne, nombreMines);
    zoneLabel  = new QGridLayout(parent);

    labelNombreMinesMasquees = new QLabel(getNombreMinees());


    labelTempsEcoule = new QLabel("0");


    QHBoxLayout *horizontalLayout = new QHBoxLayout();


    QPushButton *nombre_bombe = new QPushButton(parent);
    nombre_bombe->setIcon(QIcon(":/resources/img/bombe_.png"));
    nombre_bombe->setMinimumSize(QSize(40, 40));
    nombre_bombe->setMaximumSize(QSize(40, 40));

    nombre_bombe->setStyleSheet("border: none");


    horizontalLayout->addWidget(nombre_bombe);
    horizontalLayout->addWidget(labelNombreMinesMasquees);


    QPushButton *time = new QPushButton(parent);
    time->setIcon(QIcon(":/resources/img/chrono.png"));
    time->setMinimumSize(QSize(40, 40));
    time->setMaximumSize(QSize(40, 40));
    time->setStyleSheet("border: none");


    horizontalLayout->addWidget(time);
    horizontalLayout->addWidget(labelTempsEcoule);


    nouvellePartie = new QPushButton(parent);
    nouvellePartie->setText("Nouvelle partie");



    horizontalLayout->addWidget(nouvellePartie);



    debutant = new QPushButton(parent);
    debutant->setText("Débutant");


    horizontalLayout->addWidget(debutant);

    moyen = new QPushButton(parent);
    moyen->setText(" Moyen");

    horizontalLayout->addWidget(moyen);


    expert = new QPushButton(parent);
    expert->setText("Expert");

    horizontalLayout->addWidget(expert);


    zoneLabel->addLayout(horizontalLayout, 0, 0, 1, 1);


        initialiser(parent,ligne, colonne, nombreMines);

    _timer=new QTimer(this);
    _timer->setInterval(100);
    rejouer();
}


void GrilleUI::initialiser(QWidget* parent,size_t ligne, size_t colonne, size_t nombreMines){
    qDebug()<<"debug initialisation";

    grille=new Grille(ligne, colonne, nombreMines);
    for (Case *_case :  grille->getCases()) {
        CaseUI *_caseui = new CaseUI(this,_case, tailleCase, parent );
        _caseui->setGrilleUI(this);
        casesUI.push_back(_caseui);
    }

}

QPushButton*  GrilleUI::getExpert(){

    return expert;
}

QPushButton*  GrilleUI::getMoyen(){

    return moyen;
}
QPushButton*  GrilleUI::getDebutant(){

    return debutant;
}
QPushButton*  GrilleUI::getNouvellePartie(){

    return nouvellePartie;
}





QLabel* GrilleUI::getLabelNombreMinesMasquees(){

    return labelNombreMinesMasquees;

}

QLabel* GrilleUI::getLabelTempsEcoule(){
    return labelTempsEcoule;
}

QGridLayout* GrilleUI::getZoneLabel(){

    return zoneLabel;
}

size_t GrilleUI::getLargeur(){
    return tailleCase * grille->getColonne();
}
size_t GrilleUI::getLongueur(){
    return tailleCase * grille->getLigne();

}

Partie* GrilleUI::getPartie() {
    return  partie;
}

QString GrilleUI::getNombreMinees(){
    return std::to_string(grille->getNombreMineesRestant()).c_str();
}

GrilleUI::GrilleUI(){}

CaseUI* GrilleUI::getCaseUI(size_t i, size_t j){
    return  casesUI[i * grille->getColonne() + j];
}

CaseUI* GrilleUI::getCaseUI(size_t i){
    return  getCasesUI()[i];
}

QTimer* GrilleUI::getTimer(){
    return  _timer;
}

std::vector<CaseUI *> GrilleUI::getCasesUI()
{
    return casesUI;
}

void GrilleUI::terminerAvecEchec() {
    /* grille->terminerAvecEchec();
    rafraichir(); */
}

void GrilleUI::rafraichir(){
    for (CaseUI *_caseui : getCasesUI()) {
        _caseui->rafraichir();
    }
    labelNombreMinesMasquees->setText(getNombreMinees());
}

void GrilleUI::setTempsEcoule() {
    labelTempsEcoule->setText(std::to_string(partie->getTempEcoule()).c_str());
}

void GrilleUI::rejouer(){
    partie = new Partie(grille);
    rafraichir();
}
