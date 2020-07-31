#ifndef DESACTIVEE_H
#define DESACTIVEE_H

#include "etat.h"

class Desactivee : public Etat
{
public:
    Desactivee();
    void devoiler();
    void marquer();
    void desactiver();
    int getEtat();
};

#endif // DESACTIVEE_H
