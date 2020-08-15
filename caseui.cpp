#include "caseui.h"
#include <QDebug>
#include <QMouseEvent>
#include "enumetats.h"
#include "grilleui.h"


CaseUI::CaseUI(){}

void CaseUI::devoiler() {
    _case->devoiler();
  //  grilleUI->getPartie()->demarrer();
}

void CaseUI::marquer(){
    _case->marquer();
}

void CaseUI::desactiver() {
    _case->desactiver();
}

CaseUI::CaseUI(QGridLayout *grille,Case* case_, size_t taille, QWidget *parent) :QPushButton("",parent){
    _case=case_;
    this->setBackGround("#B1CBCB");
    this->setMinimumSize(QSize(int(taille), int(taille)));
    this->setMaximumSize(QSize(int(taille), int(taille)));
    grille->addWidget(this, int(_case->getX()), int(_case->getY()), 1, 1);
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
    qDebug() << "caseUI::delete";
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

void CaseUI::setBackGround(QString couleur)
{
    this->setStyleSheet("border-radius:none; border:1px solid #E0EBEF; background-color:" + couleur);
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
            this->setBackGround("#B1CBCB");
        break;

        case EnumEtats::Marquee :
            this->setIcon(QIcon(":/resources/img/flag.png"));
            this->setBackGround("#FFAA00");
        break;

        case EnumEtats::Desactivee :
            if (this->getCase()->estMinee()){
                //this->setBackGround("#FF0000");
                this->setIcon(QIcon(":/resources/img/bombe_.png"));
            }
        break;

        case EnumEtats::Devoilee :
           this->setText(getNombreMines());
           this->setBackGround("#FFFFFF");
           if (this->getCase()->estMinee()){
                this->setBackGround("#FF0000");
           }
        break;
    case EnumEtats::MarqueeDesactivee :
        this->setIcon(QIcon(""));
        if (this->getCase()->estMinee()){
            this->setIcon(QIcon(":/resources/img/bombe_.png"));
        }
    break;
    }
}

