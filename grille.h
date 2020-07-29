#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <iostream>
#include "case.h"

class Grille
{

private:
    size_t ligne;
    size_t colonne;
    std::vector<Case*> cases;
public:
    Grille();
    Grille(size_t,size_t);
   ~Grille(void);
    Case* getCase(size_t,size_t);
    Case* getCase(size_t);
    std::vector<Case*> getCases();
    size_t getLigne();
    size_t getColonne();
    void setMines(int);
    void devoilerMinees();
    void desactiverCases();
    void terminerAvecEchec();
};

#endif // GRILLE_H
