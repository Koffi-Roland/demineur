#include "partie.h"
#include "initial.h"
#include <QDebug>

Partie::Partie(){}

Partie::Partie(Grille* _grille) {
    grille = _grille;
    grille->reinitialiser();
}

Grille * Partie::getGrille() {
    return grille;
}

void Partie::demarrer() {
    if (tempsDebut == 0){
        tempsDebut = std::time(nullptr);
    }
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
    if(!estTerminee()){
        tempsFin = std::time(nullptr);
    }
    return (tempsDebut == 0) ? 0 : int(tempsFin - tempsDebut);
}
