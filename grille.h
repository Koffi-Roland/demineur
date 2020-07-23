#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <iostream>
#include "case.h"

class Grille
{

private:
    int longueur;
    int largeur;
    std::vector<std::vector<Case>> cases;
    static Grille* instance;
    /*Constructeur privé pour éviter l'instanciation*/
    Grille();
    Grille(int,int);
    Grille(int,int,std::vector<std::vector<Case>>);

public:
   ~Grille(void);
    static Grille* getInstance();
    std::vector<std::vector<Case>> getCases();


};

#endif // GRILLE_H
