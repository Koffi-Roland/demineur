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

size_t Case::getX(){
  return x;
}
size_t Case::getY(){
  return y;
}

void Case::devoiler(){
    _etat->devoiler();
}

void Case::marquer(){
    _etat->marquer();
}

void Case::desactiver() {
    _etat->desactiver();
}

void Case::setMinee(){
    minee = true;
}

bool Case::estMinee(){
    return minee;
}

std::vector<Case*> Case::getVoisines(){
    std::vector<Case*> voisines;
    size_t min_x = (x == 0) ? 0 : x-1;
    size_t min_y = (y == 0) ? 0 : y-1;
    size_t max_x = (x == getGrille()->getLigne()-1) ? getGrille()->getLigne()-1 : x+1;
    size_t max_y = (y == getGrille()->getColonne()-1) ? getGrille()->getColonne()-1 : y+1;
    for (size_t i = min_x; i <= max_x; ++i) {
        for (size_t j = min_y; j <= max_y; ++j) {
            if(i !=x || j != y){
                voisines.push_back(getGrille()->getCase(i,j));
            }
        }
    }
    return  voisines;
}

int Case::getNombreMines(){
    int n = 0;
    for (Case *voisine :  getVoisines()) {
        n +=  (voisine->estMinee()) ? 1 : 0;
    }
    return n;
   // return   (estMinee()) ? 1 : 0;
}

void Case::passerAlEtat(Etat *nouvel_etat){
    /*if (_etat != nullptr)
          delete _etat;*/
     nouvel_etat->setCase(this);

   /* _etat = nouvel_etat;
    _etat->setCase(this);*/
}

void Case::devoilerVoisines(){
    for (Case *voisine :  getVoisines()) {
        voisine->devoiler();
    }
}
