#include "grille.h"
#include "initial.h"
#include "nondevoilee.h"
#include "enumetats.h"
#include "partie.h"

Grille::Grille(){}
Grille::Grille(size_t _ligne, size_t _colonne, size_t _nombreMines)
{
    ligne = _ligne;
    colonne = _colonne;
    for (size_t i = 0; i < _ligne; ++i) {
        for (size_t j = 0; j < _colonne; ++j) {
            Case *__case = new Case(i, j,this);
             __case->passerAlEtat(new Initial());
            cases.push_back(__case);
        }
    }
    nombreMines = _nombreMines;
   // initialiser(new Initial());
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
    size_t i = 0;
    srand(time(nullptr));
    while (i < nombreMines) {
       Case *_case = getCase(rand() % (colonne*ligne));
       if(! _case->estVoisine(_caseInitial) && ! _case->estSaturee(saturation) && ! _case->estMinee()) {
            _case->setMinee();
            i++;
       }
    }
    partieEncours->demarrer();
    initialiser();
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

bool Grille::estTerminee(){
    for (Case *_case :  getCases()) {
        if(_case->getEtat() == EnumEtats::NonDevoilee || _case->getEtat() == EnumEtats::Initial) {
            return false;
        }
    }
    return true;
}

void Grille::desactiverCases() {
    for (Case *_case :  getCases()) {
           _case->desactiver();
    }
}

void Grille::initialiser() {
    for (Case *_case :  getCases()) {
           _case->initialiser();
    }
}

void Grille::initialiser(Etat* etat) {
    for (Case *_case :  getCases()) {
           _case->passerAlEtat(etat);
    }
}

void Grille::setPartieEncours(Partie *_partieEncours)
{
    partieEncours = _partieEncours;
}

Partie *Grille::getPartieEncours()
{
    return partieEncours;
}

void Grille::reinitialiser() {
    for (Case *_case :  getCases()) {
           _case->passerAlEtat(new Initial());
    }
}

size_t Grille::getNombreMineesRestant() {
    return nombreMines - getNombreMarquees();
}

size_t Grille::getNombreMineesNonMarques()
{
    size_t n = 0;
    for (Case *_case :  getCases()) {
        if(_case->getEtat() == EnumEtats::Marquee && _case->estMinee()) {
            n++;
        }
    }
    return nombreMines - n;
}

size_t Grille::getNombreMarquees() {
    size_t n = 0;
    for (Case *_case :  getCases()) {
        if(_case->getEtat() == EnumEtats::Marquee) {
            n++;
        }
    }
    return  n;
}

void Grille::terminerAvecEchec() {
    partieEncours->terminer();
}
