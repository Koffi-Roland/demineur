#ifndef CASEUI_H
#define CASEUI_H
#include <QPushButton>
#include <QGridLayout>
//#include <QSound>

#include "case.h"

class GrilleUI;

class CaseUI: private InterfaceCase, public QPushButton
{

private slots:
    void clickGauche();
private:
    GrilleUI * grilleUI;
    Case *_case;
   // QSound *son;

public:
   explicit CaseUI(QGridLayout*,Case*, size_t, QWidget *parent = Q_NULLPTR);
   CaseUI();
   Case* getCase();
   QString getNombreMines();
   void auClickDroit();
   void auClickGauche();
   void setBackGround(QString);
   void mousePressEvent(QMouseEvent *);
   void devoiler();
   void marquer();
   void desactiver();
   void rafraichir();
   GrilleUI * getGrilleUI();
   void setGrilleUI(GrilleUI *);
   ~CaseUI();
};

#endif // CASEUI_H
