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

    //nombreMinesMasquees = new QLabel(parent);
  //  nombreMinesMasquees->setText("Bonjour");
}

GrilleUI::GrilleUI(){}

CaseUI* GrilleUI::getCaseUI(size_t i, size_t j){
    return  casesUI[i * grille->getColonne() + j];
}

CaseUI* GrilleUI::getCaseUI(size_t i){
    return  getCasesUI()[i];
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
}

