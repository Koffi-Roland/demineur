#ifndef DEVOILEE_H
#define DEVOILEE_H

#include "etat.h"

class Devoilee : public Etat
{
public:
    Devoilee();
    void devoiler();
    void marquer();
    void desactiver();
};

#endif // DEVOILEE_H
