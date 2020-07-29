#ifndef GRILLEUI_H
#define GRILLEUI_H
#include <vector>
#include "caseui.h"
#include "grille.h"


class GrilleUI
{

private:
    Grille *grille;
    std::vector<std::vector<CaseUI*>> casesUI;
public:
    GrilleUI();
    GrilleUI(QWidget*);

    CaseUI* getCaseUI(size_t,size_t);
    CaseUI* getCaseUI(size_t);
    std::vector<CaseUI*> getCasesUI();

};

#endif // GRILLEUI_H
