#include "grille.h"
#include "initial.h"
#include "nondevoilee.h"

Grille::Grille(){}

Grille::Grille(size_t _ligne, size_t _colonne, size_t _nombreMines)
{
    ligne = _ligne;
    colonne = _colonne;
    for (size_t i = 0; i < _ligne; ++i) {
        for (size_t j = 0; j < _colonne; ++j) {
            cases.push_back(new Case(i, j, new Initial(), this));
        }
    }
    nombreMines = _nombreMines;
}

Grille::~Grille(){}

Case* Grille::getCase(size_t i, size_t j){
    return  cases[i * colonne + j];
}

Case* Grille::getCase(size_t i){
    return  getCases()[i];
}

std::vector<Case *> Grille::getCases()
{
    return cases;
}

size_t Grille::getLigne(){
    return  ligne;
}

size_t Grille::getColonne(){
    return  colonne;
}

void Grille::setMines(Case * _caseInitial) {
    for (size_t i = 0; i < nombreMines ; ++i) {
       Case *_case = getCase(rand() % (colonne*ligne));
       if(_caseInitial == _case) {
           i--;
           continue;
       }
       _case->setMinee();
    }
    initialierCases();
}

std::vector<Case*> Grille::getMinees() {
    std::vector<Case*> minees;
    for (Case *_case :  getCases()) {
        if(_case->estMinee()) {
           minees.push_back(_case);
        }
    }
    return  minees;
}

void Grille::desactiverCases() {
    for (Case *_case :  getCases()) {
           _case->desactiver();
    }
}

void Grille::initialierCases() {
    for (Case *_case :  getCases()) {
           _case->passerAlEtat(new NonDevoilee());
    }
}

void Grille::terminerAvecEchec() {
    desactiverCases();
}
