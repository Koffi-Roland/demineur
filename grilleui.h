#ifndef GRILLEUI_H
#define GRILLEUI_H
#include <vector>
#include "caseui.h"
#include "interfacegrille.h"

class GrilleUI :  private InterfaceGrille, public QGridLayout
{

private:
    Grille* grille;
    std::vector<CaseUI*> casesUI;
    size_t tailleCase = 25;

public:
    GrilleUI();
    ~ GrilleUI();
    GrilleUI(QWidget*, size_t, size_t, size_t);
    CaseUI* getCaseUI(size_t,size_t);
    CaseUI* getCaseUI(size_t);
    std::vector<CaseUI*> getCasesUI();
    size_t getLargeur();
    size_t getLongueur();
    void initialiser(QWidget*, size_t, size_t, size_t);
    void rafraichir();
    void devoilerMinees();
    int getNombreMinees();
    void rejouer();
    Grille* getGrille();
    void terminerAvecEchec();

};

#endif // GRILLEUI_H
