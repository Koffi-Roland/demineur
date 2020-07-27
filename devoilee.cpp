#include "devoilee.h"
#include "desactivee.h"
#include "case.h"


Devoilee::Devoilee(){}

void Devoilee::devoiler(){}

void Devoilee::marquer(){}

void Devoilee::desactiver() {
    _case->passerAlEtat(new Desactivee());
};
