#include "case.h"
#include "grille.h"

Case::Case(){}

Case::Case(size_t _x, size_t _y, Etat *_etat_initial, Grille *grille)
{
    x = _x;
    y = _y;
    this->passerAlEtat(_etat_initial);
    this->_grille = grille;
}
void Case::devoiler(){
    _etat->devoiler();
}

void Case::marquer(){
    _etat->marquer();
}

void Case::setMinee(){
    minee = true;
}

bool Case::estMinee(){
    return minee;
}

std::vector<Case*> Case::getVoisines(){
    std::vector<Case*> voisines;
    for (size_t i = x; i < x+1; i++) {
        for (size_t j = y; j < y+1; j++) {
            if (getGrille()->existe(i, j) ){
                voisines.push_back(getGrille()->getCase(i,j));
            }
        }
    }
    return  voisines;
}

int Case::getNombreMines(){
    std::vector<Case*> voisines = getVoisines();
    int n = 0;
    for (Case * voisine:voisines) {
        n +=  (voisine->estMinee()) ? 1 : 0;
    }
   //return n;
   return  (int) voisines.size();
}

void Case::passerAlEtat(Etat *nouvel_etat){
    /*if (_etat != nullptr)
          delete _etat;*/
    _etat = nouvel_etat;
    _etat->setCase(this);
}
