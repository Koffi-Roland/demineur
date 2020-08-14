#include "grilleui.h"
#include "caseui.h"
#include "grille.h"
#include <QDebug>

GrilleUI::GrilleUI(){}
GrilleUI::~ GrilleUI(){
    qDebug() << "grilleUI::delete";
    for (CaseUI *_caseui :  getCasesUI()) {
        delete  _caseui;
    }
}

GrilleUI::GrilleUI(QWidget* parent, size_t ligne, size_t colonne, size_t nombreMines)
{
    grille = new Grille(ligne, colonne, nombreMines);
    initialiser(parent,ligne, colonne, nombreMines);
    rejouer();
}

void GrilleUI::initialiser(QWidget* parent,size_t ligne, size_t colonne, size_t nombreMines){
    grille=new Grille(ligne, colonne, nombreMines);
    for (Case *_case :  grille->getCases()) {
        CaseUI *_caseui = new CaseUI(this, _case, tailleCase, parent );
        _caseui->setGrilleUI(this);
        casesUI.push_back(_caseui);
    }
}

size_t GrilleUI::getLargeur(){
    return tailleCase * grille->getColonne();
}

size_t GrilleUI::getLongueur(){
    return tailleCase * grille->getLigne();
}

QString GrilleUI::getNombreMinees(){
    return std::to_string(grille->getNombreMineesRestant()).c_str();
}

CaseUI* GrilleUI::getCaseUI(size_t i, size_t j)
{
    return  casesUI[i * grille->getColonne() + j];
}

CaseUI* GrilleUI::getCaseUI(size_t i)
{
    return  getCasesUI()[i];
}

std::vector<CaseUI *> GrilleUI::getCasesUI()
{
    return casesUI;
}

void GrilleUI::terminerAvecEchec() {
    /* grille->terminerAvecEchec();
    rafraichir(); */
}

void GrilleUI::rafraichir(){
    for (CaseUI *_caseui : getCasesUI()) {
        _caseui->rafraichir();
    }
   // labelNombreMinesMasquees->setText(getNombreMinees());
}

void GrilleUI::rejouer(){
   // partie = new Partie(grille);
    rafraichir();
}
