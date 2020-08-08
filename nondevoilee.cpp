#include "nondevoilee.h"
#include "case.h"
#include "devoilee.h"
#include "marquee.h"
#include "grille.h"
#include "desactivee.h"
#include "enumetats.h"
#include <QDebug>

NonDevoilee::NonDevoilee(){}

void NonDevoilee::initialiser(){}

void NonDevoilee::devoiler(){
   if(_case->estMinee()){
      _case->getGrille()->terminerAvecEchec();
      return;
   }
   _case->passerAlEtat(new Devoilee());

   if(_case->getNombreMines() == 0){
        _case->devoilerVoisines();
   }
}

void NonDevoilee::marquer(){
    _case->passerAlEtat(new Marquee());
}

void NonDevoilee::desactiver() {
     _case->passerAlEtat(new Desactivee());
}

int NonDevoilee::getEtat(){
    return EnumEtats::NonDevoilee;
};
