#include "initial.h"
#include "enumetats.h"
#include "case.h"
#include "grille.h"
#include "nondevoilee.h"
#include "marquee.h"
Initial::Initial()
{

}
void Initial::initialiser(){
     _case->passerAlEtat(new NonDevoilee());
}
void Initial::devoiler(){
    _case->getGrille()->setMines(_case);
    this->initialiser();
    _case->devoiler();
}
void Initial::marquer(){
     _case->passerAlEtat(new Marquee());
}
void Initial::desactiver(){};
int Initial::getEtat(){
    return EnumEtats::Initial;
}
