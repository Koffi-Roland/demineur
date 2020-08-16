#include "partie.h"
#include "initial.h"
#include <QDebug>

Partie::Partie(){}

Partie::Partie(Grille* _grille) {
    grille = _grille;
    grille->setPartieEncours(this);
    grille->reinitialiser();
}

Grille * Partie::getGrille() {
    return grille;
}

void Partie::demarrer() {
    this->tempsDebut = std::time(nullptr);
    this->tempsFin = std::time(nullptr);
}

void Partie::terminer()
{
    terminee = true;
}

bool Partie::estTerminee(){
    terminee = grille->estTerminee();
    return terminee ;
}

int Partie::getTempEcoule() {
    if( ! terminee ){
        tempsFin = std::time(nullptr);
    }
    return int(tempsFin - tempsDebut);
}
