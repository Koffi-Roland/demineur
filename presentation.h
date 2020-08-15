#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <QPushButton>
#include <QRadioButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QTimer>
#include "partie.h"
#include "grilleui.h"
#include "util.h"
#include <QMainWindow>
#include "grilleui.h"

class Presentation : public QGridLayout
{
private:
    QWidget* cadre;
    Partie *partie;
    Donnee* nombreMinesMasquees;
    Donnee* tempsEcoule;
    QTimer* _timer;
    QWidget* widgetGrille;
    QGridLayout* gridLayoutGrille;
    GrilleUI* grilleUI = nullptr;
    TypeJeux*  typeJeux;
    QWidget *centralWidget;

public:
    Presentation();
    Presentation(QWidget*, QMainWindow*);
    void setTextes(QMainWindow*);
    Partie* getPartie();
    QRadioButton* getDebutant();
    QRadioButton* getMoyen();
    QRadioButton* getExpert();
    QToolButton* getNouvellePartie();
    void setNombreMinesMasquees();
    void setTempsEcoule();
    QWidget* getWidgetGrille();
    QGridLayout* getGridLayoutGrille();
    QTimer* getTimer();
    void initialiserGrille(size_t, size_t, size_t);
    void jouer();
    void definirMenus(QMainWindow* );
};

#endif // PRESENTATION_H
