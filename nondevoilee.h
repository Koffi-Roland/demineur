#ifndef NONDEVOILEE_H
#define NONDEVOILEE_H

#include "etat.h"

class NonDevoilee : public Etat
{
public:
    NonDevoilee();
    void devoiler();
    void marquer();
    void desactiver();
};

#endif // NONDEVOILEE_H
