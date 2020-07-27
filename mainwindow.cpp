#include "mainwindow.h"
// #include "ui_mainwindow.h"
#include "fenetre.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi2(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

