#include "initial.h"
#include "enumetats.h"
#include "case.h"
#include "grille.h"
#include "nondevoilee.h"

Initial::Initial()
{

}
void Initial::devoiler(){
    _case->getGrille()->setMines(_case);
    _case->passerAlEtat(new NonDevoilee());
    _case->devoiler();
}
void Initial::marquer(){}
void Initial::desactiver(){};
int Initial::getEtat(){
    return EnumEtats::Initial;
}
