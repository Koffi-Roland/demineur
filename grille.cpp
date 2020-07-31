#include "grille.h"
#include "nondevoilee.h"

Grille::Grille(){}

Grille::Grille(size_t _ligne, size_t _colonne)
{
    ligne = _ligne;
    colonne = _colonne;
    for (size_t i = 0; i < _ligne; ++i) {
        for (size_t j = 0; j < _colonne; ++j) {
            cases.push_back(new Case(i, j, new NonDevoilee(), this));
        }    
    }
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

void Grille::setMines(int n) {
    for (size_t i = 0; i < n; ++i) {
       getCase(rand() % (colonne*ligne))->setMinee();
    }
}

void Grille::devoilerMinees() {
    for (Case *_case :  getCases()) {
        if(_case->estMinee()) {
           _case->devoiler();
        }
    }
}

void Grille::desactiverCases() {
    for (Case *_case :  getCases()) {
           _case->desactiver();
    }
}

void Grille::terminerAvecEchec() {
    desactiverCases();
}
