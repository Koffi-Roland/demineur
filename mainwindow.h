#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caseui.h"
#include <vector>
#include "grilleui.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void handleButton();
private:
   // std::vector<std::vector<CaseUI>>
    CaseUI *m_button;
    GrilleUI *grilleUI;
};

#endif // MAINWINDOW_H
