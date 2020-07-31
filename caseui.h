#ifndef CASEUI_H
#define CASEUI_H
#include <QPushButton>
#include "case.h"

class CaseUI: private InterfaceCase, public QPushButton
{

private slots:
    void clickGauche();
private:
    Case *_case;
public:
   explicit CaseUI(Case*, size_t, QWidget *parent = Q_NULLPTR);
   CaseUI();
   Case* getCase();
   QString getNombreMines();
   void auClickDroit(QMouseEvent *);
   void auClickGauche(QMouseEvent *);
   void mousePressEvent(QMouseEvent *);
   void devoiler();
   void marquer();
   void desactiver();
   void setApparence();
   ~CaseUI();
};

#endif // CASEUI_H
