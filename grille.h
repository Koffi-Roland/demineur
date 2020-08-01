#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <iostream>
#include "case.h"
#include "interfacegrille.h"

class Grille : private InterfaceGrille
{

private:
    size_t ligne;
    size_t colonne;
    size_t nombreMines;
    std::vector<Case*> cases;
public:
    Grille();
    Grille(size_t,size_t, size_t);
   ~Grille(void);
    Case* getCase(size_t,size_t);
    Case* getCase(size_t);
    std::vector<Case*> getCases();
    size_t getLigne();
    size_t getColonne();
    void setMines(Case *);
    std::vector<Case*> getMinees();
    size_t getNombreMineesRestant();
    void desactiverCases();
    void initialierCases();
    void terminerAvecEchec();
};

#endif // GRILLE_H
