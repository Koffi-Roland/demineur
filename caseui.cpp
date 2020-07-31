#include "caseui.h"

CaseUI::CaseUI()
{

}

void CaseUI::devoiler(){
    _case->devoiler();
}

void CaseUI::marquer(){
    _case->marquer();
}

void CaseUI::desactiver() {
    _case->desactiver();
}

CaseUI::CaseUI(Case* case_, size_t taille, QWidget *parent) :QPushButton("",parent){
    _case=case_;
    this->setText(getNombreMines());
    this->setGeometry(QRect(
        QPoint(taille * getCase()->getX(), taille * getCase()->getY()),
        QSize(taille, taille)
    ));
}

Case* CaseUI::getCase(){
    return _case;
}

CaseUI::~CaseUI() {
    delete this ;
}

QString CaseUI::getNombreMines(){
    int n=_case->getNombreMines();
    std::string s = std::to_string(n);
    char const *pchar = s.c_str();
    return pchar;
}

void CaseUI::auClickDroit(){
    this->getCase()->devoiler();
    this->setText("d"); // Pour tester
}

void CaseUI::auClickGauche(){
    this->getCase()->marquer();
    this->setText("m"); // Pour tester
}
