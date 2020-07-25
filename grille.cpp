
#include "grille.h"
#include "nondevoilee.h"
/*========== Application de design pattern Singleton=========*/

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
            ligne.push_back(new Case(i, j, new NonDevoilee()));
        }
        cases.push_back(ligne);
    }
}
Grille::~Grille(){}

Grille* Grille::instance = nullptr;

Grille* Grille::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Grille(9,9);
    }

    return instance;
}

Case* Grille::getCase(size_t i, size_t j){
    return  Grille::getCases()[i][j];
}

std::vector<std::vector<Case *>> Grille::getCases()
{
    return cases;
}

size_t Grille::getLigne(){
    return  ligne;
}

size_t Grille::getColonne(){
    return  colonne;
}

bool Grille::existe(size_t i, size_t j) {
    return  i < ligne && 0 < i && j < colonne && 0 < j ;
}

