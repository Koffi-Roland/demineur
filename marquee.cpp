#include "marquee.h"
#include "case.h"
#include "nondevoilee.h"
#include "desactivee.h"

Marquee::Marquee(){}

void Marquee::devoiler(){
}

void Marquee::marquer(){
    _case->passerAlEtat(new NonDevoilee());
}

void Marquee::desactiver() {
     _case->passerAlEtat(new Desactivee());
}
