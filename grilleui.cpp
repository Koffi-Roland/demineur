#include "grilleui.h"
#include "caseui.h"
#include "grille.h"
#include <QDebug>

GrilleUI::GrilleUI(QWidget* parent, size_t ligne, size_t colonne, size_t nombreMines)
{
    grille = new Grille(ligne, colonne, nombreMines);

   zoneLabel  = new QGridLayout(parent);

 /*  zoneLabel->setGeometry(QRect(
                              QPoint(0, 0),
                              QSize(this->getLargeur(), 40)
                          ));*/




    labelNombreMinesMasquees = new QLabel(getNombreMinees());

    zoneLabel->addWidget(labelNombreMinesMasquees, 10, 10);

    labelTempsEcoule = new QLabel("0");
    zoneLabel->addWidget(labelTempsEcoule, 10, 15);

    for (Case *_case :  grille->getCases()) {
        CaseUI *_caseui = new CaseUI(this,_case, tailleCase, parent );
        _caseui->setGrilleUI(this);
        casesUI.push_back(_caseui);
    }


    _timer=new QTimer(this);
    _timer->setInterval(100);
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
    grille->terminerAvecEchec();
    rafraichir();
}

void GrilleUI::rafraichir(){
    for (CaseUI *_caseui : getCasesUI()) {
       _caseui->rafraichir();
    }
    labelNombreMinesMasquees->setText(getNombreMinees());
}

void GrilleUI::setTempsEcoule(){
    labelTempsEcoule->setText(std::to_string(grille->getTempEcoule()).c_str());
}

