#include "grilleui.h"
#include "caseui.h"
#include "grille.h"




GrilleUI::GrilleUI(QWidget* parent)
{
grille=Grille::getInstance();


for (size_t i = 0; i < grille->getLigne(); ++i) {
    std::vector<CaseUI *> ligne;
    for (size_t j = 0; j < grille->getColonne(); ++j) {
        Case *_case=grille->getCase(i,j);

        CaseUI *_caseui = new CaseUI(_case,"1",parent );
        _caseui->setText(_caseui->getNombreMines());
        ligne.push_back(_caseui);

    }
    casesUI.push_back(ligne);

}
}


GrilleUI::GrilleUI()
{

}
CaseUI* GrilleUI::getCaseUI(size_t i, size_t j){
    return  casesUI[i][j];
}

CaseUI* GrilleUI::getCaseUI(size_t i){
    return  getCasesUI()[i];
}

std::vector<CaseUI *> GrilleUI::getCasesUI()
{
    std::vector<CaseUI *> _cases;
    for (size_t i = 0; i < grille->getLigne(); ++i) {
        for (size_t j = 0; j < grille->getColonne(); ++j) {
            _cases.push_back(getCaseUI(i,j));
        }
    }
    return _cases;
}
