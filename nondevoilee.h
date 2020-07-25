#ifndef NONDEVOILEE_H
#define NONDEVOILEE_H

#include "etat.h"

class NonDevoilee : public Etat
{
public:
    NonDevoilee();
    void devoiler();
    void marquer();
};

#endif // NONDEVOILEE_H
