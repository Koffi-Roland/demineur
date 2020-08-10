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
    QLabel* labelNombreMinesMasquees;
    QLabel* labelTempsEcoule;
    QTimer* _timer;
    QGridLayout  *zoneLabel;

public:
    GrilleUI();
    GrilleUI(QWidget*, size_t, size_t, size_t);

    CaseUI* getCaseUI(size_t,size_t);
    CaseUI* getCaseUI(size_t);
    QTimer* getTimer();
    std::vector<CaseUI*> getCasesUI();
    size_t getLargeur();
    size_t getLongueur();
    QLabel* getLabelNombreMinesMasquees();
    QLabel* getLabelTempsEcoule();
    QGridLayout* getZoneLabel();

    void rafraichir();
    void devoilerMinees();
    void terminerAvecEchec();
    QString getNombreMinees();
    void setTempsEcoule();

};

#endif // GRILLEUI_H
