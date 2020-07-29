#include "caseui.h"

/*CaseUI::CaseUI()
{

}*/


CaseUI::CaseUI(Case* case_,const QString &text, QWidget *parent ) :QPushButton(text,parent){

    _case=case_;
}

Case* CaseUI::getCase(){
    return _case;
}
CaseUI::~CaseUI(){
    delete this ;

}

QString CaseUI::getNombreMines(){
    int n=_case->getNombreMines();
    std::string s = std::to_string(n);
    char const *pchar = s.c_str();
    return pchar;
}

void CaseUI::auClick(){

    this->setText("2");

}
