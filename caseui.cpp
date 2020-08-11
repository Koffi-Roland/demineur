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

CaseUI::CaseUI(QGridLayout *grille,Case* case_, size_t taille, QWidget *parent) :QPushButton("",parent){
    _case=case_;


   /* this->setGeometry(QRect(
        QPoint(taille * getCase()->getX()+9, taille * getCase()->getY()+40),
        QSize(taille, taille)
    ));*/
    this->setStyleSheet("background-color:#B1CBCB;");


    this->setMinimumSize(QSize(taille, taille));
    this->setMaximumSize(QSize(taille, taille));

     grille->addWidget(this, _case->getX(), _case->getY(), 1, 1);



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
            this->setIcon(QIcon(":/resources/img/flag.png"));
            this->setStyleSheet("background-color:#FFAA00;");
        break;

        case EnumEtats::Desactivee :
            // this->setDisabled(true);
            if (this->getCase()->estMinee()){
                this->setStyleSheet("background-color:#FF0000");
                this->setIcon(QIcon(":/resources/img/bombe_.png"));
                 /* son=new QSound(":/resources/son/son_bombe.wav");
                   son->play();
                   son->stop();*/
            }
        break;

        case EnumEtats::Devoilee :
           this->setText(getNombreMines());
           this->setStyleSheet("background-color:#FFFFFF;");
        break;
    case EnumEtats::MarqueeDesactivee :
        this->setIcon(QIcon(""));
        if (this->getCase()->estMinee()){
            this->setIcon(QIcon(":/resources/img/bombe_.png"));
        }
    break;
    }
}

