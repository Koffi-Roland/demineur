#ifndef UTIL_H
#define UTIL_H
#include <QWidget>
#include <QLCDNumber>
#include <QLabel>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QToolButton>


/**
 * @brief The Donnee class
 */
class Donnee : public QWidget
{
private:
    QLCDNumber * nombre;
    QLabel* icone;

public:
   Donnee();
   Donnee(QHBoxLayout*, QWidget*, int, QString);
   void setNombre(int);
   void setIcone(QString);
   ~ Donnee();
};

/**
 * @brief The TypeJeux class
 */
class TypeJeux : public QWidget
{
private:
    QRadioButton *debutant;
    QRadioButton *moyen;
    QRadioButton *expert;
    QToolButton *nouvellePartie;
    size_t ligne;
    size_t colonne;
    size_t nombreMines;

public:
   TypeJeux();
   TypeJeux(QWidget*);
   void setApparence();
   ~ TypeJeux();
   size_t getLigne();
   size_t getColonne();
   size_t getNombreMines();
   void setParametre(size_t, size_t, size_t);
   void initialiser();
   QToolButton * getNouvellePartie();
};
#endif // UTIL_H
