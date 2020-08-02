#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->resize(600, 620);
    QWidget *centralwidget = new QWidget(this);

    QVBoxLayout *verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QStringLiteral("VerticalLayout"));


    QLabel *bombe = new QLabel("0");
    bombe->setStyleSheet("background-color:#FF0000;");
    bombe->setContentsMargins(15,20,10,30);
    bombe->setMinimumHeight(30);
    bombe->setMinimumWidth(30);

    QLabel *mineRestant = new QLabel("0");
    mineRestant->setStyleSheet("background-color:#FFFFFF;");
    mineRestant->setContentsMargins(15,20,10,30);
    mineRestant->setMinimumHeight(30);
    mineRestant->setMinimumWidth(30);


    QTimer *timer = new QTimer(this);
    QGridLayout *labelAndTimer = new QGridLayout;
    labelAndTimer->setObjectName(QStringLiteral("labelAndTimer"));
    labelAndTimer->setSizeConstraint(QLayout::SetNoConstraint);
    labelAndTimer->setVerticalSpacing(10);

    labelAndTimer->addWidget(bombe, 10, 10);
    labelAndTimer->addWidget(mineRestant, 10, 15);


    //labelAndTimer->addWidget(timer, 0, 1);

    grilleUI=new GrilleUI(this, 16, 16, 50);
    grilleUI->setSpacing(0);
    grilleUI->setObjectName(QStringLiteral("grille"));
    grilleUI->setSizeConstraint(QLayout::SetNoConstraint);


    verticalLayout->addLayout(labelAndTimer);
    verticalLayout->addLayout(grilleUI);



    this->show();

}
