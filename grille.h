#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <iostream>
#include "case.h"
#include "interfacegrille.h"
#include <QString>
#include <chrono>
#include <ctime>

class Grille : private InterfaceGrille
{

private:
    size_t ligne;
    size_t colonne;
    size_t nombreMines;
    std::vector<Case*> cases;
    int saturation = 3; // Nombres maximale de mines autour d'une case
public:
    Grille();
    Grille(size_t, size_t, size_t);
    ~ Grille();
    Case* getCase(size_t,size_t);
    Case* getCase(size_t);
    std::vector<Case*> getCases();
    size_t getLigne();
    size_t getColonne();
    void setMines(Case *);
    std::vector<Case*> getMinees();
    size_t getNombreMineesRestant();
    size_t getNombreMarquees();
    bool estTerminee();
    void desactiverCases();
    void initialiser();
    void reinitialiser();
    void initialiser(Etat *);
    int getTempEcoule();
    void terminerAvecEchec();
};

#endif // GRILLE_H
