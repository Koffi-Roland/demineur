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

};

#endif // MAINWINDOW_H
