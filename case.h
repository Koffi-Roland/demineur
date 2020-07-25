#ifndef CASE_H
#define CASE_H
#include <iostream>
#include "etat.h"
#include <vector>

class Grille;

class Case
{
private:
    size_t x;
    size_t y;
    bool minee = false;
    Grille *_grille;
    Etat *_etat;
public:
    Case();
    Case(size_t, size_t, Etat *, Grille *);
    ~Case(void);
    std::vector<Case*> getVoisines();
    int getNombreMines();
    void setMinee();
    bool estMinee();
    void passerAlEtat(Etat*);
    void devoiler();
    void marquer();
    Grille* getGrille(){
        return _grille;
    }
};

#endif // CASE_H
