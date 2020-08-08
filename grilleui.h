#ifndef GRILLEUI_H
#define GRILLEUI_H
#include <vector>
#include "caseui.h"
#include "grille.h"
#include "interfacegrille.h"
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QTimer>


class GrilleUI : private InterfaceGrille, public QGridLayout
{


private:
    Grille *grille;
    std::vector<CaseUI*> casesUI;
    size_t tailleCase = 25;
   // QLabel* nombreMinesMasquees;
   // QTimer* temps;
public:
    GrilleUI();
    GrilleUI(QWidget*, size_t, size_t, size_t);

    CaseUI* getCaseUI(size_t,size_t);
    CaseUI* getCaseUI(size_t);
    std::vector<CaseUI*> getCasesUI();
    void rafraichir();
    void devoilerMinees();
    void terminerAvecEchec();
    QString getNombreMinees();

};

#endif // GRILLEUI_H
