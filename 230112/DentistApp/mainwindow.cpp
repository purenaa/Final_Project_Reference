#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "layout.h"
#include "fmx.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 700 << 70;
    ui->splitter->setSizes(sizes);

    QList<int> sizes2;
    sizes2 << 500 << 130;
    ui->splitter2->setSizes(sizes2);

    QList<int> sizes3;
    sizes3 << 100 << 550;
    ui->splitter3->setSizes(sizes3);

    ui->verticalSpacer->changeSize(20, 25);

    /* WindowTitle 지정 */
    gridLayout = new Layout(this);
    gridLayout->setWindowTitle(tr("2 X 2 Grid"));
    connect(gridLayout, SIGNAL(destroyed()), gridLayout, SLOT(deleteLater()));

    fmx = new FMX(this);
    fmx->setWindowTitle(tr("14 FMX"));
    connect(fmx, SIGNAL(destroyed()), fmx, SLOT(deleteLater()));

    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(gridLayout);
    ui->mdiArea->addSubWindow(fmx);
    ui->mdiArea->setActiveSubWindow(cw);


}

MainWindow::~MainWindow()
{
    delete ui;
}

