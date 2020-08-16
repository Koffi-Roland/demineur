#include "util.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QVariant>
#include <QSpacerItem>
#include <QSplitter>
#include <QDebug>


Donnee::Donnee(){}

Donnee::~Donnee(){}

Donnee::Donnee(QHBoxLayout* layout, QWidget* parent, int _nombre, QString urlIcone) :
    QWidget(parent)
{
    this->setStyleSheet("border-radius:3px; background-color:#B1CBCB");
    QHBoxLayout* layoutDonneesGauche = new QHBoxLayout (this);

    icone  = new QLabel(this);
    icone->setPixmap(QPixmap(urlIcone));
    layoutDonneesGauche->addWidget(icone);

    nombre = new QLCDNumber(5);
    nombre->setStyleSheet("background-color:#000000");
    nombre->setProperty("intValue", QVariant(_nombre));
    nombre->setMinimumSize(QSize(30, 30));
    layoutDonneesGauche->addWidget(nombre);
    layout->addWidget(this);
}

void Donnee::setNombre(int _nombre) {
     nombre->setProperty("intValue", QVariant(_nombre));
}

void Donnee::setIcone(QString urlIcone){
    icone->setPixmap(QPixmap(urlIcone));
}


TypeJeux::TypeJeux(QWidget* centralWidget)
{
    QFrame *line;

    QSplitter * zoneTypesJeux = new QSplitter(centralWidget);
    zoneTypesJeux->setGeometry(QRect(40, 10, 720, 40));
    zoneTypesJeux->setOrientation(Qt::Horizontal);
    zoneTypesJeux->setStyleSheet("border-radius:3px;");

    debutant = new QRadioButton("Débutant", zoneTypesJeux);
    debutant->setChecked(true);
    moyen = new QRadioButton("Intermédiaire", zoneTypesJeux);
    expert = new QRadioButton("Expert", zoneTypesJeux);
    nouvellePartie = new QToolButton (centralWidget);
    nouvellePartie->setText("Jouer");
    nouvellePartie->setGeometry(QRect(300, 60, 200, 40));

    debutant->setStyleSheet("padding:10px; background-color:#B1CBCB");
    moyen->setStyleSheet("padding:10px; background-color:#B1CBCB");
    expert->setStyleSheet("padding:10px; background-color:#B1CBCB");

    debutant->setMinimumWidth(200);
    moyen->setMinimumWidth(200);
    expert->setMinimumWidth(200);

    line = new QFrame(centralWidget);
    line->setGeometry(QRect(50, 50, 700, 10));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    initialiser();
}

TypeJeux::~TypeJeux(){}
size_t  TypeJeux::getLigne()
{
    return  ligne;
}
size_t  TypeJeux::getColonne()
{
    return  colonne;
}

size_t  TypeJeux::getNombreMines()
{
    return  nombreMines;
}

void TypeJeux::setParametre(size_t _ligne, size_t _colonne, size_t _nombreMines)
{
    ligne = _ligne;
    colonne = _colonne;
    nombreMines = _nombreMines;
}

void TypeJeux::initialiser()
{
    if(debutant->isChecked()){
        setParametre(9, 9, 10);
    }

    if(moyen->isChecked()){
        setParametre(16, 16, 40);
    }

    if(expert->isChecked()){
        setParametre(16, 30, 99);
    }
}

QToolButton* TypeJeux::getNouvellePartie()
{
    return nouvellePartie;
}
