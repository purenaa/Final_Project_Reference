#include "mainwindow.h"
#include "imagemanagementform.h"
#include "patientcareform.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QList<int> sizes;
//    sizes << 100 << 1000;
//    ui->splitter->setSizes(sizes);

    /* WindowTitle 지정 */
    imageManagementForm = new ImageManagementForm(this);
    imageManagementForm->setWindowTitle(tr("Image Management Page"));
    connect(imageManagementForm, SIGNAL(destroyed()), imageManagementForm, SLOT(deleteLater()));

    patientCareForm = new PatientCareForm(this);
    patientCareForm->setWindowTitle(tr("Patient CareForm Page"));
    connect(patientCareForm, SIGNAL(destroyed()), patientCareForm, SLOT(deleteLater()));

//    gridForm = new GridForm(this);
//    gridForm->setWindowTitle(tr("2 X 2 Grid"));
//    connect(gridForm, SIGNAL(destroyed()), gridForm, SLOT(deleteLater()));

//    fmxForm = new FMXForm(this);
//    connect(fmxForm, SIGNAL(destroyed()), fmxForm, SLOT(deleteLater()));
//    fmxForm->setWindowTitle(tr("14 FMX Layout"));

//    toothGridForm = new ToothGridForm(this);
//    connect(toothGridForm, SIGNAL(destroyed()), toothGridForm, SLOT(deleteLater()));
//    toothGridForm->setWindowTitle(tr("Tooth Grid"));

//    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(gridForm);
//    ui->mdiArea->addSubWindow(fmxForm);
//    ui->mdiArea->addSubWindow(toothGridForm);
//    ui->mdiArea->setActiveSubWindow(cw);


    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(imageManagementForm);
    ui->mdiArea->addSubWindow(patientCareForm);
    ui->mdiArea->setActiveSubWindow(cw);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileLoad()
{
    QFileDialog dialog;
    QString filePath = dialog.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");

    QImage* imageSize = new QImage(filePath);
    QPixmap img = QPixmap::fromImage(*imageSize);
    img = img.scaled(imageSize->width(), imageSize->height());

    QGraphicsScene* scene = new QGraphicsScene;
//    scene->addPixmap(img);
//    ui->graphicsView1->setScene(scene);
//    ui->graphicsView2->setScene(scene);
//    ui->graphicsView3->setScene(scene);
//    ui->graphicsView4->setScene(scene);
}

void MainWindow::zoomIn()
{
//    ui->graphicsView1->scale(1.25,1.25);
}

void MainWindow::zoomOut()
{
//    ui->graphicsView1->scale(0.8, 0.8);
}

void MainWindow::leftRotate()
{
//    ui->graphicsView1->rotate(90);
}

void MainWindow::rightRotate()
{
//    ui->graphicsView1->rotate(-90);
}
