#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(buttonForm);
    ui->mdiArea->setActiveSubWindow(cw);
}

MainWindow::~MainWindow()
{
    delete ui;
}
