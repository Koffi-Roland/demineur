#include "caseui.h"
#include <QDebug>
#include "enumetats.h"

CaseUI::CaseUI()
{

}

void CaseUI::devoiler(){
    qDebug() << "CaseUI::devoiler" << this;
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

    // Pour tester
    if(_case->estMinee()){
        this->setText("m");
    }


    this->setGeometry(QRect(
        QPoint(taille * getCase()->getX(), taille * getCase()->getY()),
        QSize(taille, taille)
    ));
    this->setStyleSheet("background-color:#B1CBCB;");
}

Case* CaseUI::getCase(){
    return _case;
}

CaseUI::~CaseUI() {
    delete this ;
}

QString CaseUI::getNombreMines(){
    int n = _case->getNombreMines();
    if( n == 0){
        return "";
    }
    std::string s = std::to_string(n);
    char const *pchar = s.c_str();
    return pchar;
}

void CaseUI::auClickDroit(QMouseEvent *event){
    qDebug() << "droit:" << this;
}

void CaseUI::auClickGauche(QMouseEvent *event){
    devoiler();
}
void CaseUI::mousePressEvent(QMouseEvent *event){
    auClickGauche(event);
}

void CaseUI::setApparence() {
    int etat = _case->getEtat();
    switch (etat) {
        case EnumEtats::NonDevoilee :
            this->setStyleSheet("background-color:#B1CBCB;");
        break;

        case EnumEtats::Marquee :
            this->setStyleSheet("background-color:#FF0000;");
        break;

        case EnumEtats::Devoilee :
            this->setStyleSheet("background-color:white;");
        break;

        case EnumEtats::Desactivee :
            this->setStyleSheet("background-color:#CCCCCC;");
        break;
    }
}

