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
    void desactiver();
    void devoilerVoisines();
    size_t getX();
    size_t getY();

    Grille* getGrille(){
        return _grille;
    }
};

#endif // CASE_H
