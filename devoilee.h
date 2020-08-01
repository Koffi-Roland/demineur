#ifndef DEVOILEE_H
#define DEVOILEE_H

#include "etat.h"

class Devoilee : public Etat
{
public:
    Devoilee();
    void initialiser();
    void devoiler();
    void marquer();
    void desactiver();
    int getEtat();
};

#endif // DEVOILEE_H
