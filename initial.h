#ifndef INITIAL_H
#define INITIAL_H
#include "etat.h"

class Initial : public Etat
{
public:
    Initial();
    void devoiler();
    void marquer();
    void desactiver();
    int getEtat();
};

#endif // INITIAL_H
