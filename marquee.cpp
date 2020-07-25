#include "marquee.h"
#include "case.h"
#include "nondevoilee.h"

Marquee::Marquee(){}

void Marquee::devoiler(){
}

void Marquee::marquer(){
    _case->passerAlEtat(new NonDevoilee());
}
