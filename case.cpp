#include "case.h"
#include "grille.h"
#include <QDebug>

Case::Case(){}

Case::Case(size_t _x, size_t _y, Grille *grille)
{
    x = _x;
    y = _y;
    this->_grille = grille;
}

size_t Case::getX(){
  return x;
}
size_t Case::getY(){
  return y;
}

Grille* Case::getGrille(){
    return _grille;
}

void Case::initialiser(){
    _etat->initialiser();
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

bool Case::estSaturee(int saturation) {
    for (Case *voisine :  getVoisines()) {
        if(voisine->getNombreMines() >= saturation )
            return true;
    }
    return false;
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

bool Case::estVoisine(Case *_case){
    for (Case *voisine :  getVoisines()) {
        if( _case == voisine || _case == this)
            return true;
    }
    return false;
}

int Case::getNombreMines(){
    int n = 0;
    for (Case *voisine :  getVoisines()) {
        n +=  (voisine->estMinee()) ? 1 : 0;
    }
    return n;
}

void Case::passerAlEtat(Etat *nouvel_etat){
     nouvel_etat->setCase(this);
     _etat = nouvel_etat;
}

int Case::getEtat(){
    return _etat->getEtat();
}

void Case::devoilerVoisines(){
    for (Case *voisine :  getVoisines()) {
        voisine->devoiler();
    }
}

Case::~Case() {
}

