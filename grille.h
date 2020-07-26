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
    std::vector<std::vector<Case*>> cases;
    static Grille* instance;
    /*Constructeur privé pour éviter l'instanciation*/
    Grille();
    Grille(size_t,size_t);

public:
   ~Grille(void);
    static Grille* getInstance();
    Case* getCase(size_t,size_t);
    std::vector<std::vector<Case*>> getCases();
    size_t getLigne();
    size_t getColonne();
    void setMines(int);
};

#endif // GRILLE_H
