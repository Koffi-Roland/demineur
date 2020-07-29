#ifndef CASEUI_H
#define CASEUI_H
#include <QPushButton>
#include "case.h"




class CaseUI:public QPushButton
{

private:
    Case *_case;
public:
   explicit CaseUI(Case*, size_t, QWidget *parent = Q_NULLPTR);
   CaseUI();
   Case* getCase();
   QString getNombreMines();
   void auClickDroit();
   void auClickGauche();
   ~CaseUI();
};

#endif // CASEUI_H
