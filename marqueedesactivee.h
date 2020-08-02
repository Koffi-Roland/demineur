#ifndef MARQUEEDESACTIVEE_H
#define MARQUEEDESACTIVEE_H

#include "etat.h"

class MarqueeDesactivee : public Etat
{
public:
    MarqueeDesactivee();
    void initialiser();
    void devoiler();
    void marquer();
    void desactiver();
    int getEtat();
};

#endif // MARQUEEDESACTIVEE_H
