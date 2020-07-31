#ifndef GRILLEUI_H
#define GRILLEUI_H
#include <vector>
#include "caseui.h"
#include "grille.h"

class GrilleUI : private InterfaceGrille
{

private:
    Grille *grille;
    std::vector<CaseUI*> casesUI;
    size_t tailleCase = 35;
public:
    GrilleUI();
    GrilleUI(QWidget*, size_t, size_t);

    CaseUI* getCaseUI(size_t,size_t);
    CaseUI* getCaseUI(size_t);
    std::vector<CaseUI*> getCasesUI();
    void terminerAvecEchec();

};

#endif // GRILLEUI_H
