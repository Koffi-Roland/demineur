#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caseui.h"
#include <vector>
#include "grilleui.h"
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *_Timer;
    QLabel *mineRestant;
    QLabel *bombe;
    int counter;

signals :

public slots :

    void chrono();

private:
    // std::vector<std::vector<CaseUI>>
    CaseUI *m_button;
    GrilleUI *grilleUI;
};

#endif // MAINWINDOW_H
