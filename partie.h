#ifndef PARTIE_H
#define PARTIE_H
#include <vector>
#include <iostream>
#include "grille.h"
#include <QString>
#include <chrono>
#include <ctime>

class Partie
{
private:
    Grille *grille;
    bool terminee = false;
    bool gagnee = false;
    std::time_t tempsDebut = 0;
    std::time_t tempsFin = 0;
public:
    Partie();
    Partie(Grille *);
    Grille * getGrille();
    void demarrer();
    int getTempEcoule();
    void terminer();
    bool estTerminee();
    bool estGagnee();
};

#endif // PARTIE_H
