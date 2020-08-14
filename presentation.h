#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <QPushButton>
#include <QLCDNumber>
#include <QRadioButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QTimer>
#include "partie.h"
#include "grilleui.h"
#include <QMainWindow>

class Presentation : public QGridLayout
{
private:
    Partie *partie;
    QLCDNumber* nombreMinesMasquees;
    QLCDNumber* tempsEcoule;
    QTimer* _timer;
    QWidget* widgetGrille;
    QGridLayout* gridLayoutGrille;
    GrilleUI* grilleUI = nullptr;
    QRadioButton *debutant;
    QRadioButton *moyen;
    QRadioButton *expert;
    QPushButton *nouvellePartie;

public:
    Presentation();
    Presentation(QWidget*, QMainWindow*);
    void setTextes(QMainWindow*);
    Partie* getPartie();
    QRadioButton* getDebutant();
    QRadioButton* getMoyen();
    QRadioButton* getExpert();
    QPushButton* getNouvellePartie();
    void setNombreMinesMasquees();
    void setTempsEcoule();
    QWidget* getWidgetGrrille();
    QGridLayout* getGridLayoutGrille();
    QTimer* getTimer();
    void initialiserGrille(size_t, size_t, size_t);
    void jouer();
};

#endif // PRESENTATION_H
