#ifndef MARQUEE_H
#define MARQUEE_H

#include "etat.h"

class Marquee : public Etat
{
public:
    Marquee();
    void devoiler();
    void marquer();
    void desactiver();
};

#endif // MARQUEE_H
