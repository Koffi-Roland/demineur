#include "nondevoilee.h"
#include "case.h"
#include "devoilee.h"
#include "marquee.h"
#include "grille.h"
#include "desactivee.h"

NonDevoilee::NonDevoilee(){ }

void NonDevoilee::devoiler(){
   _case->passerAlEtat(new Devoilee());
   if(_case->estMinee()){
      _case->getGrille()->terminerAvecEchec();
   }
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
