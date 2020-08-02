#ifndef CASE_H
#define CASE_H
#include <iostream>
#include <vector>
#include "etat.h"
#include "interfacecase.h"

class Grille;

class Case : private InterfaceCase
{
private:
    size_t x;
    size_t y;
    bool minee = false;
    bool marquee = false;
    Grille *_grille;
    Etat *_etat;
public:
    Case();
    Case(size_t, size_t, Grille *);
    ~Case();
    std::vector<Case*> getVoisines();
    int getNombreMines();
    void setMinee();
    bool estMinee();
    void passerAlEtat(Etat*);
    int getEtat();
    void devoilerVoisines();
    bool estVoisine(Case *);
    size_t getX();
    size_t getY();
    Grille* getGrille();
    void initialiser();
    void devoiler();
    void marquer();
    void desactiver();
};

#endif // CASE_H
