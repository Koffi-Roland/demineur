#ifndef GRILLEUI_H
#define GRILLEUI_H
#include <vector>
#include "caseui.h"
#include "grille.h"
#include "partie.h"
#include "interfacegrille.h"
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QTimer>


class GrilleUI :  private InterfaceGrille, public QGridLayout
{

private:
    Grille *grille;
    Partie *partie;
    std::vector<CaseUI*> casesUI;
    size_t tailleCase = 25;
    QLabel* labelNombreMinesMasquees;
    QLabel* labelTempsEcoule;
    QTimer* _timer;
    QGridLayout  *zoneLabel;
    QPushButton *debutant;
    QPushButton *moyen;
    QPushButton *expert;
    QPushButton *nouvellePartie;

public:
    GrilleUI();
    GrilleUI(QWidget*, size_t, size_t, size_t);
    Partie* getPartie();

    CaseUI* getCaseUI(size_t,size_t);
    CaseUI* getCaseUI(size_t);
    QTimer* getTimer();
    std::vector<CaseUI*> getCasesUI();
    size_t getLargeur();
    size_t getLongueur();
    void initialiser(QWidget*, size_t, size_t, size_t);
    QPushButton* getDebutant();
    QPushButton* getMoyen();
    QPushButton* getExpert();
    QPushButton* getNouvellePartie();
    QLabel* getLabelNombreMinesMasquees();
    QLabel* getLabelTempsEcoule();
    QGridLayout* getZoneLabel();
    void rafraichir();
    void devoilerMinees();
    QString getNombreMinees();
    void setTempsEcoule();
    void rejouer();
    void terminerAvecEchec();

};

#endif // GRILLEUI_H
