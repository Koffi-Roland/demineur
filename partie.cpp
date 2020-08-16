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
    grille->desactiverCases();
    terminee = true;
}

bool Partie::estTerminee(){
    terminee = grille->estTerminee();
    return terminee ;
}

bool Partie::estGagnee()
{
    return  gagnee;
}

int Partie::getTempEcoule() {
    if(grille->getNombreMineesRestant() == 0){
        terminer();
        gagnee = true;
    }
    if( ! terminee ){
        tempsFin = std::time(nullptr);
    }
    return int(tempsFin - tempsDebut);
}
