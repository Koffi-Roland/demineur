#include "grilleui.h"
#include "caseui.h"
#include "grille.h"

GrilleUI::GrilleUI(QWidget* parent, size_t ligne, size_t colonne)
{
    grille = new Grille(ligne, colonne);
    for (Case *_case :  grille->getCases()) {
        CaseUI *_caseui = new CaseUI(_case, tailleCase, parent );
        casesUI.push_back(_caseui);
    }
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
}
