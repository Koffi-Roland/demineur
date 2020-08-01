#include "caseui.h"
#include <QDebug>
#include <QMouseEvent>
#include "enumetats.h"
#include "grilleui.h"

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
    this->setGeometry(QRect(
        QPoint(taille * getCase()->getX(), taille * getCase()->getY()),
        QSize(taille, taille)
    ));
    this->setStyleSheet("background-color:#B1CBCB;");
}

Case* CaseUI::getCase(){
    return _case;
}

GrilleUI * CaseUI::getGrilleUI(){
    return grilleUI;
}

void CaseUI::setGrilleUI(GrilleUI * _grilleUI){
    grilleUI = _grilleUI;
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

void CaseUI::auClickDroit(){
    marquer();
}

void CaseUI::auClickGauche(){
    devoiler();
}

void CaseUI::mousePressEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton) {
        auClickGauche();
    }
    if(event->button() == Qt::RightButton) {
         auClickDroit();
    }
    CaseUI::getGrilleUI()->rafraichir();
}


void CaseUI::rafraichir() {
    int etat = _case->getEtat();
    switch (etat) {
        case EnumEtats::NonDevoilee :
            this->setStyleSheet("background-color:#B1CBCB;");
        break;

        case EnumEtats::Marquee :
            this->setIcon(QIcon("C:/demineur/10409.png"));
            this->setStyleSheet("background-color:#FFAA00;");
        break;

        case EnumEtats::Desactivee :
            this->setDisabled(true);
            this->setStyleSheet((_case->estMinee()) ? "background-color:#FF0000" : "");
            this->setIcon(QIcon((_case->estMinee()) ? "C:/demineur/bombe_.png":""));

        break;

        case EnumEtats::Devoilee :
           this->setText(getNombreMines());
           this->setStyleSheet("background-color:#FFFFFF;");
        break;
    }
}

