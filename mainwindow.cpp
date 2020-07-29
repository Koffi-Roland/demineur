#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    grilleUI=new GrilleUI(this, 16, 16);
    for (CaseUI *_caseui :  grilleUI->getCasesUI()) {
        connect(_caseui, SIGNAL (clicked()), this, SLOT (handleButton()));
    }
}

void MainWindow::handleButton()
{
qDebug() << "Date:" <<this;
}
