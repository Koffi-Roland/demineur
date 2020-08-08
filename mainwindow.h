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

signals :
public slots :
    void chrono();

private:
    GrilleUI *grilleUI;
};

#endif // MAINWINDOW_H
