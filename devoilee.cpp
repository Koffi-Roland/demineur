#include "devoilee.h"
#include "desactivee.h"
#include "case.h"
#include "enumetats.h"


Devoilee::Devoilee(){}

void Devoilee::devoiler(){}

void Devoilee::marquer(){}

void Devoilee::desactiver() {
   // _case->passerAlEtat(new Desactivee());
};

int Devoilee::getEtat(){
    return EnumEtats::Devoilee;
}
