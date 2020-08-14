#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caseui.h"
#include <vector>
#include "grilleui.h"
#include "presentation.h"
#include <QTimer>
#include <QLCDNumber>
#include <QSplitter>
#include <QRadioButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void initialiser(size_t, size_t, size_t);

signals :
public slots :
    void chrono();
    void rejouer();
    void jouerModeDebutant();
    void jouerModeMoyen();
    void jouerModeExpert();

private:
    GrilleUI *grilleUI;
    Presentation * presentation;
};



#endif // MAINWINDOW_H
