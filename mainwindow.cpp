#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    grilleUI=new GrilleUI(this);
    for (CaseUI *_caseui :  grilleUI->getCasesUI()) {
        _caseui->setGeometry(QRect(QPoint(40*_caseui->getCase()->getX(), 40*_caseui->getCase()->getY()),
                                   QSize(40, 40)));
        connect(_caseui, SIGNAL (clicked()), this, SLOT (handleButton()));

    }


}

void MainWindow::handleButton()
{
qDebug() << "Date:" <<this;
}
