#include "marquee.h"
#include "case.h"
#include "nondevoilee.h"
#include "marqueedesactivee.h"
#include "enumetats.h"

Marquee::Marquee(){}

void Marquee::initialiser(){}

void Marquee::devoiler(){}

void Marquee::marquer(){
    _case->passerAlEtat(new NonDevoilee());
}

void Marquee::desactiver() {
    _case->passerAlEtat(new MarqueeDesactivee());
}

int Marquee::getEtat(){
    return EnumEtats::Marquee;
}
