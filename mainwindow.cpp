#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>
#include <QTimer>
#include <string>


void MainWindow::chrono(){
     grilleUI->setTempsEcoule();
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->resize(600, 620);
    // this->minimumSize();
    QWidget *centralwidget = new QWidget(this);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    centralwidget->setFont(font);
    QVBoxLayout *verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QStringLiteral("VerticalLayout"));

    grilleUI=new GrilleUI(this, 20, 15, 40);
    grilleUI->setSpacing(0);
    grilleUI->setSizeConstraint(QLayout::SetNoConstraint);
    verticalLayout->addLayout(grilleUI);

    /* Partie timer*/
    QObject::connect(grilleUI->getTimer(), SIGNAL(timeout()), this,SLOT(chrono()));
    grilleUI->getTimer()->start();

    this->show();

}
