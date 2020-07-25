#include "nondevoilee.h"
#include "case.h"
#include "devoilee.h"
#include "marquee.h"

NonDevoilee::NonDevoilee(){ }

void NonDevoilee::devoiler(){
   _case->passerAlEtat(new Devoilee());
}

void NonDevoilee::marquer(){
    _case->passerAlEtat(new Marquee());
}
