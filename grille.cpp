
#include "grille.h"
#include "nondevoilee.h"
/*========== Application de design pattern Singleton=========*/

Grille* Grille::instance = nullptr;

Grille::Grille()
{

}
Grille::Grille(size_t _ligne, size_t _colonne)
{
    ligne = _ligne;
    colonne = _colonne;
    for (size_t i = 0; i < _ligne; ++i) {
        std::vector<Case *> ligne;
        for (size_t j = 0; j < _colonne; ++j) {
            Case *_case = new Case(i, j, new NonDevoilee(), this);
            ligne.push_back(_case);
        }
        cases.push_back(ligne);
    }
}
Grille::~Grille(){}

Grille* Grille::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Grille(9,9);
    }

    return instance;
}

Case* Grille::getCase(size_t i, size_t j){
    return  cases[i][j];
}

Case* Grille::getCase(size_t i){
    return  getCases()[i];
}

std::vector<Case *> Grille::getCases()
{
    std::vector<Case *> _cases;
    for (size_t i = 0; i < ligne; ++i) {
        for (size_t j = 0; j < colonne; ++j) {
            _cases.push_back(getCase(i,j));
        }
    }
    return _cases;
}

size_t Grille::getLigne(){
    return  ligne;
}

size_t Grille::getColonne(){
    return  colonne;
}

void Grille::setMines(int n) {
    for (int i = 0; i < n; ++i) {
       // getCase(rand() % 81)->setMinee();
        getCase(i)->setMinee();

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
