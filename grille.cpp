
#include "grille.h"

/*========== Application de design pattern Singleton=========*/

Grille::Grille()
{

}
Grille::Grille(int longueur,int largeur, std::vector<std::vector<Case>> cases)
{
    this->longueur = longueur;
    this->largeur= largeur;
    this->cases= cases;


}
Grille::~Grille()
{

}

Grille* Grille::instance = 0;

Grille* Grille::getInstance()
{
    if (instance == 0)
    {
        instance = new Grille();
    }

    return instance;
}

std::vector<std::vector<Case>> Grille::getCases()
{
    return instance->cases;
}
