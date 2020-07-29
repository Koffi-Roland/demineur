#ifndef FENETRE_H
#define FENETRE_H

#endif // FENETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <vector>
#include <grille.h>
#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include <QtWidgets/QPushButton>


QT_BEGIN_NAMESPACE

class fenetre:public QMainWindow
{
   Q_OBJECT
private slots:
    void handlebutton(){
        _case->setText("Example");
    };

private:
    explicit fenetre(QWidget *parent = 0);

public:

   QAction *actionVersion_1;
   QAction *actionAZIAWOR_KOFFI;
   QAction *actionCOUBADJA_MAYI_MOUNA;
   QAction *actionCOUBADJA_MAYI_MOUNA_2;
   QWidget *centralwidget;
   QGridLayout *gridLayout_3;
   QGridLayout *grille;
   QMenuBar *menubar;
   QMenu *menuA_Propos;
   QMenu *menuAide;
   QMenu *menuParticipants;
   QStatusBar *statusbar;
   QPushButton *_case;


   void setupUi2(QMainWindow *MainWindow)
   {
       if (MainWindow->objectName().isEmpty())
           MainWindow->setObjectName(QStringLiteral("MainWindow"));
       MainWindow->resize(405, 312);
       MainWindow->setLayoutDirection(Qt::LeftToRight);
       actionVersion_1 = new QAction(MainWindow);
       actionVersion_1->setObjectName(QStringLiteral("actionVersion_1"));
       actionAZIAWOR_KOFFI = new QAction(MainWindow);
       actionAZIAWOR_KOFFI->setObjectName(QStringLiteral("actionAZIAWOR_KOFFI"));
       actionCOUBADJA_MAYI_MOUNA = new QAction(MainWindow);
       actionCOUBADJA_MAYI_MOUNA->setObjectName(QStringLiteral("actionCOUBADJA_MAYI_MOUNA"));
       actionCOUBADJA_MAYI_MOUNA_2 = new QAction(MainWindow);
       actionCOUBADJA_MAYI_MOUNA_2->setObjectName(QStringLiteral("actionCOUBADJA_MAYI_MOUNA_2"));
       centralwidget = new QWidget(MainWindow);
       centralwidget->setObjectName(QStringLiteral("centralwidget"));
       QFont font;
       font.setBold(true);
       font.setWeight(75);
       centralwidget->setFont(font);
       gridLayout_3 = new QGridLayout(centralwidget);
       gridLayout_3->setSpacing(0);
       gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
       gridLayout_3->setContentsMargins(0, 0, 0, 0);
       grille = new QGridLayout();
       grille->setSpacing(0);
       grille->setObjectName(QStringLiteral("grille"));
       grille->setSizeConstraint(QLayout::SetNoConstraint);

       Grille * grille_metier = Grille::getInstance();
       grille_metier->setMines(10);

       for (int i = 0; i < grille_metier->getLigne(); ++i) {
           //  std::vector<QToolButton*> ligne;
           for (int j = 0; j < grille_metier->getColonne(); ++j) {
              // QToolButton *_case;
               _case = new QPushButton(centralwidget);

              // _case = new QToolButton(centralwidget);
               //_case->setObjectName(QStringLiteral("case24"));
               _case->setMinimumSize(QSize(40, 40));
               connect(_case, SIGNAL (clicked()),this, SLOT (handlebutton()));

               int n = grille_metier->getCase(i,j)->getNombreMines();
               std::string s = std::to_string(n);
               char const *pchar = s.c_str();
               _case->setText(QApplication::translate("MainWindow", pchar , Q_NULLPTR));
               grille->addWidget(_case, i, j, 1, 1);

           }
       }

       gridLayout_3->addLayout(grille, 0, 0, 1, 1);

       MainWindow->setCentralWidget(centralwidget);
       menubar = new QMenuBar(MainWindow);
       menubar->setObjectName(QStringLiteral("menubar"));
       menubar->setGeometry(QRect(0, 0, 405, 21));
       menuA_Propos = new QMenu(menubar);
       menuA_Propos->setObjectName(QStringLiteral("menuA_Propos"));
       menuAide = new QMenu(menubar);
       menuAide->setObjectName(QStringLiteral("menuAide"));
       menuParticipants = new QMenu(menubar);
       menuParticipants->setObjectName(QStringLiteral("menuParticipants"));
       MainWindow->setMenuBar(menubar);
       statusbar = new QStatusBar(MainWindow);
       statusbar->setObjectName(QStringLiteral("statusbar"));
       MainWindow->setStatusBar(statusbar);

       menubar->addAction(menuA_Propos->menuAction());
       menubar->addAction(menuAide->menuAction());
       menubar->addAction(menuParticipants->menuAction());
       menuA_Propos->addAction(actionVersion_1);
       menuParticipants->addAction(actionAZIAWOR_KOFFI);
       menuParticipants->addSeparator();
       menuParticipants->addAction(actionCOUBADJA_MAYI_MOUNA);
       menuParticipants->addSeparator();
       menuParticipants->addAction(actionCOUBADJA_MAYI_MOUNA_2);

       retranslateUi(MainWindow);

       QMetaObject::connectSlotsByName(MainWindow);
   } // setupUi

   void retranslateUi(QMainWindow *MainWindow)
   {
       MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Demineur", Q_NULLPTR));
       actionVersion_1->setText(QApplication::translate("MainWindow", "Version 1", Q_NULLPTR));
       actionAZIAWOR_KOFFI->setText(QApplication::translate("MainWindow", "COUBADJA MAYI-MOUNA", Q_NULLPTR));
       actionCOUBADJA_MAYI_MOUNA->setText(QApplication::translate("MainWindow", "AZIAWOR KOFFI", Q_NULLPTR));
       actionCOUBADJA_MAYI_MOUNA_2->setText(QApplication::translate("MainWindow", "HOETOHOU YAOVI", Q_NULLPTR));
       /*  case24->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));*/

       menuA_Propos->setTitle(QApplication::translate("MainWindow", "A Propos", Q_NULLPTR));
       menuAide->setTitle(QApplication::translate("MainWindow", "Aide?", Q_NULLPTR));
       menuParticipants->setTitle(QApplication::translate("MainWindow", "Participants", Q_NULLPTR));
   } // retranslateUi

};

namespace Ui {
class fenetre;
        //: public fenetre {};
} // namespace Ui
