#include "mainwindow.h"
#include <QDebug>

#include <QCoreApplication>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    QWidget *centralwidget = new QWidget(this);

    QGridLayout  *basegridLayout = new QGridLayout(centralwidget);
    basegridLayout->setSpacing(0);
    basegridLayout->setObjectName(QStringLiteral("gridLayout_3"));
    basegridLayout->setContentsMargins(0, 0, 0, 0);

    //   QWidget *window = new QWidget;
    QLabel *bombe = new QLabel("0");
    bombe->setStyleSheet("background-color:#FF0000;");
    bombe->setMargin(10);
    QLabel *mineRestant = new QLabel("0");
    mineRestant->setStyleSheet("background-color:#FFFFFF;");


    QTimer *timer = new QTimer(this);
    QGridLayout *labelAndTimer = new QGridLayout;
    labelAndTimer->setObjectName(QStringLiteral("labelAndTimer"));
    labelAndTimer->setSizeConstraint(QLayout::SetNoConstraint);
//    labelAndTimer->setMargin(20);

    labelAndTimer->addWidget(bombe, 10, 10);
    labelAndTimer->addWidget(mineRestant, 10, 15);


    //labelAndTimer->addWidget(timer, 0, 1);

    grilleUI=new GrilleUI(this, 16, 16, 50);
    grilleUI->setSpacing(0);
    grilleUI->setObjectName(QStringLiteral("grille"));
    grilleUI->setSizeConstraint(QLayout::SetNoConstraint);
    basegridLayout->addLayout(grilleUI, 0, 0, 1, 1);
    basegridLayout->addLayout(labelAndTimer, 0, 0, 1,1);


    /* QGridLayout *layout = new QGridLayout;
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);*/

    // grilleUI->addWidget(button1,20,20);
    //this->setCentralWidget(centralwidget);
    this->show();

    /* QGridLayout *layout = new QGridLayout;
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);
    layout->addLayout(grilleUI, 1, 0, 1, 2);


    window->setLayout(layout);
    this->show();*/

    /*QWidget *centralwidget = new QWidget(this);

    grilleUI=new GrilleUI(centralwidget, 16, 16, 50);
    grilleUI->setSpacing(0);
    grilleUI->setObjectName(QStringLiteral("grille"));
    grilleUI->setSizeConstraint(QLayout::SetNoConstraint);
    this->setCentralWidget(centralwidget);*/
}
