#include "grilleui.h"
#include "caseui.h"
#include "grille.h"
#include <QDebug>

GrilleUI::GrilleUI(QWidget* parent, size_t ligne, size_t colonne, size_t nombreMines)
{
    grille = new Grille(ligne, colonne, nombreMines);
    for (Case *_case :  grille->getCases()) {
        CaseUI *_caseui = new CaseUI(_case, tailleCase, parent );
        _caseui->setGrilleUI(this);
        casesUI.push_back(_caseui);
    }
    labelNombreMinesMasquees = new QLabel(getNombreMinees());
    this->addWidget(labelNombreMinesMasquees, 10, 10);

    labelTempsEcoule = new QLabel("0");
    this->addWidget(labelTempsEcoule, 10, 15);

    _timer=new QTimer(this);
    _timer->setInterval(1000);
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

